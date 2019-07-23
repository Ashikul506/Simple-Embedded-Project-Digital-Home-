#include <Servo.h>
Servo myservo;
int eco=12;
int trig=11;
int time1=0;
float dist=0;
int servopin=9;
int greenled=5;
int whiteled=6;
int blueled=7;
int buzzer=8;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(eco,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(whiteled,OUTPUT);
  pinMode(blueled,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
  myservo.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  time1=pulseIn(eco,HIGH);
  dist=time1*.034/2;
  Serial.print("Distance = ");
  Serial.print(dist);
  Serial.print(" cm.");
  Serial.print("\n");
  if(dist<=10 && dist>=0)
  {
    myservo.write(15);
    digitalWrite(greenled,HIGH);
    digitalWrite(whiteled,HIGH);
    digitalWrite(blueled,LOW);
    tone(buzzer,1000);
    delay(300);
  }
  else
  {
    myservo.write(90);
    digitalWrite(greenled,LOW);
    digitalWrite(whiteled,LOW);
    digitalWrite(blueled,HIGH);
    noTone(buzzer);
    delay(300);
  }
  delay(300);
}
