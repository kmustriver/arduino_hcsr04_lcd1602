/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin A5 Trig to Arduino pin A2
*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#define trigPin A2
#define echoPin A5

void setup() {
  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();                      // initialize the lcd 

  // Print a message to the LCD.
  lcd.backlight();
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance >= 400 || distance < 2){
    lcd.clear();
    lcd.print("Out of range");
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println("cm");
    lcd.clear();
    lcd.print(distance);
    lcd.print("cm");
    
  }
  delay(1000);
}
