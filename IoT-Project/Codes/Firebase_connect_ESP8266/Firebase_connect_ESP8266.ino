//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <Wire.h>
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
// Adafruit_ADS1015 ads;     /* Use thi for the 12-bit version */
// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "swapnil-61130.firebaseio.com"
#define FIREBASE_AUTH "qmwr2XnhAqIo3GJBrRUJUWgKsSnXpsrPO37Oh6Jl"
#define WIFI_SSID "build"
#define WIFI_PASSWORD "hereyougo"

void setup() {
  Serial.begin(115200);
  Wire.begin(D2,D1);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;

void loop() {
  // set value
    int16_t adc0, adc1, adc2, adc3;
  int  temp = ads.readADC_SingleEnded(0);
  int  sound = ads.readADC_SingleEnded(1);
  int  smoke = ads.readADC_SingleEnded(2);
  int analogValue = temp;
  float millivolts = (analogValue/1024.0) * 3300; //3300 is the voltage provided by NodeMCU
  float celsius = millivolts/10;
  String SOUND = String(sound);
  String TEMP = String(celsius);
  String SMOKE = String(smoke);

  
  
  
  
  
  Firebase.setFloat("temperature",celsius);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  // get value 
  Serial.print("Temperature: ");
  Serial.println(Firebase.getFloat("temperature"));
  delay(1000);


  
  
  
  
  
  
    Firebase.setInt("smoke",smoke);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  // get value 
  Serial.print("Smoke: ");
  Serial.println(Firebase.getInt("smoke"));
  delay(1000);
  
  
  
  
  




    Firebase.setInt("sound",sound);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  // get value 
  Serial.print("Sound: ");
  Serial.println(Firebase.getInt("sound"));
  delay(1000);
  








  
  
//  
//  // set string value
//  Firebase.setString("message", "hello world");
//  // handle error
//  if (Firebase.failed()) {
//      Serial.print("setting /message failed:");
//      Serial.println(Firebase.error());  
//      return;
//  }
//  delay(1000);
//  









//  Firebase.setBool("truth", false);
//  // handle error
//  if (Firebase.failed()) {
//      Serial.print("setting /truth failed:");
//      Serial.println(Firebase.error());  
//      return;
//  }
//  delay(1000);






  // append a new value to /logs
  String name = Firebase.pushInt("logs", n++);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /logs/");
  Serial.println(name);
  delay(1000);
}
