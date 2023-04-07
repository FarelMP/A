#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int pinled[7] = {2,3,4,6,7,8,9};
const int pb = 13;
int k = 0;
const int angka[10][7]= {
{2,3,4,6,7,8},
{3,4},
{2,3,6,7,9},
{2,3,4,6,9},
{3,4,8,9},
{2,4,6,8,9},
{2,4,6,7,8,9},
{2,3,4},
{2,3,4,6,7,8,9},
{2,3,4,6,8,9},
};

void setup() {
lcd.begin(16,2);
lcd.backlight();
for(int i = 0; i<8; i++){
  pinMode(pinled[i], OUTPUT);
}  
lcd.setCursor(3,0);
lcd.print("LOADING...");
  pinMode(pb,INPUT_PULLUP);
for(int i=0; i<6;i++){
    digitalWrite(pinled[i],HIGH);
    delay(250);
    digitalWrite(pinled[i], LOW);
    delay(50);
  }

  for(int j = 0; j<3;j++){
     for(int i=0; i<7;i++){
    digitalWrite(pinled[i],HIGH);
  }
  delay(250);
   for(int i=0; i<7;i++){
    digitalWrite(pinled[i],LOW);
  } 
delay(250);
}
lcd.setCursor(1,0);
lcd.print("BUTTON READY!!");
}

void loop() {
  lcd.setCursor(0, 1);
  if(digitalRead(pb)==LOW){
    if(k == 10){
      k = 0;
    }
    lcd.print("ANGKA TAMPIL : ");
    lcd.setCursor(15,1);
    lcd.print(k);
    for(int j = 0;j<7;j++){
      digitalWrite(angka[k-1][j],LOW);
    }
    for(int j = 0;j<7;j++){
      digitalWrite(angka[k][j],HIGH);
    }
    delay(500);
    k++;
  }
}