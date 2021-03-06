/*
Created by 
Swapnil Modani (swapnil.modani@gmail.com)

What the code does:
1. Connects the NodeMCU to tthe internet.
2. Displays the IP adress it is running on.

Circuit Connections:
1. Connect the NodeMcu to the ESP8266 NodeMcu using a USB type B micro
2. Set the Board to NodeMCU 1.0 (ESP-12E Module)
3. Upload baud rate to 115200

Note:
The NodeMcu can only connect to those Wifi's that have SSID and password.
Not to those that need additional username and password to connect to the internet.

*/

#include <ESP8266WiFi.h>
const char* ssid     = "build";
const char* password = "hereyougo"; 
int wifiStatus;
void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println();
  Serial.print("Your are connecting to;");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
      
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
  }   
     
void loop() {
  wifiStatus = WiFi.status();
  if(wifiStatus == WL_CONNECTED){
    Serial.println("");
    Serial.println("Your ESP is connected!");  
    Serial.println("Your IP address is: ");
    Serial.println(WiFi.localIP());  
  }
  else {
    Serial.println("");
    Serial.println("WiFi not connected");
  }
  delay(1000); // check for connection every once a second
}
