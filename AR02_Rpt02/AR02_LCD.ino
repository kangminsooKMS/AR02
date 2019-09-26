/*
 예제 3.2
 I2C를 이용한 LCD 출력
*/
int blinkNumber = 0;
// I2C 통신 라이브러리 설정
#include <Wire.h>
// I2C LCD 라리브러리 설정
#include <LiquidCrystal_I2C.h>

// LCD I2C address 설정 PCF8574:0x27, PCF8574A:0x3F
LiquidCrystal_I2C lcd(0x27,16,2);  // LCD address:0x27, 16X2 LCD, 0x3F

void setup()
{
  // 9600 bps로 시리얼 통신 설정
  Serial.begin(9600);
  lcd.init(); // LCD 설정
  lcd.clear();      // LCD를 모두 지운다.
  lcd.backlight();  // 백라이트를 켠다.  
 
  // LCD 백라이트를 두 번 점멸  
  


  // Open Serial Monitor, Type to display 표시


  
}

void loop()
{
  // 시리얼 통신 수신 값이 있을 때
  if (Serial.available()) {	
    char val = Serial.read();
    if(isDigit(val)){
     // val은 ASCII 코드값이므로 숫자로 바꿔주기 위하여 
     // '0'의 아스키 코드값을 빼줌
     // blinkNumber에는 실제 숫자가 저장된다.
      blinkNumber = (val - '0');
    }
    delay(100);
    for(char i=0;i < blinkNumber; i++){  
    lcd.backlight();
    delay(200);
    lcd.noBacklight();
    delay(200);
    }
    // 모두 삭제
    lcd.clear();
     // 커서를 좌측 상단으로
    lcd.setCursor(0,0);
    lcd.print("message : ");
     lcd.print(blinkNumber);
  
   
  }
}
