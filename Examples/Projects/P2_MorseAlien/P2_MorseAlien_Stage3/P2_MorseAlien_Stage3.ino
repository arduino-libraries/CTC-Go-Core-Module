/*
  CTC GO! CORE MODULE 
  PROJECT 2 - MORSE ALIEN

  This sketch is written to accompany Stage 3 in MORSE ALIEN  of the CTC GO! core module
*/

int distanceSensor = A0;
int blueLED = 13;
int breakButton = 10;
int recordButton = 12;
int playButton = 11;
int piezo = 8;

int prevBreakButtonState = LOW;
int prevRecordButtonState = LOW;
int prevPlayButtonState = LOW;

//STEP 3; Initialise the array for storing the symbols and other variables that will be used to store and retrieve the morse coded message
int mySymbols[50];
int symbolIndex = 0;
int symbolLength = 300;
int currentSymbol = 0;
int sequencePlayed = false;

//STEP 3; Initialise the values & tone frequencies for DOT(.) and DASH (__)
int DASH = 2;
int DOT = 1;
int freq_DASH = 1500 ;
int freq_DOT = 1000 ;

void setup()
{
   pinMode(blueLED,OUTPUT);
   pinMode(breakButton,INPUT);
   pinMode(recordButton,INPUT);
   pinMode(playButton,INPUT);
   pinMode(piezo, OUTPUT);

   Serial.begin(9600);
}

void loop()
{    
   int distanceSensorValue = analogRead(distanceSensor);
   int actualDistanceMM = map(distanceSensorValue,0,1023,0,3000);

   if (distanceSensorValue < 200)
   {
     digitalWrite(blueLED,HIGH);
     //STEP 3;
     currentSymbol = DASH;
   }
   else
   {
     digitalWrite(blueLED,LOW);
     //STEP 3;
     currentSymbol = DOT;
   }
   
   if (digitalRead(recordButton) == HIGH) 
   { 
     if (prevRecordButtonState == LOW) 
    {  
      Serial.print("ADDING SYMBOL");
      //STEP 3; Print the symbol index to which the current symbol(DOT or DASH) is added 
      Serial.print(symbolIndex);
      Serial.print(" ");
      Serial.println(currentSymbol);
      digitalWrite(blueLED, LOW);
      delay(symbolLength);

      //STEP 3; If the the currentSymbol is a DOT then play a specific tone 
      if (currentSymbol == DOT) 
      {
         digitalWrite(blueLED, HIGH);
         tone(piezo, freq_DOT);
         delay(symbolLength);
         digitalWrite(blueLED, LOW);
      }
      //STEP 3; If the the currentSymbol is a DASH then play a different tone as compared to DASH 
      else if (currentSymbol == DASH) 
      {
         digitalWrite(blueLED, HIGH);
         tone(piezo, freq_DASH );
         delay(symbolLength * 3);
         digitalWrite(blueLED, LOW);
       }
    }
    prevRecordButtonState = HIGH;  

    /*
      Add the symbol to the array
    */
    //STEP 3; Check if the sequence has played already, start recording from scratch
    if (sequencePlayed == true) 
    {
      sequencePlayed = false;
      symbolIndex = 0;
    }
    mySymbols[symbolIndex] = currentSymbol;
    symbolIndex = symbolIndex + 1;    
   }
   else
   {
    prevRecordButtonState = LOW;    
   }

   if (digitalRead(breakButton) == HIGH)
   {    
     if (prevBreakButtonState == LOW) 
     {
      Serial.println("ADDING BREAK");
      tone(piezo, 1000);
     }
     prevBreakButtonState = HIGH;  
   }
   else
   {
    prevBreakButtonState = LOW;  
   }

   if (digitalRead(playButton) == HIGH)
   {    
     if (prevPlayButtonState == LOW) 
      {
        Serial.println("START PLAYING SYMBOLS");
        tone(piezo, 1000);
      }
      prevPlayButtonState = HIGH; 
   } 
   else
   {
    prevPlayButtonState = LOW;  
   }
}
