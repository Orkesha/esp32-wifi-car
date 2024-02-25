#include <SoftwareSerial.h>
SoftwareSerial ser(2, 3);
#include <Servo.h>
Servo srv1;
Servo srv2;
Servo srv3;
Servo srv4;

int last[4] = {90, 0, 180, 0};

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
srv1.write(last[0]);
srv2.write(last[1]);
srv3.write(last[2]);
srv4.write(last[3]);
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
      digitalWrite(m2, 0);
      digitalWrite(m3, 1);
      digitalWrite(m4, 0);
      delay(1000);
      digitalWrite(m1, 0);
      digitalWrite(m3, 0);
    }
    else{
      digitalWrite(m1, 1);
      digitalWrite(m2, 0);
      digitalWrite(m3, 1);
      digitalWrite(m4, 0);
    }
    break;
    case 'R':
      digitalWrite(m1, 1);
      digitalWrite(m2, 0);
      digitalWrite(m3, 0);
      digitalWrite(m4, 1);
      delay(1000);
      digitalWrite(m1, 0);
      digitalWrite(m4, 0);      
    break;
    case 'L':
      digitalWrite(m1, 0);
      digitalWrite(m2, 1);
      digitalWrite(m3, 1);
      digitalWrite(m4, 0);
      delay(1000);
      digitalWrite(m2, 0);
      digitalWrite(m3, 0);      
    break;
    case 'B':
    if(val == 0){
      digitalWrite(m1, 0);
      digitalWrite(m2, 1);
      digitalWrite(m3, 0);
      digitalWrite(m4, 1);
      delay(1000);
      digitalWrite(m2, 0);
      digitalWrite(m4, 0);
    }
    else{
      digitalWrite(m1, 0);
      digitalWrite(m2, 1);
      digitalWrite(m3, 0);
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
    val = map(val, 0, 100, 0, 180);
    if(val > last[0]){
    for(int i = last[0]; i<val+1; i++){
    srv1.write(i);
    delay(10);  
    }
    }
    else{
    for(int i = last[0]; i>val+1; i--){
    srv1.write(i);
    delay(10);  
    }
    }
    last[0] = val;
    break;
    case 'X':
    val = map(val, 0, 100, 0, 180);
    if(val > last[1]){
    for(int i = last[1]; i<val+1; i++){
    srv2.write(i);
    delay(10);  
    }
    }
    else{
    for(int i = last[1]; i>val+1; i--){
    srv2.write(i);
    delay(10);  
    }
    }
    last[1] = val;
    break;
    case 'C':
    val = map(val, 0, 100, 0, 180);
    if(val > last[2]){
    for(int i = last[2]; i<val+1; i++){
    srv3.write(i);
    delay(10);  
    }
    }
    else{
    for(int i = last[2]; i>val+1; i--){
    srv3.write(i);
    delay(10);  
    }
    }
    last[2] = val;
    break;
    case 'V':
    val = map(val, 0, 100, 0, 180);
    if(val > last[3]){
    for(int i = last[3]; i<val+1; i++){
    srv4.write(i);
    delay(10);  
    }
    }
    else{
    for(int i = last[3]; i>val+1; i--){
    srv4.write(i);
    delay(10);  
    }
    }
    last[3] = val;
    break;
  }
  }
}
