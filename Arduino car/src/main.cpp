#include <Arduino.h>
#include <Servo.h> // link all of these libraries in my readme on github
#include <Ultrasonic.h>
#include <IRremote.h>

// definitions
#define SONAR_SERVO_PIN A2
#define SONAR_TRIG_PIN A1 // creates ultrasound
#define SONAR_ECHO_PIN A0 // listens for ultrasound
#define IR_RECV_PIN 12 // listens for IR signal

#define Lpwm_pin 5 // motor A speed
#define pinLF 4 // motor A direction
#define pinLB 2
#define Rpwm_pin 6 // motor B speed
#define pinRB 7 // motor B direction
#define pinRF 8

#define IR_Go      0x46 // controller keys
#define IR_Back    0x15
#define IR_Left    0x44
#define IR_Right   0x43
#define IR_Stop    0x40
#define Enable_Auto 0x4A
#define Enable_Manual 0x42

// objects
Servo sonarServo;
Ultrasonic sonar(SONAR_TRIG_PIN, SONAR_ECHO_PIN);
IRrecv infrared(IR_RECV_PIN);

// variables
int CAR_SPEED_AUTO = 120; // for PWM maximum possible values are 0 to 255
int CAR_SPEED_REMOTE = 150;

// functions
void drive(){ // for motors
     digitalWrite(pinRB,LOW);
     digitalWrite(pinRF,HIGH);
     digitalWrite(pinLB,LOW);
     digitalWrite(pinLF,HIGH); 
}
void turnR(){
     digitalWrite(pinRB,LOW);  
     digitalWrite(pinRF,HIGH);
     digitalWrite(pinLB,HIGH);
     digitalWrite(pinLF,LOW);  
}
void turnL(){
     digitalWrite(pinRB,HIGH);
     digitalWrite(pinRF,LOW);  
     digitalWrite(pinLB,LOW);  
     digitalWrite(pinLF,HIGH);
}    
void stopp(){
     digitalWrite(pinRB,HIGH);
     digitalWrite(pinRF,HIGH);
     digitalWrite(pinLB,HIGH);
     digitalWrite(pinLF,HIGH);
}
void reverse(){
     digitalWrite(pinRB,HIGH); 
     digitalWrite(pinRF,LOW);
     digitalWrite(pinLB,HIGH); 
     digitalWrite(pinLF,LOW);
}

void remoteControlCar(){ // CONTROL MANUALLY
  //recieve data
  int decoded;
  if(infrared.decode()){
    decoded = infrared.decodedIRData.command;
    Serial.println(decoded);
    infrared.resume(); // recieve next value
  }
  // control motors
  switch(decoded){
    case(IR_Go):
      drive();
      break;
    case(IR_Back):
      reverse();
      break;
    case(IR_Right):
      turnR();
      break;
    case(IR_Left):
      turnL();
      break;
    case(IR_Stop):
      stopp();
      break;
  }
}

void autoCar(){ // CONTROLS AUTOMATICALLY
  int frontDistance;

  sonarServo.write(85); // it's 85 because servo is a little off from the center
  frontDistance = sonar.read(); // in centimeters
  delay(15);
  drive();

  if(frontDistance < 25){
    int leftDistance;
    int rightDistance;

    stopp();
    sonarServo.write(180);
    leftDistance = sonar.read();
    delay(600);

    sonarServo.write(0);
    rightDistance = sonar.read();
    delay(600);

    sonarServo.write(85);
    delay(200);

    if(leftDistance > rightDistance){
      reverse();
      delay(180);
      turnL();
      delay(400);
    }
    if(leftDistance < rightDistance){
      reverse();
      delay(180);
      turnR();
      delay(400);
    }
    if(leftDistance == rightDistance){
      reverse();
      delay(400);
    }
  }
}

// ARDUINO
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // arduino communication, 9600 baud rate
  infrared.begin(IR_RECV_PIN); // start IR reciever
  sonarServo.attach(SONAR_SERVO_PIN); // give object pin

  // set motor pins to output (arduino pins are by default input)
  pinMode(pinLB,OUTPUT);
  pinMode(pinLF,OUTPUT);
  pinMode(pinRB,OUTPUT); 
  pinMode(pinRF,OUTPUT); 
  pinMode(Lpwm_pin,OUTPUT);  
  pinMode(Rpwm_pin,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int decoded; //recieve data
  if(infrared.decode()){
    decoded = infrared.decodedIRData.command;
    Serial.println(decoded);
    infrared.resume(); // recieve next value
  }

  while(decoded == Enable_Manual){
    // start motor
    analogWrite(Lpwm_pin, CAR_SPEED_REMOTE);
    analogWrite(Rpwm_pin, CAR_SPEED_REMOTE);
    remoteControlCar();
  }
  while(decoded == Enable_Auto){
    analogWrite(Lpwm_pin, CAR_SPEED_AUTO);
    analogWrite(Rpwm_pin, CAR_SPEED_AUTO);
    autoCar();
  }
}