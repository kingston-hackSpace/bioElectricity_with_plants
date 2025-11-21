#include <SoftwareSerial.h>
#include "HX711.h"

// Pins for HX711
#define HX_DT 4
#define HX_CLK 5

// Pins for RGB LED (common-anode style, 5V connected to LED)
#define RED_PIN 6
#define GREEN_PIN 9
#define BLUE_PIN 10

// Bluetooth
const uint8_t BT_RX = 2;
const uint8_t BT_TX = 3;
SoftwareSerial BTserial(BT_RX, BT_TX);

HX711 scale;

// Smoothing
float filtered = 0.0;
const float filtAlpha = 0.03; // slow smoothing

// Sampling
const unsigned long sampleInterval = 200; // ms
unsigned long lastSample = 0;

// Baseline
long baseline = 0;
const int baselineSamples = 50;

// Spike / noise filter
const int minConsecutive = 3; // number of consecutive readings to trigger change
int consecutiveCount = 0;
long lastStableData = 0;

///////////////////////////////////////////////////
// SETUP
///////////////////////////////////////////////////
void setup() {
  Serial.begin(115200);
  BTserial.begin(9600);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  scale.begin(HX_DT, HX_CLK);
  scale.set_gain(128);

  // Compute baseline
  long sum = 0;
  for (int i = 0; i < baselineSamples; i++) {
    while (!scale.is_ready()) delay(1);
    sum += scale.read();
    delay(20);
  }
  baseline = sum / baselineSamples;

  Serial.print("Baseline: ");
  Serial.println(baseline);
  BTserial.println("Bluetooth Communication Successful");
}

///////////////////////////////////////////////////
// LOOP
///////////////////////////////////////////////////
void loop() {
  unsigned long now = millis();
  if (now - lastSample >= sampleInterval) {
    lastSample = now;

    while (!scale.is_ready()) delay(1);
    long raw = scale.read();

    // Adjust relative to baseline
    long adjusted = raw - baseline;

    // Smooth the data
    filtered = filtered * (1 - filtAlpha) + adjusted * filtAlpha;
    long plantData = filtered / 500; // scale down

    // Minimum consecutive filter to avoid random jumps
    if (abs(plantData - lastStableData) > 50) { // arbitrary jump threshold
      consecutiveCount++;
      if (consecutiveCount >= minConsecutive) {
        lastStableData = plantData;
        consecutiveCount = 0;
      }
    } else {
      consecutiveCount = 0;
      lastStableData = plantData;
    }

long greenThreshold = 500; // ±100 is considered green
long minNeg = -3000;       // extreme negative
long maxPos = 3000;        // extreme positive

int r, g, b;  // values before anode inversion

if (plantData < -greenThreshold) {
    // Negative: red → yellow → green
    float t  = float(plantData - minNeg) / float(-greenThreshold - minNeg);
    float tAdj = sqrt(t);   // non-linear mapping

    r = int(255 * (1 - tAdj));  // red strong → fades
    g = int(255 * tAdj);        // green increases
    b = 0;                      // no blue

} else if (plantData > greenThreshold) {

    // Positive: green → cyan → blue
    float t  = float(plantData - greenThreshold) / float(maxPos - greenThreshold);
    float tAdj = sqrt(t);

    r = 0;                       // no red
    g = int(255 * (1 - tAdj));   // green strong → fades
    b = int(255 * tAdj);         // blue increases

} else {
    // Around zero → pure green
    r = 0;
    g = 255;
    b = 0;
}

// Convert to COMMON-ANODE output (invert)
int outR = 255 - r;
int outG = 255 - g;
int outB = 255 - b;

analogWrite(RED_PIN,   outR);
analogWrite(GREEN_PIN, outG);
analogWrite(BLUE_PIN,  outB);

    // Output for monitoring
    Serial.print("Plant Data: ");
    Serial.println(lastStableData);

    BTserial.print("Plant Data: ");
    BTserial.println(lastStableData);
  }
}
