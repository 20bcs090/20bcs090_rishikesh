// include the library code:
#include <LiquidCrystal.h>
#include <Arduino.h>
#include <analogWrite.h>

int Contrast = 50;
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);
const int trigPin = 1;
const int echoPin = 3;
const int ledPin = 13; 
long duration;
int distanceCm, distanceInch;
 
void setup() {
  analogWrite(22, Contrast);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
 // lcd.print("circuitschools.");
  pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
  pinMode (ledPin, OUTPUT);

}
 
void loop() {
  digitalWrite (ledPin, LOW);
  delay(1000);
  digitalWrite(trigPin, LOW);
  
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;

lcd.setCursor(0,0);
lcd.print("Distance: "); 
lcd.print(distanceCm); 
lcd.print(" cm");
delay(10);
lcd.setCursor(0,1);
lcd.print("Distance: ");
lcd.print(distanceInch);
lcd.print(" inch");
delay(1000);
if (distanceCm < 5){
  digitalWrite (ledPin, HIGH);
delay(500);

  
  
}
}
