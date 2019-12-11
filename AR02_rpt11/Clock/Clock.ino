#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // or 0x3F

#define btnH 5
#define btnM 4
unsigned long times=0;
unsigned long seconds=55;
unsigned long minutes=29;
unsigned long hours=12;
unsigned long cnt=0;
int buzzerPin = 9;
const int button = 2;
const int ledPin = 13;

void setup()
{
   // 부저핀을 출력으로 설정한다
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  lcd.init();
  delay(1000);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(" AR02 AR03 Clock ");

  times=millis() / 1000;

  pinMode(btnH, INPUT);
  pinMode(btnM, INPUT);
}
  
void loop()
{
   // 부저 출력 시간에 사용할 변수 설정
  int buttons = digitalRead(button);
  int ledOutput = digitalRead(ledPin);
 
    if(hours == 12 && minutes == 30 && seconds ==0)
    {
    tone(buzzerPin, 262);
     digitalWrite(ledPin,HIGH);
     }
     if(buttons == LOW)
     {
      pinMode(buzzerPin, INPUT);
      digitalWrite(ledPin,LOW);
     }
  
  if (digitalRead(btnH)==HIGH && cnt==0)
  {
    hours++;
    if (hours>=24)
    {
      hours=0;
    }
    cnt=millis();
  }
  else if (digitalRead(btnM)==HIGH && cnt==0)
  {
    minutes++;
    if (minutes>=60)
    {
      minutes=0;
    }
    cnt=millis();
  }
  else if (millis() > cnt+200)
  {
    cnt=0;
  }

 if (millis() / 1000 > times)
  {
    seconds++;

    if (seconds>=60)
    {
      minutes++;
      seconds=0;
      if (minutes>=60)
      {
        hours++;
        minutes=0;
        if (hours>=24)
        {
          hours=0;
        }
      }
    }

    times=millis() / 1000;
  }

 lcd.setCursor(4,1);

  if (hours<10)
  {
    lcd.print("0");
  }
  lcd.print(hours);
  lcd.print(":");
  if (minutes<10)
  {
    lcd.print("0");
  }
  lcd.print(minutes);
  lcd.print(":");
  if (seconds<10)
  {
    lcd.print("0");
  }
  lcd.print(seconds);
}
