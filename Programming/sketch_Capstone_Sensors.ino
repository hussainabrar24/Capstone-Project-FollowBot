#include <Servo.h>

Servo topservo;

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
int dis;
int setdis;

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
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(disPin,INPUT);
  
}

void loop() {
  dis = analogRead(disPin);
  setdis = map(dis, 0, 1023, 5, 90);
  Serial.println(setdis);
  
  
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