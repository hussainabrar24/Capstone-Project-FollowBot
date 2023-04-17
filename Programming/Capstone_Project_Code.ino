//motor pin setup
int motor1pin1 = 2;
int motor1pin2 = 4;
int motor1pin3 = 3;

int motor2pin1 = 6;
int motor2pin2 = 7;
int motor2pin3 = 5;

// sensor pin setup
int trigPin = 8;
int echoPin = A5;

int LED1 = 11;
int LED2 = 12;
int LED3 = 13;

// distance variables
long duration, distance;

int disPin = A0;
int dis;
int setdis;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor1pin3, OUTPUT);
  
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor2pin3, OUTPUT);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(disPin,INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // redefine potentiometer values into distance variables 
  dis = analogRead(disPin);
  setdis = map(dis, 0, 1023, 5, 90); //actually 5-83 for some reason
  Serial.println(setdis);
  
  if(setdis >= 65){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
  }
  else if(setdis >= 30 && setdis <= 64){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
  }
  else if(setdis >= 5 && setdis <= 29){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
  }
  
  //Sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 74;
    
    if (distance <= setdis) {
      analogWrite(motor1pin3, 0);
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);
      
      analogWrite(motor2pin3, 0);
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);
    }
    else{
      analogWrite(motor1pin3, 255);
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      
      analogWrite(motor2pin3, 255);
      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
    }
}
