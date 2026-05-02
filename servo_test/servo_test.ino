#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

// LCD Setup
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// Servo Setup
Servo myServo;
int servoPin = 18; // Use GPIO 18 for the Servo signal wire

void setup() {
  // LCD Init
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();
  
  // Servo Init
  // Standard SG90 pulses are usually between 500us and 2400us
  myServo.setPeriodHertz(50); // Standard 50hz servo
  myServo.attach(servoPin, 500, 2400); 

  lcd.setCursor(0, 0);
  lcd.print("SERVO TEST");
}

void loop() {
  // Move to 0 degrees
  lcd.setCursor(0, 1);
  lcd.print("Angle: 0  ");
  myServo.write(0);
  delay(1000);

  // Move to 90 degrees
  lcd.setCursor(0, 1);
  lcd.print("Angle: 90 ");
  myServo.write(90);
  delay(1000);

  // Move to 180 degrees
  lcd.setCursor(0, 1);
  lcd.print("Angle: 180");
  myServo.write(180);
  delay(1000);
}
