
#define LEDBreath 11

void setup() {
  // put your setup code here, to run once:
pinMode(LEDBreath, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
        //
        for (int value = 1 ; value < 255; value++){  
                analogWrite(LEDBreath, value);
                delay(7);
        }
        for (int value = 255; value >1; value--){  
                analogWrite(LEDBreath, value);  
                delay(7);  
        }  
}
