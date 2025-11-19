# bioElectricity_with_plants (Work-In-Progress)

In this tutorial, we will monitor the internal electrical activity in a plant.

*note:* Some plants may xx

*note:* Electrical noise. 

---

ABOUT BIO-ELECTRICITY
---

Plants produce slow drifts of electrical activity with occassional spikes. By slow, we mean that plants do not present "fast" electrical reactions. 

AMPLIFING PLANT ELECTRICAL SIGNALS
- 

Plant electrical activity may go between micro and milliVolts, which is a very small signal. We need an amplier device that can sense those signals and feed the arduino with a representative data. 
For this experiment, we will use the HX711 Load Cell Amplifier.  

HX711 LOAD CELL AMPLIFIER
-
This device is designed to sense millivolts and add high gain differential amplification.



REDUCING NOISE: TIPS
-

- Short - shield wires help to reduce electromagnetic noise. 

- At least 2 wire connections will be needed. One of them should go to the soil of the plant to reduce electromagnectic noise.

- Moistured soil (not dumped) helps conduct electricity
- 

HARDWARE
-
- Arduino UNO
- HX711 Load Cell Amplifier
- HC06 Bluetooth Module
- RGB LED (common anode)
- 220ohms resistor (x3)
- 2.2K resistor
- 1K resistor
- 5V Power Bank
  
ELECTRODES
- 
- Stainless steel is recommended for good conductivity, and to avoid metal corrossion

WIRING
-

AMPLIFIER 5V --- ARDUINO 5V
AMPLIFIER GND --- ARDUINO GND
AMPLIFIER DATA --- ARDUINO PIN 4
AMPLIFIER CLK --- ARDUINO PIN 5
AMPLIFIER (+) --- PLANT LEAVE
AMPLIFIER (-) --- PLANT SOIL

CODE
-
Library: HX711

