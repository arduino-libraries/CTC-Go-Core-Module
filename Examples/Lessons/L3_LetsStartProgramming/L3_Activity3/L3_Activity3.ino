/*
  CTC GO! CORE MODULE 
  LESSON 03 - Let's Start Programming 

  This sketch is written to accompany Activity 3 in Lesson 03 of the CTC GO! core module

*/


int redLED = 13;
int yellowLED = 12;

void setup() 
{
  // Setting up the pins as OUTPUTS.
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
}

void loop() 
{
  
  digitalWrite(redLED, HIGH);    // turn the LEDs on (HIGH is the voltage level)
  digitalWrite(yellowLED, HIGH); 
  delay(1000);                   // wait for a second
  digitalWrite(redLED, LOW);     // turn the LEDs off by making the voltage LOW
  digitalWrite(yellowLED, LOW);
  delay(1000);                   // wait for a second
} 
