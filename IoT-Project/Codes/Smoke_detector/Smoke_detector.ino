/*******
 Created by
 Randa Shady (rshady@hawk.iit.edu)
 
What the code does:
1. Set the smoke sensor's threshold
2. Define the pins I/O
3. Get the sensor's reading and compare it to the threshold, if you exceed it turn on a buzzer and print smoke detected.

Circuit connections:
1. connect the smoke sensor and the buzzer if needed to the ESP8266
2. Set baud rate to 9600 and upload the code.

*******/
int buzzer = 10;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 400;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    tone(buzzer, 1000, 200);
    Serial.println("smoke detected!");
  }
  else
  {
    noTone(buzzer);
  }
  delay(100);
}
