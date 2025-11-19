# bioElectricity_with_plants (Work-In-Progress)

In this tutorial, we will attempt to monitor the internal electrical activity in a plant.

Plants naturally move ions (charged particles) through their tissues, and this creates small voltage changes across their cell membranes. These signals tend to shift gradually over time, producing slow drifts with the occasional spike. 

*note*: “Slow electrical signals” in this context means that plant electrical responses usually unfold over seconds or minutes rather than instantly.

*note:* Reading bio-electrical activity could be more difficult in some plants more than others. Thick, waxy, shiny, very smooth, or very hairy leaves can reduce conductivity or prevent good electrode adhesion.

*note:* Environmental electrical noise (from mains power, static, nearby electronics, or loose wires) can affect the readings. More information is provided below.

---

AMPLIFING PLANT ELECTRICAL SIGNALS
- 

Plant electrical activity may go between micro and milliVolts, which is a very small signal. We need an amplier device that can sense those signals and feed the arduino with a representative data. 

For this experiment, we will use the HX711 Load Cell Amplifier.  

HX711 LOAD CELL AMPLIFIER
-
This device is designed to sense millivolts and add high gain differential amplification. This makes it very sensitive, and it can pick external electrical influences that may interfere with our plant readings. 

The HX711 has 2 connections points: A+ and A-. The device measures the voltage between this two points. 

Usual device gain: x128, x64, x32.

*note*: The HX711 -designed to pick up tiny voltages -  won't distinguish between the plant's electricl signals and the environment's. Unfortunatelly, there will be electrical noise in our readings, so we need to try to reduce it in hardware and software to get reliable plpant data. Please keep in mind that cancelling external noise for pure plant activity signals can be very difficult. 

ELECTROMAGNETIC FIELDS
- 
Every charged object -a wire, a wall socket, our  bodies, even the air- creates electrical fields. 

An electrical field is the space around something where its charge can influence other charges. 


REDUCING NOISE: TIPS
-
Our HX711 Amplifier is trying to sense very small electrical signals, for this reason, we need to reduce any electrical noise that might interfere with our plant electrical sensing. 

- Use a power bank to power your Arduino Board. Once you upload the code to the Arduino Board, avoid keeping the board connected to the computer as it fill add electromacnetic field interference to your sensing device. To be able to keep monitoring the data, we will send the data from the Arduino to an Android Smartphone via Bluetooth.  

- Short - shield wires help to reduce electromagnetic noise. 

- At least 2 wire connections will be needed. One of them should go to the soil of the plant to reduce environmental soil from the surrounding electrical fields. because the soil is large and conductive, it can stabilize our readings. 

- Moistured soil (not dumped) helps conduct electricity
- 

TUTORIALS
- 
- RGB LED (common anode)
- HC06 Bluetooth Module
- HX711 Cell Load Amplifier

HARDWARE
-
- Arduino UNO
- HX711 Load Cell Amplifier Module
- HC06 Bluetooth Module
- RGB LED (common anode)
- 220ohms resistor (x3)
- 2.2K resistor
- 1K resistor
- 5V Power Bank
- Android Smartphone
  
ELECTRODES
- 

The plants outer surface - its epidermis or "skin"- has cell membranes that hold electrical activity. A plant, as us - humans- present an "electrically active outer layer". For this reason, our electrodes can be stick to the plant leaves. Avoid perforating through them, as you can cause them stress. 

For good contact points use slightly damp connections such as wet-get electrodes. You can also make yourown electrodes using stainless steel, which has good conductivity, and avoids metal corrossion. Don't use copper (corrosive).

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

Understanding Data Readings
-
What kind of data do you get when:
- electrodes are lose (no plant connection)
- electrodes are in touch with a human hand
- electrodes are connected to two different leaves
- one electrode is connected to a leave, the other one to the soil
- move the leaves or soil using a wood stick (mechanical stimulation)



