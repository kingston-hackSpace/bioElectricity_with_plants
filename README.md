# bioElectricity_with_plants (Work-In-Progress)

In this tutorial, we will attempt to monitor the internal electrical activity in a plant. 
The accuracy of the findings, and forms of data visualization are still in work-in-progress. 

Plants naturally move ions (charged particles) through their tissues, and this creates small voltage changes across their cell membranes. These signals tend to shift gradually over time, producing slow drifts with the occasional spike. In this tutorial, our aim is to sense and observe this naturally occurring electrical activity.

***note:** Plant electrical signals are “slow”, meaning they usually change over the course of seconds or minutes rather than instantly.*

***note:** Some plants are more challenging to measure than others. Leaves that are thick, waxy, shiny, very smooth, or very hairy may reduce conductivity or make it difficult for electrodes to adhere properly. Plants with softer, matte, slightly moist, or gently textured leaves—such as pothos, peace lilies, or philodendrons—tend to provide better contact.*

***note:** Environmental electrical noise (from mains power, static, nearby electronics, or loose wires) can affect the readings. More information is provided below.*

---

AMPLIFING PLANT ELECTRICAL SIGNALS
- 

Plant electrical activity is small and subtle, usually in the microvolt (µV) to low-millivolt (mV) range. To sense and observe it, we need a voltage-amplifying device that also performs analogue-to-digital conversion (ADC). In other words, this device boosts the plant’s tiny signals and converts them into numerical values that the Arduino can read.

For this experiment, we will use the HX711 Load-Cell Amplifier.  



HX711 LOAD-CELL AMPLIFIER
-

The HX711 load-cell amplifier is an cheap, high-resolution 24-bit ADC with selectable gain. It is designed to measure very small millivolt-level signals using high-gain differential amplification. Although it was not created specifically for biological measurements, it is a practical choice for this experiment because it offers high sensitivity and is easy to interface with an Arduino. Its sensitivity, however, also means it can easily pick up external electrical noise, which may interfere with the plant readings. Furtheer in this tutorial, we will learn how to reduce environmental electrical noise. 


HOW IT WORKS:
- The HX711 has two input terminals: A+ and A-. The chip measures the voltage difference between these two points (a differential input).

- It supports different gain levels: ×32, ×64, and ×128, allowing it to amplify very small signals.


ELECTRICAL NOISE
-

Our surroundings are full of electrical activity. Mains wiring, chargers, electronic devices, fluorescent lights, Wi-Fi routers, and even our own bodies all generate electric fields. An electric field is simply the region around a charged object where it can influence other charges.

Because the HX711 is designed to detect extremely small voltages, it cannot easily tell the difference between the plant’s bio-electrical signals and electrical noise from the environment. As a result, some noise will inevitably appear in our readings.

In this project, we try to reduce unwanted noise through both hardware and software. However, completely eliminating environmental interference is very difficult, and in practice we aim for readings that are representative rather than perfectly “pure” plant signals.



REDUCING NOISE: TIPS
-

- Use a power-bank to power your Arduino Board. Once you upload the code to the Arduino Board, avoid keeping the board connected to the computer as it fill add electromacnetic field interference to your sensing device. To be able to keep monitoring the data, we will send the data from the Arduino to an Android Smartphone via Bluetooth.  

- Short - shield wires help to reduce electromagnetic noise. 

- At least 2 wire connections will be needed. One of them should go to the soil of the plant to reduce environmental soil from the surrounding electrical fields. because the soil is large and conductive, it can stabilize our readings. 

- Moistured soil (not dumped) helps conduct electricity

- We treat the HX711 output as a high-resolution raw signal (counts), then baseline and filter it in software to produce the representative values used for visualisation.


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



