#include <Wire.h>


//int values[64]={};
int i=0;
bool status = true;
int time_begin;
int count = 5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();
  Serial.println("Setup");
  //delay(100);
  for (count; count>0; count--)
  {
    Serial.println(count);
    delay(1000);
  }
  int time_begin = millis();
  while(status){
        Serial.print("waiting...");
        Serial.println(i);
        i++;
        
        int time_end;
        Wire.beginTransmission(0x1A);
        Wire.write(0xA0);
        delay(2);
        Wire.requestFrom(0x1A,1);
        int get = 0;
        get = Wire.read();
        Wire.endTransmission(1);
        Serial.println(get);
        if(get == 1)
        {
                time_end = millis();
                Serial.println((time_end - time_begin),DEC);
                status = false;
        }
        delay(50);
  }
  Serial.println("Go to Loop...");
}
void loop() 
{
  while (Serial.available())
  {
    char mode = Serial.read();
    switch (mode)
    {
      case 'r':
      case 'R': if (Serial.available() > 0)
      {
        device = (int)Serial.read();
        offset = (int)Serial.read();
        numbers = (int)Serial.read();
        Serial.println(device,DEC);
        Serial.println(offset,DEC);
        Serial.println(numbers,DEC);
      }
    }
  }
}

