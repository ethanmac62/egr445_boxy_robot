int Byte1 = 0, Byte2 = 0, Byte3 = 0, Byte4 = 0;
int Number1 = 0, Number2 = 0;
int data1 = 0;

void setup()                    // run once, when the sketch starts
{
  Serial.begin(115200);           // set up Serial library at 115200 bps  
  Serial.print("EGR 445 Serial Starting Point");  // prints welcome message
  Serial.print('\n');  // prints newline character
}

void loop()                       // run over and over again
{
  if (Serial.available() > 1) {
    Byte1 = Serial.read();
    Byte2 = Serial.read();
    Byte3 = Serial.read();
    Byte4 = Serial.read();
    Serial.print(Byte1);
    Serial.print(",");
    Serial.print(Byte2);
    Serial.print('\n');
    Serial.print(Byte3);
    Serial.print(",");
    Serial.print(Byte4);
    Serial.print('\n');
    Number1 = Byte1 * 256+Byte2;
    Number2 = Byte3 * 256+Byte4;
    Serial.print(Number1);
    Serial.print(",");
    Serial.print(Number2);
    Serial.print('\n');
    
    delay(100);
  }
}
