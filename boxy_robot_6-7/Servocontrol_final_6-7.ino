#include <Servo.h>
int Byte1 = 0, Byte2 = 0, Byte3 = 0, Byte4 = 0;
int Number1 = 0, Number2 = 0;
int data1 = 0;
int inByte;
int myint, myint2;

Servo myservo1;
Servo myservo2;
Servo myservo3;
void setup()
{
  Serial.begin(115200);
  Serial.print("dual servo control over serial");
  Serial.print("\n");

  myservo1.attach(6, 900, 2100);
  myservo2.attach(7, 900, 2100);
  myservo3.attach(3, 900, 2100);
}

void loop()
{
/*
  myservo1.writeMicroseconds(1500);
  myservo2.writeMicroseconds(1000);
*/  
  myservo3.writeMicroseconds(1500);
  if (Serial.available() >= 4) {
    Byte1 = Serial.read();
    Byte2 = Serial.read();
    Byte3 = Serial.read();
    Byte4 = Serial.read();

    myint  = makeInteger(Byte1, Byte2);
    myint2 = makeInteger(Byte3, Byte4);

    // echo back bytes and reconstructed ints for servo 1
    Serial.print(Byte1);
    Serial.print(",");
    Serial.print(Byte2);
    Serial.print('\n');
    Serial.print(myint);
    Serial.print('\n');

    // echo back bytes and reconstructed ints for servo 2
    Serial.print(Byte3);
    Serial.print(",");
    Serial.print(Byte4);
    Serial.print('\n');
    Serial.print(myint2);
    Serial.print('\n');

    if (myint >= 1000 && myint <= 2000){
      myservo1.writeMicroseconds(myint);
    }
    if (myint2 >= 1000 && myint2 <= 2000){
      myservo2.writeMicroseconds(myint2);
    }
  }

  
}

int makeInteger(byte byt1, byte byt2){
  int NewInteger = byt1 * 256 + byt2;
  return NewInteger;
}
