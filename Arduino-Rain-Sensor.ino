#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int sensor = 8;
void setup() {
  pinMode(sensor,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool okunan = digitalRead(sensor);
  if(okunan == false){
    Serial.println("yağmur var");
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    lcd.begin(16,2);
    lcd.clear();
    lcd.print("Yagmur var");
  }
  else{
    Serial.println("yağmur yok");
    lcd.begin(16,2);
    lcd.clear();
    lcd.print("Yagmur yok");
  }
  delay(500);
}
