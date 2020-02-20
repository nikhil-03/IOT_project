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
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.

#define FIREBASE_HOST "swapnil-61130.firebaseio.com"
#define FIREBASE_AUTH "qmwr2XnhAqIo3GJBrRUJUWgKsSnXpsrPO37Oh6Jl"
#define WIFI_SSID "build"
#define WIFI_PASSWORD "hereyougo"

int soundsensor = 16; // potentiometer wiper (middle terminal) connected to analog pin 3
int LED1=5;
int LED2=4;
bool work1=false;
bool work2=false;
bool hit1=false;
bool hit2=false;
int now=0;
int prev=0;
unsigned long endtime;
unsigned long starttime;
int loopcount;
String soundclap;

void setup() {
  Serial.begin(115200);
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
  pinMode(soundsensor,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  int n = 0;

}


void loop() {
    
  while (digitalRead(soundsensor) == 0){
      now++;
      Serial.println(now);   
  }
  starttime = millis();
  endtime = starttime;
  if (now > 10){
    Serial.println("First Clap");
    hit1=true;
    while ((endtime - starttime) <=1000) // do this loop for up to 1000mS
    {
// code here
      while (digitalRead(soundsensor) == 0){
        now++;
        Serial.println(now);   
      }
      loopcount = loopcount+1;
      endtime = millis();
    }
    if (now > 25){
      Serial.println("Second Clap");
      hit2=true;
    }
    now = 0;
    if (hit1==true &hit2==true)
    {
      if (work2==false)
      {work2=true;
      digitalWrite(LED2,HIGH);
      Firebase.setString("Second Clap","ON");
      hit1=false;
      hit2=false;
      }
      else{
        work2=false;
              digitalWrite(LED2,LOW);
              Firebase.setString("Second Clap","OFF");

      hit1=false;
      hit2=false;
        }
      }
    if (hit1==true & hit2==false)
    {
        if (work1==false)
      {work1=true;
            digitalWrite(LED1,HIGH);
            Firebase.setString("First Clap","ON");

      hit1=false;
      hit2=false;
      }
      else{
        work1=false;
              digitalWrite(LED1,LOW);
              Firebase.setString("First Clap","OFF");

      hit1=false;
      hit2=false;
        }
      }
  
 // Serial.print(loopcount,DEC);
  }
  
  

}
