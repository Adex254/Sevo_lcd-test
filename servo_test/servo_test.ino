#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

// LCD Setup
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// Servo Setup
Servo myServo;
int servoPin = 4; 

void setup() {
  Serial.begin(115200);
  
  // LCD Init
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SYSTEM START");

  // Allow timers to allocate for ESP32
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  
  myServo.setPeriodHertz(50);
  myServo.attach(servoPin, 500, 2400);

  delay(1000);
  lcd.clear();
  lcd.print("SERVO ACTIVE");
}

void loop() {
  // Sweep from 0 to 180 degrees
  lcd.setCursor(0, 0);
  lcd.print("SWEEP: 0->180  ");
  for (int pos = 0; pos <= 180; pos += 5) { // Move in 5-degree steps to save power
    myServo.write(pos);
    lcd.setCursor(0, 1);
    lcd.print("Angle: ");
    lcd.print(pos);
    lcd.print("   ");
    delay(50); // Small delay for smooth movement
  }

  // Sweep from 180 back to 0
  lcd.setCursor(0, 0);
  lcd.print("SWEEP: 180->0  ");
  for (int pos = 180; pos >= 0; pos -= 5) {
    myServo.write(pos);
    lcd.setCursor(0, 1);
    lcd.print("Angle: ");
    lcd.print(pos);
    lcd.print("   ");
    delay(50);
  }
}
