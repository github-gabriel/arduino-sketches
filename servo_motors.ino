#include <Servo.h>

Servo servo;

int value;

void setup(){
  Serial.begin(9600);
  servo.attach(9);
  delay(50);
  servo.write(0);
}

void loop(){
  value = analogRead(0);
  value = map(value, 0, 1023, 0, 180);
  servo.write(value);
  delay(15);
}
