#include <SoftwareSerial.h>
SoftwareSerial ser(2, 3);
#include <Servo.h>
Servo srv1;
Servo srv2;
Servo srv3;
Servo srv4;


#define m1 4
#define m2 5
#define m3 6
#define m4 7

#define ser1 8
#define ser2 9
#define ser3 10
#define ser4 11


void setup() {
srv1.attach(ser1);
srv2.attach(ser2);
srv3.attach(ser3);
srv4.attach(ser4);
srv1.write(0);
srv2.write(0);
srv3.write(0);
srv4.write(0);
ser.begin(115200);
Serial.begin(115200);
pinMode(m1, OUTPUT);
pinMode(m2, OUTPUT);
pinMode(m3, OUTPUT);
pinMode(m4, OUTPUT);
}

void loop() {
  if(ser.available()){
    String data = ser.readStringUntil('\n');
    char comm = data.charAt(0);
    int val = data.substring(1).toInt();
  switch(comm){
    case 'F':
    if(val == 0){
      digitalWrite(m1, 1);
      digitalWrite(m2, 1);
      digitalWrite(m3, 0);
      digitalWrite(m4, 0);
      delay(1000);
      digitalWrite(m1, 0);
      digitalWrite(m2, 0);
    }
    else{
      digitalWrite(m1, 1);
      digitalWrite(m2, 1);
      digitalWrite(m3, 0);
      digitalWrite(m4, 0);
    }
    break;
    case 'R':
      digitalWrite(m1, 1);
      digitalWrite(m2, 0);
      digitalWrite(m3, 1);
      digitalWrite(m4, 0);
      delay(1000);
      digitalWrite(m1, 0);
      digitalWrite(m3, 0);      
    break;
    case 'L':
      digitalWrite(m1, 0);
      digitalWrite(m2, 1);
      digitalWrite(m3, 0);
      digitalWrite(m4, 1);
      delay(1000);
      digitalWrite(m2, 0);
      digitalWrite(m4, 0);      
    break;
    case 'B':
    if(val == 0){
      digitalWrite(m1, 0);
      digitalWrite(m2, 0);
      digitalWrite(m3, 1);
      digitalWrite(m4, 1);
      delay(1000);
      digitalWrite(m3, 0);
      digitalWrite(m4, 0);
    }
    else{
      digitalWrite(m1, 0);
      digitalWrite(m2, 0);
      digitalWrite(m3, 1);
      digitalWrite(m4, 1);
    }
    break;
    case 'S':
      digitalWrite(m1, 0);
      digitalWrite(m2, 0);
      digitalWrite(m3, 0);
      digitalWrite(m4, 0);
    break;
    case 'Z':
    srv1.write(val);
    break;
    case 'X':
    srv2.write(val);
    break;
    case 'C':
    srv3.write(val);
    break;
    case 'V':
    srv4.write(val);
    break;
  }
  }
}
