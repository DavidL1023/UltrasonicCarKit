#include <Arduino.h>
#include <Servo.h> // link all of these libraries in my readme on github
#include <Ultrasonic.h>
#include <IRremote.h>

// pin definitions
#define SONAR_SERVO_PIN A2
#define SONAR_TRIG_PIN A1 // creates ultrasound
#define SONAR_ECHO_PIN A0 // listens for ultrasound
#define IR_RECV_PIN 12 // listens for IR signal
#define SPEED_A_PIN 5 // motor A speed
#define DIRECTION1_A_PIN 4 // motor A direction
#define DIRECTION2_A_PIN 2
#define SPEED_B_PIN 6 // motor B speed
#define DIRECTION1_B_PIN 7 // motor B direction
#define DIRECTION2_B_PIN 8

// objects
Servo sonarServo;
Ultrasonic sonar(SONAR_TRIG_PIN, SONAR_ECHO_PIN);
IRrecv infared(IR_RECV_PIN);
decode_results irResults;

// variables
int sonarServoPos = 0; // stores radar's rotation value

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // arduino communication, 9600 baud rate
  infared.enableIRIn(); // start IR reciever

}

void loop() {
  // put your main code here, to run repeatedly:
  if(infared.decode(&irResults)){
    Serial.println("Decoded Value:");
    Serial.println(irResults.value, HEX); // print decoded hexadecimal
    infared.resume(); // recieve next value
  }

}