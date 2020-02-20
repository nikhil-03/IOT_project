int soundsensor = 12; // potentiometer wiper (middle terminal) connected to analog pin 3
int LED1=16;
int LED2=14;
bool work1=false;
bool work2=false;
bool hit1=false;
bool hit2=false;
int now=0;
int prev=0;
unsigned long endtime;
unsigned long starttime;
int loopcount;

void setup() {
  
  Serial.begin(9600);           //  setup serial
  pinMode(soundsensor,INPUT);
  pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);

  digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);

//  now=millis();
}

void loop() {
//  int readS=digitalRead(soundsensor);
  
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
    if (now > 30){
      Serial.println("Second Clap");
      hit2=true;
    }
    now = 0;
    if (hit1==true &hit2==true)
    {
      if (work2==false)
      {work2=true;
      digitalWrite(LED2,HIGH);
      hit1=false;
      hit2=false;
      }
      else{
        work2=false;
              digitalWrite(LED2,LOW);

      hit1=false;
      hit2=false;
        }
      }
    if (hit1==true &hit2==false)
    {
        if (work1==false)
      {work1=true;
            digitalWrite(LED1,HIGH);

      hit1=false;
      hit2=false;
      }
      else{
        work1=false;
              digitalWrite(LED1,LOW);

      hit1=false;
      hit2=false;
        }
      }
  
  Serial.print(loopcount,DEC);
  }
  
}
