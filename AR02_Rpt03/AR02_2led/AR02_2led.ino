/*
 예제 4.1
 LED 점멸
*/

const int ledA   =  1;
const int ledB   =  2;
const int ledC   =  4;
const int ledD   =  8;

int number = 1;
boolean flag = true;

void setup()
{
  Serial.begin(9600);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
}

void loop()
{
  digitalWrite(ledA,HIGH);
  digitalWrite(ledB,LOW);
  digitalWrite(ledC,LOW);
  digitalWrite(ledD,LOW);
  delay(100 * number);
  digitalWrite(ledA,LOW);
  digitalWrite(ledB,HIGH);
  digitalWrite(ledC,LOW);
  digitalWrite(ledD,LOW);
  delay(100 * number);
  digitalWrite(ledA,LOW);
  digitalWrite(ledB,LOW);
  digitalWrite(ledC,HIGH);
  digitalWrite(ledD,LOW);
  delay(100 * number);
  digitalWrite(ledA,LOW);
  digitalWrite(ledB,LOW);
  digitalWrite(ledC,LOW);
  digitalWrite(ledD,HIGH);
  Serial.print("delay = ");
  Serial.print(100 * number);
  Serial.println(" msec");
  delay(100 * number);

if(flag) {
  number++;
} else {
  number--;
}


if(number >= 20){
    flag = false;
  }
else if(number == 1){
    flag = true;
  }
}
