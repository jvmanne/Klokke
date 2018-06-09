//Koble til Adafruit HUZZAH ESP8266
//Når man bruker ESP8266

#include <Servo.h>

const int pinA = 7;
const int pinB = 8;
int pos = 0;
int valALast;
int valA;
int valB;

Servo myservo;

void setup() {
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  Serial.begin(9600);
  valALast = digitalRead(pinA);
  
  myservo.attach(4);
  myservo.write(0);
}

void loop() {
  valA = digitalRead(pinA);
  valB = digitalRead(pinB);
  if (valALast != valA) {
    if (valB != valA) {
      pos++;
    } else {
      pos--;
    }
    //Serial.println(pos);
    //myservo.write(pos);
  }
  valALast = valA;
  
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(0);
}
