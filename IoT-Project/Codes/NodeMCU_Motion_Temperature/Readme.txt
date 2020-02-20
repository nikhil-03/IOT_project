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
1. The digital output from PIR module to the PIN D0 of NodeMCU.
2. Common Ground the PIR module and the NodeMCU.
3. Supply power from the 3V supply to the PIR module.
4. Common Ground the Relay module and the NodeMCU.
5. Supply power from the 3V supply to the Relay module.
6. Connect the relay pin to the PIN D7 of the NodeMCU.
7. Also connect the LED to PIN 13 of the NodeMCU.
8. Common the ground and Vcc of LM35 Temperature Sensor and NodeMCU.
9. Connect the Analog pin A0 of LM35 to the NodeMCU.
