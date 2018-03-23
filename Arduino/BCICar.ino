#include "motor_movement.h"           // Load motor functions

#define MAXSPEED 255

void setup() {
    pinMode(Ain1Pin, OUTPUT);
    pinMode(Ain2Pin, OUTPUT);
    pinMode(PwmAPin, OUTPUT);
    pinMode(Bin1Pin, OUTPUT);
    pinMode(Bin2Pin, OUTPUT);
    pinMode(PwmBPin, OUTPUT);

    Serial.begin(9600);
  
    forward(MAXSPEED); delay(200);
    reverse(MAXSPEED); delay(200);
    pause();
}

void loop() {
    if(Serial.available()) {
      delay(2000);
      int speed = Serial.parseInt();
      Serial.println(speed);

      if(speed >= 0 && speed <= 255) {
        forward(speed);
      }
    }
}
