# IoT-Project
NIKHIL PRAKASH
BIT MESRA
 User programmable Home Automation

Project Overview 
	Our target is to build an IoT-based user programmable home automation system. Temperature, motion, and sound sensors, smoke detector, and a camera are to be controlled with multiple ESP8266-Nodemcu units and a Raspberry Pi 3B+. The data collected by the sensors is to be sent to a server (or Cloud), to become accessible for the user from anywhere in the world. The users are given the control to turn on/off their home-devices based on the readings from the sensors. The user will decide how the devices will operate based on their preferences. For example, if the temperature is more than X (degrees Celsius) turn on the AC, etc.
 
Necessary Materials 
•	Temperature sensors.
•	Motion sensors.
•	Smoke detectors.
•	Sound sensors.
•	Camera.
•	Xbee units.
•	Arduino Nano.
•	Raspberry Pi 3B+.
•	ESP8266 Nodemcu.
•	USB type B micro cable.
•	12V DC adapter.
•	Breadboards.
•	Connecting Jumpers.
•	PCBs.
•	Soldering station.
•	Relays.

Research Objectives 
o	Architecture and software interface of microcontrollers.
o	Mechanism of sensors and integration with microcontrollers.
o	User programmability on IoT devices.
o	Integration between the cloud and hardware.
o	Cybersecurity and cloud computing.

Weekly Roadmap  
•	June 3rd through June 7th 
1.	Sensors integration with the ESP8266:  
We are working with 4 major sensors, i.e. PIR motion sensor, temperature sensor, sound sensor and the smoke sensor. Each one needs to be integrated with the microcontroller (in this case ESP8266 Nodemcu). 
The code (Arduino) for each sensor needs to be written and checked with the respective sensor separately.
Once all sensor codes are written, we will put them together and test all sensors simultaneously.

2.	Local Host Setup:
Before, we begin moving towards cloud communication, we want to implement the system on a localhost (to ensure it is efficiently functioning.)

3.	Cloud communication setup:
Then we will be sending the data from the sensors to the Nodemcu. From here, we will send the data into a cloud. We will test different clouds until we find the most convenient one. We may use Google Firebase, Apache Cloud, IoT Core Cloud, etc. This will involve a two-way communication between the cloud and the Nodemcu so that on-board relays (connected to the ESP8266) can be controlled via the cloud.
Cloud connection need to be tested until we ensure that it works correctly before moving to other steps.

•	June 10th through June 14th 
1.	Cloud computation:
Once we have the data sent to the cloud, we can access the data and process it to the desired parameters. This is a field that involves JavaScript or another programming language. The concept of IFTT (If this then that) will be used here to make the user experience as friendly as possible.

2.	Server processing:
We will convert one of the systems into a server where all the data recorded by the sensors at the cloud interface is dumped into. We may process this data received and send it back to the cloud for further process controls.

•	June 17th through June 21st 
User programmability: We want to focus our research project on finding the best way to offer the user the readings of the current sensor values and then implement a simple IFTT application to control appliances based on the readings. We believe that this will be one of the most challenging parts of our project and that will require the greatest time and care.

•	June 24th through June 28th 
User programmability: finish any incomplete parts from previous week.
User Interface: During this week we will deal with making the User Interface more accessible and people-friendly. This will allow our project to be more appealing to use and interact with.

•	July 1st through July 5th
1.	Exoskeleton: We will be working on pre-made CAD models and try to find an appropriate structure to house the electronics within.

2.	Debugging: Try to simplify the codes, streamline the process and try removing as many bugs as possible. Make this a more presentable and a finished product.

Stopping Points 
	If you can’t complete your overall objective, where would you be able to stop? 
If the cloud services don’t respond effectively or ideally then we would take a step back on perfecting how to control the data only locally. The data from the sensors would be viewed from anywhere in the world, however, the user would not be able to manipulate the behavior of the devices globally, but locally.

