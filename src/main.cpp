#include <Arduino.h>
#include <NanitLib.h>
#include <Motor.h>

Motor motor1(MOTOR_ENABLE, MOTOR1_A, MOTOR1_B);
Motor motor2(MOTOR_ENABLE, MOTOR2_A, MOTOR2_B);


void printMenu(){
  Serial.println("====================================");
  Serial.println("Command list:");
  Serial.println("1. forward");
  Serial.println("2. backward");
  Serial.println("3. stop");
  Serial.println("Please enter number command:");
}

void setup() {
  Serial.begin(9600);
  Nanit_Base_Start();
  printMenu();

}

void loop() {
  while( Serial.available() ) {
    String c = Serial.readString();
    Serial.print("Received: ");
    Serial.println(c);

    if (c == "1") {
      motor1.setDirection(true);
      motor1.setSpeed(255);
      Serial.println("🟢Forward");
    } else if (c == "2") {
      motor1.setDirection(false);
      motor1.setSpeed(255);
      Serial.println("🟡Backward");
    } else if (c == "3") {
      motor1.stop();  
      Serial.println("🔴Stop");
    }else {
      Serial.println("❌Invalid command");
    }
    printMenu();
  }
  
}

