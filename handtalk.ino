#include <SD.h>
#define SD_ChipSelectPin 4
#include <TMRpcm.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
TMRpcm tmrpcm;
//Constants:
const int flexPin = A0; //pin A0 to read analog input
const int flexPin1=A1;
const int flexPin2=A2;
const int flexPin3=A3;
//Variables:
int value,value1,value2,value3; //save analog value
void setup() {
tmrpcm.speakerPin=8;
Serial.begin(9600);       //Begin serial communication
lcd.begin(16, 2);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.setVolume(5);
}
void loop()
{
 value = analogRead(flexPin); //Read and save analog value from potentiometer
 value1=analogRead(flexPin1);
 value2=analogRead(flexPin2);
 value3=analogRead(flexPin3);
  Serial.println(value);               //Print value
  Serial.println(value1);
  Serial.println(value2);
  Serial.println(value3);
  delay(1000);                          //Small delay
  if(value<425 && value1>425 && value2>425 && value3>425){  
    //digitalWrite(1,HIGH);
    lcd.setCursor(0, 0);
    lcd.print("HELLO");
    tmrpcm.play("Hello.wav");
    delay(1000);
  }
  else if(value>425 && value1<425 && value2>425 && value3>425)
  {
    //digitalWrite(1,HIGH);
    lcd.setCursor(0, 0);
    lcd.print("THIS IS");
    tmrpcm.play("ThisIs.wav");
    delay(1000);
  }
  else if(value>425 && value1>425 && value2<425 && value3>425)
  {
    //digitalWrite(2,HIGH);
    lcd.setCursor(0, 0);
    lcd.print("HandTalk");
    tmrpcm.play("HandTalk.wav");
    delay(1000);
  }
  else if(value>425 && value1>425 && value2>425 && value3<425)
  {
    //digitalWrite(2,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("AtYourService.wav");
    lcd.print("AT YOUR SERVICE");
    delay(1000);
  }
  else if(value<425 && value1<425 && value2>425 && value3>425)
  {
    //digitalWrite(3,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("IAm.wav");
    lcd.print("I AM");
    delay(1000);
  }
  else if(value>425 && value1<425 && value2<425 && value3>425)
  {
    //digitalWrite(3,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("AnInterpretor.wav");
    lcd.print("AN INTERPRETER");
    delay(1000);
  }
  else if(value>425 && value1>425 && value2<425 && value3<425)
  {
    //digitalWrite(4,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("WhichConverts.wav");
    lcd.print("WHICH CONVERTS");
    delay(1000);
  }
  else if(value<425 && value1>425 && value2<425 && value3>425)
  {
    //digitalWrite(4,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("HandGestures.wav");
    lcd.print("HAND GESTURES");
    delay(1000);
  }
  else if(value>425 && value1<425 && value2>425 && value3<425)
  {
    //digitalWrite(5,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("ToTextAndVoice.wav");
    lcd.print("TO TEXT AND VOICE");
    delay(1000);
  }
  else if(value<425 && value1>425 && value2>425 && value3<425)
  {
    //digitalWrite(5,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("Sushant.wav");
    lcd.print("SUSHANT");
    delay(1000);
  }
  else if(value<425 && value1<425 && value2<425 && value3>425)
  {
    //digitalWrite(6,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("Shefin.wav");
    lcd.print("SHEFIN");
    delay(1000);
  }
  else if(value>425 && value1<425 && value2<425 && value3<425)
  {
    //digitalWrite(6,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("Akshay.wav");
    lcd.print("AKSHAY");
    delay(1000);
  }
  else if(value<425 && value1<425 && value2>425 && value3<425)
  {
    //digitalWrite(7,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("SigningOff.wav");
    lcd.print("SIGNING OFF");
    delay(1000);
  }
  else if(value<425 && value1<425 && value2<425 && value3<425)
  {
    //digitalWrite(7,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("ThankYou.wav");
    lcd.print("THANK YOU");
    delay(1000);
  }
  lcd.clear();
}