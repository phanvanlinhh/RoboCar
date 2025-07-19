
#include <Servo.h>

#define pin_IN_1 4
#define pin_IN_2 5
#define pin_IN_3 6
#define pin_IN_4 7

#define pin_Servo_1 8
#define pin_Servo_2 9
#define pin_Servo_3 10
#define pin_Servo_4 11

Servo Servo_1;
Servo Servo_2;
Servo Servo_3;
Servo Servo_4;

int S1 = 1500;
int S2 = 1500;
int S3 = 1500;
int S4 = 1500;

int speed = 80;
int turn = 100;
int step = 50;
int stepMin = 1000;
int stepMax = 2000;

int mode = 0;
char rdata;
String data = "";

void setup(){
    Serial.begin(9600);

    pinMode(pin_IN_1, OUTPUT);
    pinMode(pin_IN_2, OUTPUT);
    pinMode(pin_IN_3, OUTPUT);
    pinMode(pin_IN_4, OUTPUT);

    Servo_1.attach(pin_Servo_1);
    Servo_2.attach(pin_Servo_2);
    Servo_3.attach(pin_Servo_3);
    Servo_4.attach(pin_Servo_4);

}


void MotorControll(int sp, int t){
    
    t *= turn;
    int leftSpeed = sp - t;
    int rightSpeed = sp + t;
    if( leftSpeed > 255 ) leftSpeed = 255;
    else if( leftSpeed < -255 ) leftSpeed = -255;
    if( rightSpeed > 255 ) rightSpeed = 255;
    else if( rightSpeed < -255 ) rightSpeed = -255;


    if(leftSpeed < 0){
        analogWrite(pin_IN_2,abs(leftSpeed));
        digitalWrite(pin_IN_1,0);
    }
    else {
        leftSpeed -= 255;
        analogWrite(pin_IN_2,abs(leftSpeed));
        digitalWrite(pin_IN_1,1);
    }
    if(rightSpeed < 0){
        analogWrite(pin_IN_3,abs(rightSpeed));
        digitalWrite(pin_IN_4,0);
    }
    else {
        rightSpeed -= 255;
        analogWrite(pin_IN_3,abs(rightSpeed));
        digitalWrite(pin_IN_4,1);
    }
}

void ArmControll(){
    Servo_1.writeMicroseconds(S1);
    Servo_2.writeMicroseconds(S2);
    Servo_3.writeMicroseconds(S3);
    Servo_4.writeMicroseconds(S4); 
}

void mode_0(String dt){
    if(dt == "0") MotorControll(0,0);
    else if(dt == "W") MotorControll(speed,0);
    else if(dt == "4") MotorControll(speed,1); 
    else if(dt == "S") MotorControll(-speed,0);
    else if(dt == "2") MotorControll(speed,-1);
}

void mode_1(String dt){
    if(dt == "0"){    }
    else if(dt == "2"){
        S1 +=step;
        if(S1 > stepMax) S1 = stepMax;
    }
    else if(dt == "4"){
        S1 -=step;
        if(S1 < stepMin) S1 = stepMin;
    }
    else if(dt == "1"){
        S2 +=step;
        if(S2 > stepMax) S2 = stepMax;
    }
    else if(dt == "3"){
        S2 -=step;
        if(S2 < stepMin) S2 = stepMin;
    }
    else if(dt == "S"){
        S3 +=step;
        if(S3 > stepMax) S3 = stepMax;
    }
    else if(dt == "W"){
        S3 -=step;
        if(S3 < stepMin) S3 = stepMin;
    }
    else if(dt == "A") {
        S4 +=step;
        if(S4 > stepMax) S4 = stepMax;
    }
    else if(dt == "D") {
        S4 -=step;
        if(S4 < stepMin) S4 = stepMin;
    }
}

void ReadBluetooth(){
    if(Serial.available()){
        rdata = Serial.read();
        if (rdata == '\n') {
            Serial.println(data);
            if(data =="Off") mode = 0;
            else if(data == "On")mode = 1;
            if(mode == 0) mode_0(data);
            if(mode == 1) mode_1(data);

            data= "";
        }
        else data = data + rdata;
    }
}

void loop(){
    ReadBluetooth();
    ArmControll();
}
