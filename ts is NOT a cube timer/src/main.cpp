#include <Arduino.h>




// put function declarations here:


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(2,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  // pinMode(4,OUTPUT);
  // pinMode(10,OUTPUT);
  // digitalWrite(4,HIGH);
  // digitalWrite(10,HIGH);
}

void loop() {
  // bool aIsDown = false;
  // bool bIsDown = false;
  // Serial.println(digitalRead(2) == LOW);
  // Serial.println(digitalRead(3) == LOW);
  // Serial.println(digitalRead(2));
  // Serial.println(digitalRead(8));
  if (digitalRead(2) == LOW) {
    // bIsDown = true;
    // Serial.write((char) 98);
    Serial.write("A");
  }
  else {
    Serial.write("C");
  }
  if (digitalRead(8) == LOW) {
    Serial.write("B");
      // aIsDown = true;
    // Serial.write((char) 97);
  }
  else {
    Serial.write("D");
  }


  // Serial.write(buf);  // put your main code here, to run repeatedly:
  delay(250);
}

// put function definitions here: