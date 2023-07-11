//define pins
#define S0 6
#define S1 5
#define S2 4
#define S3 3
#define sensorOut 2
#define SD_ChipSelectPin 53
//include library
#include "SD.h"
#include "TMRpcm.h"
#include "SPI.h"
#include <Servo.h> 
#include <LiquidCrystal.h>
//define pins
const int lamp = 7;
int red = 0;
int green = 0;
int blue = 0;
int servoPin1 = 23; 
int servoPin2 = 22;
int servoPin3 = 25;
int servoPin4 = 24;
//create objects
LiquidCrystal lcd(26, 27, 28, 29, 30, 31);
TMRpcm tmrpcm;
Servo Servo11; 
Servo Servo12; 
Servo Servo13; 
Servo Servo14; 

void setup() 
{
   tmrpcm.speakerPin=11;
   Servo11.attach(servoPin1); 
   Servo12.attach(servoPin2); 
   Servo13.attach(servoPin3); 
   Servo14.attach(servoPin4); 
   lcd.begin(16, 2);
   lcd.print("welcome");
   pinMode(lamp , OUTPUT);
   digitalWrite(7,HIGH);
   Servo11.write(0); 
   Servo12.write(0);
   Servo13.write(0);
   Servo14.write(0);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
 }
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  // Setting frequency scaling to 20%
  digitalWrite(S0,LOW);
  digitalWrite(S1,HIGH);
  // Begins serial communication 
  Serial.begin(9600);
}


void loop() 
{
  lcd.setCursor(0, 0);
  lcd.print("scanning.....");
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  red = pulseIn(sensorOut, LOW);
  // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(red);
  delay(500);
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  green = pulseIn(sensorOut, LOW);
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.print(green);
  delay(500);
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  blue = pulseIn(sensorOut, LOW);
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.println(blue);
  delay(500);
  int c = analogRead(A0);
  delay(500);
if ( c>35 && c<80 ){
 // Serial.println("real");
  lcd.setCursor(0, 0);
  lcd.print(" real note");
  delay(100);
 if ((red > 480 && green > 530 && blue > 435) &&( red < 510 && green < 565 && blue < 460  ))
      { 
      Serial.println ("old 100rs");
      lcd.setCursor(0, 0);
      lcd.print("100 rupees");
      tmrpcm.setVolume(6);
      tmrpcm.play("100.wav");
      Servo11.write(90); 
      Servo12.write(90);
      Servo13.write(0);
      Servo14.write(90);
      delay (2000);
      }
 else if ((red > 420 && green > 520 && blue > 375) &&( red < 470 && green < 570 && blue < 410  ))
       {
        Serial.println ("old 50rs");
        lcd.setCursor(0, 0);
        lcd.print("50 rupees");
        tmrpcm.setVolume(6);
        tmrpcm.play("50.wav");
        Servo11.write(90); 
        Servo12.write(90);
        Servo13.write(0);
        Servo14.write(0);
        delay (2000);
       } 
 else if ((red > 305 && green > 510 && blue > 400) &&( red < 340 && green < 590 && blue < 460 ))
       {
        Serial.println ("old 20rs");
        lcd.setCursor(0, 0);
        lcd.print("20 rupees");
        tmrpcm.setVolume(6);
        tmrpcm.play("20.wav");
        Servo11.write(90); 
        Servo12.write(0);
        Servo13.write(90);
        Servo14.write(0);      
        delay (2000);
        }
 else if ((red > 335 && green > 430 && blue > 340) &&( red < 355 && green < 450 && blue < 360  ))
       {
        Serial.println ("old 10rs");
        lcd.setCursor(0, 0);
        lcd.print("10 rupees");
        tmrpcm.setVolume(6);
        tmrpcm.play("10.wav");
        Servo11.write(90); 
        Servo12.write(0);
        Servo13.write(0);
        Servo14.write(0);
        delay (2000);
        }
 else if ((red > 240 && green > 360 && blue > 200) &&( red < 280 && green < 390 && blue < 230  ))
       {
        Serial.println ("new 2000rs");
        lcd.setCursor(0, 0);
        lcd.print("2000 rupees");
        tmrpcm.setVolume(6);
        tmrpcm.play("2000.wav");
        Servo11.write(90); 
        Servo12.write(90);
        Servo13.write(90);
        Servo14.write(90);
        delay (2000);
       } 
 else if ((red > 320 && green > 360 && blue > 280) &&( red < 380 && green < 430 && blue < 350 ))
       {
        Serial.println ("new 500rs");
        lcd.setCursor(0, 0);
        lcd.print("500 rupees");
        tmrpcm.setVolume(6);
        tmrpcm.play("500.wav");
        Servo11.write(90); 
        Servo12.write(90);
        Servo13.write(90);
        Servo14.write(0);
        delay (2000);
        }
        
 else if ((red > 220 && green > 320 && blue > 270) &&( red < 270 && green < 360 && blue < 310  ))
       {
        Serial.println ("new 200rs");
        lcd.setCursor(0, 0);
        lcd.print("200 rupees");
        tmrpcm.setVolume(6);
        tmrpcm.play("200.wav");
        Servo11.write(90); 
        Servo12.write(0);
        Servo13.write(0);
        Servo14.write(90);
       delay (2000);
       }
 else if ((red > 370 && green > 420 && blue > 260) &&( red < 450 && green < 500 && blue < 315  ))
       {
        Serial.println ("new 100rs");
        lcd.setCursor(0, 0);
        lcd.print("100 rupees");
        tmrpcm.setVolume(6);
        tmrpcm.play("100.wav");
        Servo11.write(90); 
        Servo12.write(90);
        Servo13.write(0);
        Servo14.write(90);
        delay (2000);
        }
 else if ((red > 430 && green > 410 && blue > 310) &&( red < 470 && green < 460 && blue < 360  ))
       {
        Serial.println ("new 50rs");
        lcd.setCursor(0, 0);
        lcd.print("50 rupees");
        tmrpcm.setVolume(6);
        tmrpcm.play("50.wav");
        Servo11.write(90); 
        Servo12.write(90);
        Servo13.write(0);
        Servo14.write(0);
        delay (2000);
       } 
 else if ((red > 490 && green > 630 && blue > 500) &&( red < 540 && green < 680 && blue < 540  ))
       {
        Serial.println ("new 10rs");
        lcd.setCursor(0, 0);
        lcd.print("10 rupees");
        tmrpcm.setVolume(6);
        tmrpcm.play("10.wav");
        Servo11.write(90); 
        Servo12.write(0);
        Servo13.write(0);
        Servo14.write(0);
       delay (2000);
       }
      Servo11.write(0); 
      Servo12.write(0);
      Servo13.write(0);
      Servo14.write(0);
}
else {  
    //  Serial.println ("fake note");
      lcd.setCursor(0, 0);
      lcd.print(" fake note");
      tmrpcm.setVolume(6);
      tmrpcm.play("f.wav");
      Servo11.write(0); 
      Servo12.write(90);
      Servo13.write(90);
      Servo14.write(90);
      delay(30000); 
     }

}
