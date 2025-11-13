#include <DHT.h>
DHT dht(26,11);
const int fan=33;
const int buzzer=4;

int speed=0;
float temp1;
float avg;

void setup(){
  dht.begin();
  delay(1000);
  pinMode(fan,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(115200);
  Serial.println("Setting up temperature sensor");
}

void loop(){
  if(Serial.available()>0){
    String s=Serial.readStringUntil('\n');
    temp1=s.toInt();
    delay(10);
    float temp=dht.readTemperature();
    delay(50);

    Serial.print("Temperature from sensor:");
    Serial.print(temp);
    Serial.print(" C ");
    Serial.print("Temperature from input: ");
    Serial.print(temp1);
    Serial.println(" C ");
    avg=(temp1+temp)/2;
    if(avg>=10 && avg<=25){
      digitalWrite(buzzer,LOW);
      speed=70;
    }else if(avg>25 && avg<=30){
      digitalWrite(buzzer,LOW);
      speed=150;
    }else if(avg>30 && avg<=35){
      digitalWrite(buzzer,LOW);
      speed=170;
    }else if(avg>35){
      digitalWrite(buzzer,HIGH);
      speed=255;
    }else{
      speed=0;
      digitalWrite(buzzer,LOW);
    }
    analogWrite(fan,speed);
    Serial.print("Fan Speed: ");
    Serial.println(speed);
  }
  delay(100);
}