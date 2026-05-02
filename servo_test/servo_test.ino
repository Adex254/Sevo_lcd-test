#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);
Servo myServo;

int servoPin = 13; // Use the pin labeled D13

void setup() {
  // 1. Start I2C for LCD
  Wire.begin(21, 22); 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LCD OK...");
  
  // 2. Wait 3 seconds - If the LCD stays on, the ESP32 is healthy
  delay(3000); 

  // 3. Attach Servo
  ESP32PWM::allocateTimer(0);
  myServo.setPeriodHertz(50);
  myServo.attach(servoPin, 500, 2400); 

  lcd.clear();
  lcd.print("SERVO STARTING");
}

void loop() {
  // Move to 45 degrees
  lcd.setCursor(0, 1);
  lcd.print("Angle: 45      ");
  myServo.write(45);
  delay(2000);

  // Move to 135 degrees
  lcd.setCursor(0, 1);
  lcd.print("Angle: 135     ");
  myServo.write(135);
  delay(2000);
}
