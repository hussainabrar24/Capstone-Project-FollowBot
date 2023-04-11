#include <Servo.h>

Servo topservo;

int motor1pin1 = 2;
int motor1pin2 = 4;
int motor1pin3 = 3;

int motor2pin1 = 7;
int motor2pin2 = 6;
int motor2pin3 = 5;

int trigPin1 = 8;
int echoPin1 = A2;

int trigPin2 = 9;
int echoPin2 = A3;

int trigPin3 = 10;
int echoPin3 = A4;

int led1 = 11;
int led2 = 12;
int led3 = 13;

long duration1, distance1;
long duration2, distance2;
long duration3, distance3;

int disPin = A0;
int spdPin = A5;
int dis;
int spd;
int setdis;
int setspd;


void setup() {
  Serial.begin(9600);
  
  topservo.attach(A1);
  topservo.write(90);
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  pinMode(motor1pin1,OUTPUT);
  pinMode(motor1pin2,OUTPUT);
  pinMode(motor1pin3,OUTPUT);
  
  pinMode(motor2pin1,OUTPUT);
  pinMode(motor2pin2,OUTPUT);
  pinMode(motor2pin3,OUTPUT);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(disPin,INPUT);
  pinMode(spdPin,INPUT);
  
}

void loop() {
  dis = analogRead(disPin);
  setdis = map(dis, 0, 1023, 5, 90);
  Serial.println(setdis);
  
  spd = analogRead(spdPin);
  setspd = map(spd, 0, 1023, 50, 200);
  Serial.println(setspd);
  
  
  front();
  if (distance1 <= setdis) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else {
    digitalWrite(led3, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  
  right();
  if (distance2 <= setdis) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  else {
    digitalWrite(led3, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  
  left();
  if (distance3 <= setdis) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
  else {
    digitalWrite(led3, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  
  //pivot right
  if(distance1 != setdis && distance2 <= setdis){
    topservo.write(135);
    delay(2000);
    digitalWrite(motor1pin1,HIGH);
    digitalWrite(motor1pin2,LOW);
    analogWrite(motor1pin3,setspd);
    
    digitalWrite(motor2pin1,HIGH);
    digitalWrite(motor2pin2,LOW);
    analogWrite(motor2pin3,255);
    delay(500);
  }
  else{
    
  }
  
  //pivot left
  if(distance1 != setdis && distance2 <= setdis){
    topservo.write(45);
    delay(2000);
    digitalWrite(motor1pin1,HIGH);
    digitalWrite(motor1pin2,LOW);
    analogWrite(motor1pin3,255);
    
    digitalWrite(motor2pin1,HIGH);
    digitalWrite(motor2pin2,LOW);
    analogWrite(motor2pin3,spd);
    delay(500);
  }
  else{
    
  }
  
  digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor1pin2,LOW);
  analogWrite(motor1pin3,setspd);
  
  digitalWrite(motor2pin1,HIGH);
  digitalWrite(motor2pin2,LOW);
  analogWrite(motor2pin3,setspd);
}
  
void front(){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 74;
}

void right(){
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 74;
}

void left(){
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = (duration3/2) / 74;
}