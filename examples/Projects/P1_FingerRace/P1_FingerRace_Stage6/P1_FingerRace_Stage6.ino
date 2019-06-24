/*
  CTC GO! - CORE MODULE 
  PROJECT 1 - Finger Race

  This sketch is written to accompany Stage 6 in Finger Race of the CTC GO! Core Module
*/

int greenLED_P1 = 13;
int blueLED_P1 =  12;

int blueLED_P2 =  11;
int greenLED_P2 =  9;

int button_P1 = 6;
int button_P2 = 7;

int gameState = 0;
int previousButtonState_P1 = 0;
int previousButtonState_P2 = 0;
int player_1 = 0;
int player_2 = 0;

void setup()
{
  pinMode(greenLED_P1, OUTPUT);
  pinMode(blueLED_P1, OUTPUT);
  pinMode(blueLED_P2, OUTPUT);
  pinMode(greenLED_P2, OUTPUT);

  pinMode(button_P1, INPUT);
  pinMode(button_P2, INPUT);
}

void loop()
{
  if (gameState == 0)
  {
    digitalWrite(greenLED_P1, HIGH);
    digitalWrite(blueLED_P1, HIGH);
    digitalWrite(blueLED_P2, HIGH);
    digitalWrite(greenLED_P2, HIGH);
    delay(200);
    digitalWrite(greenLED_P1, LOW);
    digitalWrite(blueLED_P1, LOW);
    digitalWrite(blueLED_P2, LOW);
    digitalWrite(greenLED_P2, LOW);
    delay(200);
  }
  else if (gameState == 1) {
    digitalWrite(greenLED_P1, _____);
    digitalWrite(blueLED_P1,  _____);
    digitalWrite(blueLED_P2,  _____);
    digitalWrite(greenLED_P2, _____);
    delay( _____);
    digitalWrite(greenLED_P1, _____);
    digitalWrite(blueLED_P1,  _____);
    digitalWrite(blueLED_P2,  _____);
    digitalWrite(greenLED_P2, _____);
    delay( _____);
    digitalWrite(greenLED_P1, _____);
    digitalWrite(greenLED_P2, _____);
    delay( _____);
    digitalWrite(greenLED_P1, _____);
    digitalWrite(greenLED_P2, _____);
    delay( _____);
    digitalWrite(blueLED_P1,  _____);
    digitalWrite(blueLED_P2,  _____);
    delay( _____);
    digitalWrite(blueLED_P1, LOW);
    digitalWrite(blueLED_P2, LOW);

    player_1 =  _____;
    player_2 =  _____;
    gameState =  _____;
  }
  else if (gameState == 2)
  {
   
    if (player_1 > player_2)
    {
      digitalWrite(blueLED_P1, HIGH);
      digitalWrite(blueLED_P2, LOW);
    }
   
    else if (player_2 > player_1)
    {
      digitalWrite(blueLED_P1, LOW);
      digitalWrite(blueLED_P2, HIGH);
    }
   
    else
    {
      digitalWrite(blueLED_P1, HIGH);
      digitalWrite(blueLED_P2, HIGH);
    }

    if (player_1 > 30)
    {
      digitalWrite(greenLED_P1, HIGH);
      digitalWrite(blueLED_P1, LOW);
      digitalWrite(blueLED_P2, LOW);
      digitalWrite(greenLED_P2, LOW);
      delay(3000);
      
      gameState = 0;
      player_1 = 0;
      player_2 = 0;
    }
    
    if (player_2 > 30)
    {
      digitalWrite(greenLED_P1, LOW);
      digitalWrite(blueLED_P1, LOW);
      digitalWrite(blueLED_P2, LOW);
      digitalWrite(greenLED_P2, HIGH);
      delay(3000);
      gameState = 0;
      player_1 = 0;
      player_2 = 0;
    }
  }

  delay(5);

  if ( digitalRead(button_P1) == HIGH)
  {
    if (gameState ==  _____)
    {
      gameState =  _____1;
    }
    digitalWrite(greenLED_P1, HIGH);
    
    if (previousButtonState_P1 == LOW)
    {
      player_1 = player_1 + 1;
    }
    previousButtonState_P1 = HIGH;
  }

  else
  {
   
    digitalWrite(greenLED_P1, LOW);
    previousButtonState_P1 = LOW;
  }

  if ( digitalRead(button_P2) == HIGH)
  {
    if (gameState ==  _____)
    {
      gameState =  _____;
    }

    digitalWrite(greenLED_P2, HIGH);
    if (previousButtonState_P2 == LOW)
    {
      player_2 = player_2 + 1;
    }
    previousButtonState_P2 = HIGH;
  }
  else
  {
    digitalWrite(greenLED_P2, LOW);
    previousButtonState_P2 = LOW;
  }
}
