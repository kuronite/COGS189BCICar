/*****************************************
Motor movement instructions options:
- forward
- reverse
- pause
*****************************************/

// Define Pins
const int Ain1Pin = 7;
const int Ain2Pin = 8;
const int PwmAPin = 9;
const int Bin1Pin = 4;
const int Bin2Pin = 5;
const int PwmBPin = 6;


void forward(int aSpeed) {
    // Move motor A forward at full speed
    digitalWrite(Ain1Pin, LOW);
    digitalWrite(Ain2Pin, HIGH);
    analogWrite(PwmAPin, aSpeed);
    // Move motor B forward at full speed
    digitalWrite(Bin1Pin, LOW);
    digitalWrite(Bin2Pin, HIGH);
    analogWrite(PwmBPin, aSpeed);
}

void reverse(int aSpeed) {
    // Move motor A forward at full speed
    digitalWrite(Ain1Pin, HIGH);
    digitalWrite(Ain2Pin, LOW);
    analogWrite(PwmAPin, aSpeed);
    // Move motor B forward at full speed
    digitalWrite(Bin1Pin, HIGH);
    digitalWrite(Bin2Pin, LOW);
    analogWrite(PwmBPin, aSpeed);
}

void pause(){
    // Stop motor A
    analogWrite(PwmAPin, 0);
    // Stop motor B
    analogWrite(PwmBPin, 0);
}
