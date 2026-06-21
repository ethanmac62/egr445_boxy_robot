#include <Servo.h>
int Byte1 = 0, Byte2 = 0, Byte3 = 0, Byte4 = 0,  Byte5 = 0, Byte6 = 0;
int Number1 = 0, Number2 = 0;
int data1 = 0;
int inByte;
int myint, myint2, myint3, myint4;

Servo myservo1;
Servo myservo2;
Servo myservo3;
void setup()
{
  Serial.begin(115200);
  Serial.print("dual servo control over serial");
  Serial.print("\n");

  // initialize servos
  myservo1.attach(5, 900, 2100);
  myservo2.attach(6, 900, 2100);
  myservo3.attach(7, 900, 2100);
//  myservo4.attach(8, 900, 2100);
//  myservo5.attach(9, 900, 2100);

  // start in home position
  myservo1.writeMicroseconds(1500);
  myservo2.writeMicroseconds(1500); 
  myservo3.writeMicroseconds(1500);
}

// program takes two arm positions at a time 
void loop()
{
/*
  myservo1.writeMicroseconds(1500);
  myservo2.writeMicroseconds(1500); 
  myservo3.writeMicroseconds(1500);
*/

  if (Serial.available() >= 12) {// if the serial has 8 bytes available enter in
    Byte1 = Serial.read();// if the serial has 12 bytes available enter in
    Byte2 = Serial.read();
    Byte3 = Serial.read();
    Byte4 = Serial.read();
    Byte5 = Serial.read();
    Byte6 = Serial.read();


    // combine bites into servo values
    myint  = makeInteger(Byte1, Byte2);
    myint2 = makeInteger(Byte3, Byte4);
    myint3 = makeInteger(Byte5, Byte6);

    Serial.print("My int: ");
    Serial.print(myint);
    Serial.print('\n');

    Serial.print("My int2: ");
    Serial.print(myint2);
    Serial.print('\n');
    
    Serial.print("My int3: ");
    Serial.print(myint3);
    Serial.print('\n');

 
    // if the value is valid, move there
    // first servo
    if (myint >= 1000 && myint <= 2000){
      myservo1.writeMicroseconds(myint);
    }
    delay(300);

    // second servo
    if (myint2 >= 1000 && myint2 <= 2000){
      myservo2.writeMicroseconds(myint2);
    }
    delay(300);

     // third servo 
     if (myint3 >= 1000 && myint3 <= 2000){
      myservo1.writeMicroseconds(myint3);
    
    delay(300);//The second point is the important point, the first servo movement is to an intermediate point
    Serial.println("Ready");//Signifies to python that it is ready for python to continue iterating through the for loop
    Serial.print('\n');
    
  }

}
}
int makeInteger(byte byt1, byte byt2){
  int NewInteger = byt1 * 256 + byt2;
  return NewInteger;
}
