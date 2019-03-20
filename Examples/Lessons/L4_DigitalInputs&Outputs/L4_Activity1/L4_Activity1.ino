/*
  CTC GO! CORE MODULE 
  LESSON 04 - Digital Inputs & Outputs

  This sketch is written to accompany Activity 1 in Lesson 04 of the CTC GO! core module
*/

// pin where the button is connected
int button = 2;

// to save the button state
int button_state = 0; 

void setup() 
{
  // digital pin LED_BUILTIN as output
  pinMode(LED_BUILTIN, OUTPUT);
  // digital pin button_pin as input
  pinMode(button_pin,INPUT);
}

void loop() 
{
  // saving the button state in a variable
  button_state = digitalRead(button_pin);

  // changing the LED state
  digitalWrite(LED_BUILTIN, button_state);   
}
