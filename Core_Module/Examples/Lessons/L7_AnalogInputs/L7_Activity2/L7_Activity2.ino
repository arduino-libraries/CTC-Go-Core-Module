/*
  CTC GO! CORE MODULE 
  LESSON 07 - Analog Inputs

  This sketch is written to accompany Activity 2 in Lesson 07 of the CTC GO! core module
*/


int lightSensor = A0;  //pin where the input is connected
int LED = 13;          //pin where the LED is connected
int val = 0;           //to store the value read 
int trigger = 250;     //value to turn ON/OFF the LED 

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //savethe read on a variable and print it
  val = analogRead(lightSensor);
  Serial.print("Value read: ");
  Serial.println(val);

  if (val < trigger)    //if there is low light, turn on the LED
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW); //if there is high light, turn off the LED
  }
  delay(500);
}
