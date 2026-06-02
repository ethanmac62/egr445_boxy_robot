#include <Servo.h>
int Byte1 = 0, Byte2 = 0, Byte3 = 0, Byte4 = 0, Byte5 = 0, Byte6 = 0, Byte 7= 0, Byte8 = 0;
int Number1 = 0, Number2 = 0;
int data1 = 0;

int inByte;
int myint, myint2, myint3, myint4;

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;// create servo object to control a servo
//Servo myservo2;  // create servo object to control a servo
// twelve servo objects can be created on most boards

void setup()
{
  Serial.begin(115200);

  Serial.print("single servo control over serial SS19");
  Serial.print("\n");

  myservo1.attach(6, 900, 2100);
  myservo1.attach(7, 900, 2100);
  myservo1.attach(8, 900, 2100);
  myservo1.attach(9, 900, 2100);// attaches to servo on pin 6
}


void loop()
{
  if (Serial.available() >= 8) {
    //your code here
    // get myint from serial as two byte integer, possibly within a case
    // once you have the int reassembled, send it to the servo:
    //int myint= Serial.parseInt();
    Byte1 = Serial.read();
    Byte2 = Serial.read();
    
    Byte3 = Serial.read();
    Byte4 = Serial.read();

    Byte5 = Serial.read();
    Byte6 = Serial.read();

    Byte7 = Serial.read();
    Byte8 = Serial.read();
    
    myint = makeInteger(Byte1, Byte2);
    myint2 = makeInteger(Byte3, Byte4);
    myint3 = makeInteger(Byte5, Byte6);
    myint4 = makeInteger(Byte7, Byte8);
    
    
    
    Serial.print(Byte1);
    Serial.print(",");
    Serial.print(Byte2);
    Serial.print('\n');
    Serial.print(myint);
    Serial.print('\n');

    Serial.print(Byte3);
    Serial.print(",");
    Serial.print(Byte4);
    Serial.print('\n');
    Serial.print(myint);
    Serial.print('\n');

    Serial.print(Byte5);
    Serial.print(",");
    Serial.print(Byte6);
    Serial.print('\n');
    Serial.print(myint);
    Serial.print('\n');

    Serial.print(Byte7);
    Serial.print(",");
    Serial.print(Byte8);
    Serial.print('\n');
    Serial.print(myint);
    Serial.print('\n');
    
    
    
    
    if (myint >= 1000 && myint <=2000){
      myservo1.writeMicroseconds(myint);
    }

    if (myint2 >= 1000 && myint2 <=2000){
      myservo2.writeMicroseconds(myint2);
    }

    if (myint3 >= 1000 && myint3 <=2000){
      myservo3.writeMicroseconds(myint3);
    }
    if (myint4 >= 1000 && myint4 <=2000){
      myservo4.writeMicroseconds(myint4);
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
