#include <MQ135.h>

#include <LiquidCrystal_I2C.h>

#include <MQ2.h>

LiquidCrystal_I2C lcd(0x27,2,16);

int servopin = 9;
int pin = 13;
int sensor = A0;
int sensor2 = A1;
int buzzer = 12;
int threshold = 300;
int threshold2 = 200;
MQ2 mq2(sensor);
MQ135 mq135(sensor2);
int lpg=0, co=0, smoke=0, methan=0,hydrogen = 0;
float co2;
void setup() {
Serial.begin(9600);
pinMode(pin,OUTPUT);
pinMode(sensor,INPUT);
pinMode(sensor2,INPUT);
pinMode(12,OUTPUT);
lcd.backlight();
lcd.begin();
mq2.begin();
lcd.print("Project By ");
/*delay(1500);
          lcd.clear();
          delay(800);*/
lcd.setCursor(0,1);
lcd.println("Abbas Mehdi");
          delay(1500);
          lcd.clear();
          delay(800);
//delay(1500);
}

void loop() {
  // put your main code here, to run repeatedly:
  //int lpg;
  int var = analogRead(A0);    
  int var2 = analogRead(A1);
  lpg = mq2.readLPG();
  co = mq2.readCO();
  smoke = mq2.readSmoke();
  methan = mq2.readMethan();
        if(var>=threshold || var2 >=threshold2)
        {
          
         lcd.print("LPG:");
         lcd.print(lpg);
         lcd.print(" CO:");
         lcd.print(co);
         lcd.setCursor(0,1);
         lcd.print("H2:");
         lcd.print(hydrogen);
         lcd.print(" SMK:");
         lcd.print(smoke);
          delay(1600);
          lcd.clear();
         lcd.print("METHAN:");
         lcd.print(methan);
         delay(1600);
         lcd.clear();
         //tone(buzzer,1000,1000);
         if(methan > 1800)
         {
           //tone(buzzer,1000,1000);
          digitalWrite(buzzer,HIGH);
           delay(300);
         }else
         {
          // noTone(buzzer);
            digitalWrite(buzzer,LOW);
            delay(300);        
         }
         if(lpg > 1500 ||  smoke > 2500)
         {
           digitalWrite(pin,HIGH);
         }else
         {
           digitalWrite(pin,LOW);
         }
          delay(300); 
        }else {
         
         lcd.print("LPG:");
         lcd.print(lpg);
         lcd.print(" CO:");
         lcd.print(co);
         lcd.setCursor(0,1);
         lcd.print("H2:");
         lcd.print(hydrogen);
         lcd.print(" SMK:");
         lcd.print(smoke);
          delay(1600);
          lcd.clear();
         lcd.print("METHAN:");
         lcd.print(methan);
         lcd.setCursor(0,1);
         delay(1600);
          lcd.clear();
          delay(300);
            //noTone(buzzer);
        }
        
        delay(200);
}
