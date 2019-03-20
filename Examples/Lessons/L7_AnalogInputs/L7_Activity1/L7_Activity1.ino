/*
  CTC GO! CORE MODULE 
  LESSON 07 - Analog Inputs

  This sketch is written to accompany Activity 1 in Lesson 07 of the CTC GO! core module
*/

int pot = A0;
int val = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(pot);
  Serial.print("Value read: ");
  Serial.println(val);
}
