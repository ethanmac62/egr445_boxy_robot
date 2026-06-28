#include <Servo.h>
int Byte1 = 0, Byte2 = 0, Byte3 = 0, Byte4 = 0,  Byte5 = 0, Byte6 = 0, Byte7 = 0, Byte8 = 0, Byte9 = 0, Byte10 = 0;
int data1 = 0;
int inByte;
int myint, myint2, myint3, myint4, myint5;
int DELAY = 300;

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
void setup()
{
  Serial.begin(115200);
  Serial.print("dual servo control over serial");
  Serial.print("\n");

  // initialize servos
  myservo1.attach(5, 900, 2100);
  myservo2.attach(6, 900, 2100);
  myservo3.attach(7, 900, 2100);
  myservo4.attach(8, 900, 2100);
  myservo5.attach(9, 900, 2100);

  // start in home position
  myservo1.writeMicroseconds(1500);
  myservo2.writeMicroseconds(1500); 
  myservo3.writeMicroseconds(1500);
  myservo4.writeMicroseconds(1500);
  myservo5.writeMicroseconds(1500);

}

// program takes two arm positions at a time 
void loop()
{
  if (Serial.available() >= 10) {// if the serial has 6 bytes available enter in
    Byte1 = Serial.read();// if the serial has 6 bytes available enter in
    Byte2 = Serial.read();
    Byte3 = Serial.read();
    Byte4 = Serial.read();
    Byte5 = Serial.read();
    Byte6 = Serial.read();
    Byte7 = Serial.read();
    Byte8 = Serial.read();
    Byte9 = Serial.read();
    Byte10 = Serial.read();

    // combine bites into servo values
    myint  = makeInteger(Byte1, Byte2);
    myint2 = makeInteger(Byte3, Byte4);
    myint3 = makeInteger(Byte5, Byte6);
    myint4 = makeInteger(Byte7, Byte8);
    myint5 = makeInteger(Byte9, Byte10);


    Serial.print("My int: ");
    Serial.print(myint);
    Serial.print('\n');

    Serial.print("My int2: ");
    Serial.print(myint2);
    Serial.print('\n');
    
    Serial.print("My int3: ");
    Serial.print(myint3);
    Serial.print('\n');

    Serial.print("My int4: ");
    Serial.print(myint4);
    Serial.print('\n');

    Serial.print("My int5: ");
    Serial.print(myint5);
    Serial.print('\n');
 
    // if the value is valid, move there
    // first servo
    if (myint >= 1000 && myint <= 2000){
      myservo1.writeMicroseconds(myint);
    }

    // second servo
    if (myint2 >= 1000 && myint2 <= 2000){
      myservo2.writeMicroseconds(myint2);
    }

     // third servo 
    if (myint3 >= 1000 && myint3 <= 2000){
      myservo3.writeMicroseconds(myint3);
    }
    
     // fourth servo 
    if (myint4 >= 1000 && myint4 <= 2000){
      myservo4.writeMicroseconds(myint4);
    }
    
    // fifth servo 
    if (myint5 >= 1000 && myint5 <= 2000){
      myservo5.writeMicroseconds(myint5);
    }
    
    delay(DELAY);
    Serial.println("Ready");//Signifies to python that it is ready for python to continue iterating through the for loop
    Serial.print('\n');

  }
}
int makeInteger(byte byt1, byte byt2){
  int NewInteger = byt1 * 256 + byt2;
  return NewInteger;
}
