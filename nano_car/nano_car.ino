#include <Servo.h>
Servo servo;


#define min1
#define min2
#define min3
#define min4

#define atri
#define rela
#define pomo
#define pomi
#define serv

#define mou1
#define mou2
#define mou3
#define mou4

#define led1
#define led2
#define sen1
#define sen2
#define sen3



void setup(){
  pinMode(min1, INPUT);
  pinMode(min2, INPUT);
  pinMode(min3, INPUT);
  pinMode(min4, INPUT);

  pinMode(atri, INPUT);
  pinMode(rela, OUTPUT);
  pinMode(pomo, OUTPUT);
  pinMode(pomi, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sen1, INPUT);
  pinMode(sen2, INPUT);
  pinMode(sen3, INPUT);
  

  pinMode(mou1, OUTPUT);
  pinMode(mou2, OUTPUT);
  pinMode(mou3, OUTPUT);
  pinMode(mou4, OUTPUT);
  
}

unsigned long dela = 0;
int state = 1;

void loop(){
if(millis() - dela > 500){
  state +=1;
  if(state > 8){
    state = 1;
  }
  if(state == 1 or state == 3){
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
  }
  if(state == 2 or state == 4 or state == 6 or state == 8){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
  }
  if(state == 5 or state == 7){
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
  }
}
if(digitalRead(atri) == 0){
  digitalWrite(mou1, digitalRead(min1));
  digitalWrite(mou2, digitalRead(min2));
  digitalWrite(mou3, digitalRead(min3));
  digitalWrite(mou4, digitalRead(min4));  

  digitalWrite(pomo, digitalRead(pomi));
  digitalWrite(rela, 0);
}
if(digitalRead(atri) == 1){
int sensor1 = analogRead(sen1);
int sensor2 = analogRead(sen2);
int sensor3 = analogRead(sen3);
if(sensor1 > sensor2 and sensor1 > sensor3){
  servo.write();
}
if(sensor2 > sensor1 and sensor2 > sensor3){
  servo.write();
}
if(sensor3 > sensor2 and sensor3 > sensor1){
  servo.write();
}
}
}
