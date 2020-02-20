/*
Created by 
Swapnil Modani (swapnil.modani@gmail.com)
Randa Shady
Jenifer Rodgriguez Delgado

What the code does:
1. Detects motion using a simple PIR Motion sensor.
2. Depending on its status, it drives a relay.
3. Indicated the status of motion using an LED.
4. Senses the temperature and displays in degrees celsius.

Circuit Connections:
1. The digital output from PIR module to the PIN D0 of NodeMCU
2. Common Ground the PIR module and the NodeMCU
3. Supply power from the 3V supply to the PIR module
4. Common Ground the Relay module and the NodeMCU
5. Supply power from the 3V supply to the Relay module
6. Connect the relay pin to the PIN D7 of the NodeMCU
7. Also connect the LED to PIN 13 of the NodeMCU
‭8‬. Common the ground and Vcc of LM35 Temperature Sensor and NodeMCU.
‭9‬. Connect the Analog pin A0 of LM35 to the NodeMCU

*/



int outputpin= A0; // Pin for the LM35
int sensor_pin = 16; // Initialized the pin for motion sensor
int relay_pin = 13; // Pin to relay pin
int output = 0;// Variable to store the output state of motion sensor
int preoutput;
void setup(){
  Serial.begin(9600); //Setting the baud rate
  pinMode(sensor_pin, INPUT);   // Declared motion sensor pin as Input
  pinMode(relay_pin, OUTPUT);   // Declared relay module pin as Output pin
  pinMode(5, OUTPUT);   // Declared relay module pin as Output pin
  digitalWrite(relay_pin, HIGH);  // Make the relay module initial state as low, Relay works opposite
}
void loop(){
  preoutput = output;
  output = digitalRead(sensor_pin);
  // If output is High
   if(output == 0 && preoutput == 1){
    delay(7000);
  }
  else if(output == 1){
    digitalWrite(relay_pin, LOW);
    digitalWrite(5, HIGH);
  }
  // If output is LOW
  else if(output == 0){
    digitalWrite(relay_pin, HIGH);
    digitalWrite(5, LOW);
  }

  // The next part of the code involves calculation of the temperature from LM35
  int analogValue = analogRead(outputpin);
  float millivolts = (analogValue/1024.0) * 3300; //3300 is the voltage provided by NodeMCU
  float celsius = millivolts/10;
  // The following part just deals with printing the final sensor readings
  Serial.print("in DegreeC = ");
  Serial.println(celsius);
  if(output == 1){
    Serial.println("Motion Detected");
  }
  else if(output == 0){
    Serial.println("No Motion");
  }
}
