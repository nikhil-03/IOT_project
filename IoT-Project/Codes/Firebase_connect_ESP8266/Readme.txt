Created by 
Swapnil Modani (swapnil.modani@gmail.com)

What the code does:
1. Connects the NodeMCU to the internet.
2. Displays the IP adress it is running on.
3. Connects the NodeMCU to the Google Firebase Platform.
4. Allows us to send basic strings, numbers and boolean data from the NodeMCU to the Firebase.
5. The send information may be directly viewed in the real time database in the Google Firebase.
6. The data send to the Cloud can be taken off or removed from the live database.

Circuit Connections:
1. Connect the NodeMcu to the ESP8266 NodeMcu using a USB type B micro
2. Set the Board to NodeMCU 1.0 (ESP-12E Module)
3. Set upload baud rate to 115200

Note:
1. The NodeMcu can only connect to those Wifi's that have SSID and password.
   Not to those that need additional username and password to connect to the internet.
2. This is just a demo code to see if the NodeMCU can successfully send data to the Firebase.
3. For actual process to connect to the cloud follow the steps in the "Process.txt".