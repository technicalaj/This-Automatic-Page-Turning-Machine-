
// tutorial video https://www.youtube.com/watch?v=53ykX3utPtw&t=28s

#include  <Servo.h>
#define echoPin 14
#define trigPin 12
#define motor 2 // relay  pin to operate motor 
Servo myservo;  // create servo object to control a servo

long  duration;
int distance;
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(motor,OUTPUT);
  myservo.attach(5,500,2500);  // attaches the servo on pin 9 to the servo object

}
void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration*0.034/2);
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm ");
  delay(100);
  
  if (distance <=50)
  {
    digitalWrite(motor,LOW);
    delay(1000);
    myservo.write(180);  
    delay(2000);
    digitalWrite(motor,HIGH);
    delay(1500);
    myservo.write(0);  
    delay(1000);          
  }

  else
   digitalWrite(motor,HIGH);  
}
