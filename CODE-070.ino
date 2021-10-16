//#VTM https://www.youtube.com/c/VTMVlogVoThongMinh
#include <Wire.h>
#include <LiquidCrystal_I2C.h>  //https://drive.google.com/file/d/1lpJyuODmZXfi7wwBM2B79BqBIBmBfanS/view?usp=sharing
#define start 8
#define rain 7
#include <Servo.h>
int timer = 5; // tốc độ servo
int gocquay = 150; // góc quay
int pos = 0;
int aa = 0;
int a = 0;
Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
//............................................................
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  myservo.attach(3);
  pinMode(start, INPUT_PULLUP);
  pinMode(rain, INPUT);
  Serial.println("Da khoi dong xong");
  lcd.setCursor(0, 0);
  lcd.print("   RAIN SENSOR");
  myservo.write(pos);
}
//............................................................
void loop()
{
  a = analogRead(A0);
  aa = map(a, 150, 900, 0, 30);
  Serial.println(a);
  lcd.setCursor(4, 1);
  lcd.print("not rain");
  if ((digitalRead(start) == 0) || ( a < 900))
  {
    lcd.setCursor(4, 1);
    lcd.print("raining ");
    servo();
  }
}
//............................................................
void servo()
{
  a = analogRead(A0);
  aa = map(a, 150, 900, 0, 25);
  for (pos = 0; pos <= gocquay; pos += 1) {
    myservo.write(pos);
    if (a < 900)
    {
      delay(aa);
    }
    else
    {
      delay(timer);
    }
  }
  for (pos = gocquay; pos >= 0; pos -= 1) {
    myservo.write(pos);
    if (a < 900)
    {
      delay(aa);
    }
    else
    {
      delay(timer);
    }
  }
}
