//XAMK project - Teemu Koivuniemi & Krista Pesonen

#include <IRremote.hpp>
// KOMMENTIT ON KIRJOITETTU AINOASTAAN, JOTTA KIMMON MIELENTERVEYS SÄILYY!!!
//Comments written only for teacher's sanity (says Teemu)
//Krista does not agree, Krista likes comments.
 
int IR_RECEIVE_PIN = 5; //arduino pin 5
bool CONTINUE = true;
int LEVEL = 3; //start with three blinks
int redLed = 9; //pin 9
int greenLed = 10; //pin 10
int yellowLed = 11; //pin11
//remote input sequence
int IRArray[100];
//randomized simon says sequence
int ledArray[100];
int i = 0;
int j = 0;
int score = 0;
//computer turn loop flag
bool arTurn = true;
//player turn loop flag
bool plaTurn = false;
//scoring loop flag
bool scoTurn = false;

//initialize game
void setup()
{
  delay(3000);
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK); // start remote
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
}

//create and save a randomized led sequence into an array. level == number of lights.
//switch to player turn upon completion.
void loop() {
  if (CONTINUE == true && arTurn == true) { 
    for(i = 0; i < LEVEL; i++) {            
      int randomLed = random(9,12);
        digitalWrite(randomLed, HIGH);
        delay(500);
        digitalWrite(randomLed, LOW);
        delay(500);
        ledArray[i] = randomLed;
      }
    arTurn = false;
    plaTurn = true;
  }

//read and save player input into an array.
//switch to score turn upon completion.
  if (CONTINUE == true && plaTurn == true && j < LEVEL){
    while (!IrReceiver.decode()) {}
        if (IrReceiver.decodedIRData.command == 16) {
           IRArray[j] = {9};
           j++;
           if (j == LEVEL) {plaTurn = false; scoTurn = true;}
           delay(500);
          }
        else if (IrReceiver.decodedIRData.command == 17) {
            IRArray[j] = {10};
            j++;
            if (j == LEVEL) {plaTurn = false; scoTurn = true;}
            delay(500);
          }
        else if (IrReceiver.decodedIRData.command == 18) {
           IRArray[j] = {11};
           j++;
           if (j == LEVEL) {plaTurn = false; scoTurn = true;}
           delay(500);
          }
        IrReceiver.resume();
      }

//compare computer generated arrays and player input arrays.
//if correct, increase score, move to the next level.
//if incorrect, print current score, return score to 0 and level to 3 (beginning)
  if (scoTurn == true) {
    for (i = 0; i < LEVEL; i++) {
      if (IRArray[i] == ledArray[i]){
          //a spot of beautiful empty space to reminisce about your life choices
      }
      else if (IRArray[i] != ledArray[i]) {
        Serial.print("Game over, total score: ");
        Serial.println(score);
        score = 0;
        LEVEL = 3;
        CONTINUE = false;
        }
      }

    score++;
    Serial.print("Current score: ");
    Serial.println(score);
    scoTurn = false;
    arTurn = true;
    LEVEL++;
    i = 0;
    j = 0;
    delay(3000);
  }
}
