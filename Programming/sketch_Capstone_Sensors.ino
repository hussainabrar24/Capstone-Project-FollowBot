// pin setup
int trigPin = 8;
int echoPin = A5;

int led1 = 11;
int led2 = 12;
int led3 = 13;

// distance variables
long duration, distance;

int disPin = A0;
int dis;
int setdis;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(disPin,INPUT);
  
}

void loop() {
  // redefine potentiometer values into distance variables 
  dis = analogRead(disPin);
  setdis = map(dis, 0, 1023, 5, 90);
  Serial.println(setdis);
  
  //Sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 74;
    
    if (distance <= setdis) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
    }
    else{
      digitalWrite(led3, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }
}
