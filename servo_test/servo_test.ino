#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);
Servo myServo;

void setup() {
  // 1. Exact LCD Pattern that worked
  Wire.begin(21, 22);
  lcd.init();
  
  for(int i = 0; i < 3; i++) {
    lcd.backlight();
    delay(500);
    lcd.noBacklight();
    delay(500);
  }
  lcd.backlight(); 
  lcd.print("ADEOYE READY");

  // 2. Wait 2 seconds so you can actually read it
  delay(2000);

  // 3. Servo Setup on Pin 18
  // We use the most basic attach possible
  myServo.setPeriodHertz(50);
  myServo.attach(18, 500, 2400); 
  
  lcd.setCursor(0, 1);
  lcd.print("SERVO ACTIVE");
}

void loop() {
  // We use very small movements to prevent heavy vibration
  myServo.write(45);
  delay(1000);
  myServo.write(135);
  delay(1000);
}
