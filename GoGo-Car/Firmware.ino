#include <IRremote.h>
#include <IRremoteInt.h>

#include "IRremote.h"
#include "Arduino.h"
#include "Buzzer.h"
#include "NewPing.h"

// Pin Definitions
#define BUZZER_PIN_SIG  2
#define HCSR04_PIN_TRIG 4
#define HCSR04_PIN_ECHO 3
int receiver = 6; // Signal Pin of IR receiver to Arduino Digital Pin 6
int motorPinBR = 9;
int motorPinBL = 10;

Buzzer buzzer(BUZZER_PIN_SIG);
NewPing hcsr04(HCSR04_PIN_TRIG, HCSR04_PIN_ECHO);

IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results
void setup() {
  pinMode(motorPinBR, OUTPUT);
  pinMode(motorPinBL, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  irrecv.enableIRIn(); // Start the receiver
}
void loop()
{
  //custom();
  custom1();
  custom2();

  //analogWrite(motorPinBR, 0);
  //analogWrite(motorPinBL, 0);
  //Serial.println(results.value);
  //Serial.println(results.value);
  
}


void custom() {
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    switch (results.value)
    {
      case 0xFF629D: // VOL+ button pressed UP
        Serial.println("Up");
        analogWrite(motorPinBR, 255);
        analogWrite(motorPinBL, 255);
        delay(500);
        analogWrite(motorPinBR, 0);
        analogWrite(motorPinBL, 0);
        delay(500);
        break;

      case 0xFFA857: // VOL- button pressed Down
      Serial.println("Down");
        analogWrite(motorPinBR, 0);
        analogWrite(motorPinBL, 255);
        delay(2000);
        analogWrite(motorPinBR, 0);
        analogWrite(motorPinBL, 0);
        delay(300);
        analogWrite(motorPinBR, 255);
        analogWrite(motorPinBL, 255);
        delay(500);
        analogWrite(motorPinBR, 0);
        analogWrite(motorPinBL, 0);
        break;

      case 0xFF22DD: //Right
        analogWrite(motorPinBR, 255);
        analogWrite(motorPinBL, 0);
        delay(1000);
        analogWrite(motorPinBR, 0);
        analogWrite(motorPinBL, 0);
        delay(1000);
        break;

      case 0xFFC23D: //Left
        analogWrite(motorPinBR, 0);
        analogWrite(motorPinBL, 255);
        delay(1000);
        analogWrite(motorPinBR, 0);
        analogWrite(motorPinBL, 0);
        delay(1000);
        break;

        break;
    }
  }
}

void custom1() {
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    if (results.value == 0xFF629D)
    { // VOL+ button pressed UP
      analogWrite(motorPinBR, 255);
      analogWrite(motorPinBL, 255);
      delay(500);
      analogWrite(motorPinBR, 0);
      analogWrite(motorPinBL, 0);
      delay(500);
      irrecv.resume();
      //results.value = 0xFFFFFFFF;
      return;
    }
    else if (results.value == 0xFFA857)
    {
      // VOL- button pressed Down
      analogWrite(motorPinBR, 0);
      analogWrite(motorPinBL, 255);
      delay(2000);
      analogWrite(motorPinBR, 0);
      analogWrite(motorPinBL, 0);
      delay(300);
      analogWrite(motorPinBR, 255);
      analogWrite(motorPinBL, 255);
      delay(500);
      analogWrite(motorPinBR, 0);
      analogWrite(motorPinBL, 0);
      irrecv.resume();
    }
    else if (results.value == 0xFF22DD)
    {
      //Right
      analogWrite(motorPinBR, 255);
      analogWrite(motorPinBL, 0);
      delay(1000);
      analogWrite(motorPinBR, 0);
      analogWrite(motorPinBL, 0);
      irrecv.resume();
    }
    else if (results.value == 0xFFC23D)
    {
      //Left
      analogWrite(motorPinBR, 0);
      analogWrite(motorPinBL, 255);
      delay(1000);
      analogWrite(motorPinBR, 0);
      analogWrite(motorPinBL, 0);
      irrecv.resume();
    }
  }
}



void custom2() {
  int hcsr04Dist = hcsr04.ping_cm();
  if (hcsr04Dist < 10 && hcsr04Dist > 1)
  {
    Serial.println(hcsr04Dist);
    buzzer.on();       // 1. turns on
    delay(100);             // 2. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    buzzer.off();      // 3. turns off.
    delay(100);             // 4. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
  }
}
