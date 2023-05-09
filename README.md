# CAPSTONE PROJECT FOllOWBOT
![IMG-1774](https://user-images.githubusercontent.com/111074043/236255946-de3e6c61-0134-4746-8af7-e1f6ae0eb36c.jpg)

# About Us (Group Members)
![unnamed (31)](https://user-images.githubusercontent.com/111074043/234903571-2429d9ea-23f3-40ba-a8c1-9c0da4447094.jpg)

➼ Abrar Hussain


➼ I am Abrar, an exchange student from Pakistan and a Junior at Windsor High School. I was on the robotics team this year (2022-2023) First Tech Challenge and I like 
tweaking things and try to know how they work which brings my interest in robotics.

![unnamed (32)](https://user-images.githubusercontent.com/111074043/234903840-ab4a7d63-b09f-42b3-a998-97a947ba8315.jpg)

➼ Matthew Murray


➼ I am Matthew, a Junior at Windsor High School and was on the robotics team of year 2021-2022 First Tech Challenge and I have great interest in technincal stuff.
I would love to persue electrical engineering in my future.

# Date : 10th May,2023

# Design Summary

Many students have to carry their backpacks on a daily basis from class to class. By using robotics, we can solve this problem by making a robot which follows the person. This project can be useful while shopping etc, as the user does not have to carry the cart all the way to the checkout and through the aisles. What if we make something that just follows that person. Our particular focus of this project is to build a lightweight (Can be modified for Heavyweights) load carrying robot with user movement.
With the Followbot at their side students can simply walk they need to go, and the Followbot will carry their things behind them. Students can manually change the distance that it will follow, allowing easy use in crowded hallways. The Followbot may soon diminish the need for the common backpack. 

![Tetrix Wheels (1)](https://user-images.githubusercontent.com/111074043/236857213-e7652622-8bce-4850-a9b1-316c9a05c92c.png)

# System Details
![image](https://user-images.githubusercontent.com/90795823/236869979-9dcb5317-9adb-48f9-8fd8-520eda2ae730.png)
All wires are plugged into the Arduino Uno via male pin header soldered on the end of each wire, shrinkwrapped to reduce the chance of a short circut.
All wires on the motor controller are soldered directly to the board, with shrinkwrap between each connection to reduce the chance of a short circut.


![image](https://user-images.githubusercontent.com/90795823/236870901-8c946004-9d83-43b2-ac1b-820f0a3c4c4e.png)
All connections are soldered and there is no possibility of a short circut. All power connections are soldered to the main breadboard, with all ground connections soldered to an external breadboard fragment. The power switch is fastened tightly into the side of the Followbot head.


# Design Evaluation
Each of the requirements for this project are fufilled by the Followbot. The output display is the three LEDs that shine when a certain threshhold is reached by the potentiometer. The manual user input is fufilled via potentiometer that sets the distance that the Followbot will follow. The automatic sensor is the ultrasonic distance sensor that allows the Followbot to accuratly follow and "see" the person it is following. The actuators are the motors that move the Followbot at half the speed of smell. The programmed logic of the Followbot is the arduino uno, the brains of the Followbot. We have had many issues with the Followbot, specifically the power. We currently have three 12v battery packs wired in parellel for a grand total of 24 rechargable AA batteries. As of now, the Followbot cannot turn. At least not intentionally. We do not yet know the exact weight limit of the Followbot, all we know is the limit is somewhere between a fully loaded backpack and a human. 


# Part List
S.No:    Name      Quantity  Cost

1. Tetrix channels 5 * $6  = $ 30

2. Arduino Uno 1*$16       = $ 16

3. Ultrasonic Sensor 1*$2  =  $2

4. AndyMark Motors 2*$6    = $12

5. AA Battery Pack  3*$4   = $12

6. Tetrix Wheels 2*$6      = $12  

7. Potentiometer 1*$0.75   = $0.75

8. LED 3*$0.16             = $0.50

9. Motor Controller 1*$4   = $4

10. Other Parts $14       = $10.75



                  Combined   Total $100



# lesson learned
We faced so many issues regarding our capstone project that are listed below with the explanation of how we overcame those issues.
1. Power And Voltage Distribution
We had issues of using enogh batteries but the output was not equal to the projected as we were using only two motors and those were so slow. We had discussion with Mr. Brayan from Computer Science department in Colorado State University and he helped us regarding this issue. We increased the number of batteries and put them in parallel circuit which resulted in same voltage but high current which solved our issue. 
2. 


# Instructions to build our prototype
![FOLLOWBOT](https://github.com/hussainabrar24/Capstone-Project-FollowBot/assets/111074043/7361e53a-d7fd-47ec-8478-eb7f74192af2)



# Detailed Wiring Diagram
![image](https://user-images.githubusercontent.com/90795823/236860401-bdc86d6b-5562-4c42-9489-af6280068231.png)

# 3D Printing
![Battery Pack](https://user-images.githubusercontent.com/111074043/236872400-55b62cec-6426-4f7a-a4f8-e05f6298e5d4.png)

# Programming

//motor pin setup on I/O pins 2-7
int motor1pin1 = 2;
int motor1pin2 = 4;
int motor1pin3 = 3;

int motor2pin1 = 6;
int motor2pin2 = 7;
int motor2pin3 = 5;

// sensor pin setup
int trigPin = 8; // I/O pin 8
int echoPin = A5; // Analog pin 5

// LEDs on I/O pin 11-13
int LED1 = 11;
int LED2 = 12;
int LED3 = 13;

// distance variables defined
long duration, distance;

// Potentiometer variables defined
int disPin = A0;
int dis;
int setdis;

void setup() {
  // pinmode setup for all pins previously defined
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
  
  // Serial port useful for debugging 
  Serial.begin(9600);
}

void loop() {
  // redefine potentiometer values into distance variables 
  dis = analogRead(disPin);
  setdis = map(dis, 0, 1023, 5, 90); //actually 5-83 for some reason
  
  // Send potentiometer values through serial port for distance testing
  Serial.println(setdis);
  
  // LED indicators programmed to shine once a certain threshhold is reached by the potentiometer
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
  else if(setdis <= 29){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }
  
  // Sensor translation into inches
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 74;
    
  // Once the Followbot senses an object in range, it stops until the object is no longer in range
    if (distance <= setdis) {
      analogWrite(motor1pin3, 0);
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);
      
      analogWrite(motor2pin3, 0);
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);
    }
  // While no object is in range, the Followbot will continue moving forward until an object is in range
    else{
      analogWrite(motor1pin3, 255);
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      
      analogWrite(motor2pin3, 255);
      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
    }
}






# How it will look

➼ Tank drive without treads


➼ Two wheeled drive


➼ U-Channel stand for holding the electronics


➼ A custom designed case for the electronics


➼ Cardboard for the base with a tetrix channel as a support

➼ Makeshift castor wheels

➼ Three battery packs (36 batteries)in parallel










