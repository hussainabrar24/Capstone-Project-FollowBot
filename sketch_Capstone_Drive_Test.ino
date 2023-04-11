int motor1pin1 = 2;
int motor1pin2 = 4;
int motor1pin3 = 3;

int motor2pin1 = 5;
int motor2pin2 = 7;
int motor2pin3 = 6;

int valGO = 120;
int valSTOP = 60;

void setup() {
    pinMode(motor1pin1, OUTPUT);
    pinMode(motor1pin2, OUTPUT);
    pinMode(motor1pin3, OUTPUT);
    
    pinMode(motor2pin1, OUTPUT);
    pinMode(motor2pin2, OUTPUT);
    pinMode(motor2pin3, OUTPUT);
    //////////////
    analogWrite(motor1pin3, valGO);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    
    analogWrite(motor2pin3, valGO);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    delay(2000);
    //////////////
    analogWrite(motor1pin3, valSTOP);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    
    analogWrite(motor2pin3, valSTOP);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    delay(500);
    //////////////
    analogWrite(motor1pin3, 0);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    
    analogWrite(motor2pin3, 0);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    delay(1000);
    //////////////
    analogWrite(motor1pin3, valGO);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    
    analogWrite(motor2pin3, valSTOP);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
    delay(500);
    //////////////
    analogWrite(motor1pin3, valGO);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    
    analogWrite(motor2pin3, valGO);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    delay(2000);
    //////////////
    analogWrite(motor1pin3, valSTOP);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    
    analogWrite(motor2pin3, valSTOP);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    delay(500);
    //////////////
    analogWrite(motor1pin3, 0);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    
    analogWrite(motor2pin3, 0);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    delay(1000);
    //////////////
    analogWrite(motor1pin3, valSTOP);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    
    analogWrite(motor2pin3, valGO);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    delay(500);
    //////////////
    analogWrite(motor1pin3, valGO);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    
    analogWrite(motor2pin3, valGO);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    delay(2000);
    //////////////
    analogWrite(motor1pin3, valSTOP);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    
    analogWrite(motor2pin3, valSTOP);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    delay(500);
    //////////////
    analogWrite(motor1pin3, 0);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    
    analogWrite(motor2pin3, 0);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    delay(1000);
}

void loop() {
    
}
