
/*
  CTC GO! CORE MODULE 
  LESSON 08 - Analog Outputs

  This sketch is written to accompany Activity 2 in Lesson 08 of the CTC GO! core module
*/
 
  //pin connections
  int buttonC = 13;
  int buttonB = 12;
  int buttonA = 11;
  int piezo = 8;
  
  // notes frequency
  int C_note = 262;
  int B_note = 493;
  int A_note = 440;
  
  // to save the button states
  int buttCvalue = 0;
  int buttBvalue = 0;
  int buttAvalue = 0;
  
  void setup()
  {
    pinMode(buttonC, INPUT);
    pinMode(buttonB, INPUT);
    pinMode(buttonA, INPUT);
    pinMode(piezo, OUTPUT);
  }
  
  void loop()
  {
    //reading the buttons states
    buttCvalue = digitalRead(buttonC);
    buttBvalue = digitalRead(buttonB);
    buttAvalue = digitalRead(buttonA);
  
    if (buttCvalue == HIGH)
    {
      //if buttonC pressed, play a C note
      tone (piezo, C_note); 
    }
    else if (buttBvalue == HIGH)
    {
      //if buttonB pressed, play a B note
      tone (piezo, B_note); 
    }
    else if (buttAvalue == HIGH)
    {
      //if buttonA pressed, play a A note
      tone (piezo, A_note); 
    }
    else
    {
      noTone(piezo);    //stop playing sound
    }
  }
