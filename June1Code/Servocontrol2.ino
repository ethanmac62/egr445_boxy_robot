#include <Servo.h>
int Byte1 = 0, Byte2 = 0, Byte3 = 0, Byte4 = 0;
int Number1 = 0, Number2 = 0;
int data1 = 0;

int inByte;
int myint;

Servo myservo1;  // create servo object to control a servo
//Servo myservo2;  // create servo object to control a servo
// twelve servo objects can be created on most boards

void setup()
{
  Serial.begin(115200);

  Serial.print("single servo control over serial SS19");
  Serial.print("\n");

  myservo1.attach(7, 900, 2100);  // attaches to servo on pin 6
}


void loop()
{
  if (Serial.available() >= 2) {
    //your code here
    // get myint from serial as two byte integer, possibly within a case
    // once you have the int reassembled, send it to the servo:
    //int myint= Serial.parseInt();
    Byte1 = Serial.read();
    Byte2 = Serial.read();
    myint = makeInteger(Byte1, Byte2);
    Serial.print(Byte1);
    Serial.print(",");
    Serial.print(Byte2);
    Serial.print('\n');
    Serial.print(myint);
    Serial.print('\n');
    if (myint >= 1000 && myint <=2000){
      myservo1.writeMicroseconds(myint);
    }
    //Serial.print(myint);
    //Byte1 = Serial.read();
    //Byte2 = Serial.read();
    //myint = makeInteger(Byte1, Byte2);
    //myservo1.writeMicroseconds(myint);
  }
}
int makeInteger(byte byt1, byte byt2){
   int NewInteger = byt1 *256+byt2;
   return NewInteger;
}
