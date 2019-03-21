/*
  CTC GO! CORE MODULE 
  LESSON 05 - Showing messages on PC

  This sketch is written to accompany Activity 2 in Lesson 05 of the CTC GO! core module
*/

  // storing the pin where the button is connected in a variable
  int button = 2;
  
  // initialize a variable to store the state of the button
  int button_state = 0;
  // initialize a variable for the counter
  int counter = 0;
  
  void setup()
  {
    // initialize digital serial communication at 9600baud.
    Serial.begin(9600);
    // initialize digital pin button_pin as input
    pinMode(button, INPUT);
  }
  
  void loop()
  {
    button_state = digitalRead(button); //saving the state of thebutton
    if (button_state == HIGH)
    {
      counter += 1;                     //icrease the value of counter one unit
      delay(500);
      Serial.print("counter value = "); //print counters value
      Serial.println(counter);
      if (counter == 100)    // reset the value of counter if it arrives to 100
      {
        counter = 0;
      }
    }
  }
