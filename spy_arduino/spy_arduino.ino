#include<Servo.h>
#define e1 3
#define l1 4
#define l2 5
#define r1 2
#define r2 7
#define e2 6
#define l3 12
const int trigPin = A0;
const int echoPin = A1;
Servo myservo,myservo1;
int pos = 90;
int incomingByte=0;
int d = 10;            // step size
bool toggle = true;
bool boggle = true;


long duration;
int distance;

void setup() {
  Serial.begin(9600);
  myservo.attach(11);
  myservo1.attach(10);
  myservo1.write(90);
  pinMode(e1,OUTPUT);
  pinMode(e2,OUTPUT);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(l3,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(A0, OUTPUT); 
  pinMode(A1, INPUT);
  

  analogWrite(e1,255);
  analogWrite(e2,255);

   
  
  
}

void loop() {

  digitalWrite(A0, LOW);
  delayMicroseconds(2);

digitalWrite(A0, HIGH);
delayMicroseconds(10);
digitalWrite(A0, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(A1, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor


  if (Serial.available() > 0) {
  
    incomingByte = Serial.read();
    //Serial.println(incomingByte);
    if(incomingByte==97){      //a
      forward();
    }
    else if(incomingByte==98){    //b
      back();
    }
    else if(incomingByte==99){     //c 
        left();
    }
    else if(incomingByte==100){    //d
      right();
    }
    else if(incomingByte==101){    //e
      led();
    }
    else if(incomingByte==102){    //f
      buzzer();
    }
    else if(incomingByte==103){    //g
      angleup();
    }
    else if(incomingByte==104){    //h
      angledown();
    }
    else if(incomingByte==105){    //i
      actuator();
    }
    else if(incomingByte==106){    //j
      ultra();
    }
    //Serial.println(pos);
    ultra();
  }
  }
void led()
{
  if(toggle){
  digitalWrite(l3,HIGH);}
  else{
    digitalWrite(l3,LOW);
  }
  toggle = ! toggle;
}


void back(){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  delay(100);
  low();

}
void forward(){
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  delay(100);
  low();

}
void right(){
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  delay(100);
  low();

}
void left(){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  delay(100);
  low();

}
void buzzer(){
    if(boggle){
  digitalWrite(A5,HIGH);}
  else{
    digitalWrite(A5,LOW);
  }
  boggle = ! boggle;
}




void low(){
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
}

void angleup(){
  myservo.write(pos+d);
  pos +=d;
  if(pos>180)
    pos = 180;
}

void angledown(){
  myservo.write(pos-d);
  pos-=d;
  if(pos<0)
    pos = 0;
}


void actuator(){
  for (pos = 60; pos <= 120; pos += 1) { 
    // in steps of 1 degree
    myservo1.write(pos);              
    delay(15);                       
  }
  for (pos = 120; pos >= 60; pos -= 1) { 
    myservo1.write(pos);              
    delay(15);                       
  }
}


void ultra(){
  
Serial.print("Distance: ");
Serial.println(distance);
}


