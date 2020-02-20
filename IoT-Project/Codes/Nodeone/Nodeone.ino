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

int outputpin= A0; // temp sensor

int sensor_pin = 16; // motion sensor
int relay_pin = 13;  
int output = 0;// state of motion
int preoutput;
String txt;

void setup() {
  Serial.begin(115200);
  Wire.begin(D2,D1);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);

//  pinMode(smokeA0, INPUT);
  pinMode(sensor_pin, INPUT);   
  pinMode(relay_pin, OUTPUT);  
  //pinMode(5, OUTPUT);    
  digitalWrite(relay_pin, HIGH); 
  
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;

void loop() {

  int temp = analogRead(outputpin);
  float mV = (temp/1024.0) * 3300; 
  float celsius = mV/10;
  preoutput = output;
  Serial.print("in DegreeC = ");
  Serial.println(celsius);

  //--------------------TEMP-------------

      
  String TEMP = String(celsius);
  
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

//--------------------MOTION-------------

  preoutput = output;
  output = digitalRead(sensor_pin);
  if(output == 0 && preoutput == 1){
    delay(7000);
  }
  else if(output == 1){
    digitalWrite(relay_pin, LOW);
    txt="Yes";
    Serial.println("Motion Detected");
    
  }
  else if(output == 0){
    digitalWrite(relay_pin, HIGH);
    txt="No";
    Serial.println("No motion");
  } 
  Serial.println(output);
  
    String MOTION = String(txt);


  
    Firebase.setString("Motion",txt);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  // get value 
  Serial.print("Motion: ");
  Serial.println(Firebase.getString("Motion"));
  delay(1000);
  
  //String name = Firebase.pushInt("logs", n++);
  // handle error
//  if (Firebase.failed()) {
//      Serial.print("pushing /logs failed:");
//      Serial.println(Firebase.error());  
//      return;
//  }
//  Serial.print("pushed: /logs/");
//  Serial.println(name);
//  delay(1000);
}
