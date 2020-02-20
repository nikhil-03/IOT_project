Created by 
Swapnil Modani (swapnil.modani@gmail.com)

What the code does:
1. Connects the NodeMCU to the internet.
2. Displays the IP adress it is running on.
3. Controls an LED depending if the Motion is detected or not.

Circuit Connections:
1. Connect the NodeMcu to the ESP8266 NodeMcu using a USB type B micro
2. Set the Board to NodeMCU 1.0 (ESP-12E Module)
3. Set upload baud rate to 115200
4. Common the ground and the Vcc of the Sensor and the NodeMCU module.
5. Connect the digital out pin of the PIR motion sensor to the NodeMCU to the D7 pin.
6. Also connect the +ve terminal of the LED to the D6 pin and the gound of the LED to the ground of the NodeMCU.

Note:
1. The NodeMcu can only connect to those Wifi's that have SSID and password.
   Not to those that need additional username and password to connect to the internet.
2. This is not the most optimised code to implement, the other code is written by Swapnil and shared to all.
3. This was a just to ensure the functioning of the NodeMCU with the sensor.