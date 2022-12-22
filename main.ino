#include <SoftwareSerial.h>
#include <string.h>

SoftwareSerial BTSerial(4, 5);

int IN1 = 2;
int IN2 = 3;

int IN3 = 6;
int IN4 = 7;

char data;

// int L_IR = 9;
// int R_IR = 8;

void setup()
{
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
    // pinMode(L_IR,INPUT);
    // pinMode(R_IR,INPUT);
    
    Serial.begin(9600);
    BTSerial.begin(9600);
}

void loop() 
{
  
  // int L_VAL = digitalRead(L_IR);
  // int R_VAL = digitalRead(R_IR);
   if (BTSerial.available()) {
    data = BTSerial.read();
    //strupr(data);
    
    Serial.write(data);
    if(data == 'E' || data == 'e') motor_forward(255);
  else if (data == 'F' || data == 'f') motor_left(255);
  else if (data == 'G' || data == 'g') motor_backward(255);
  else if (data == 'H' || data == 'h') motor_right(255);
  else if(data == 0)  motor_stop();
  }
    else data = '\0';
  
  // 시리얼 모니터로 부터 입력 받은 데이터를 블루투스로 송신한다.
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }

  
}

void motor_forward(int SpeedVal)
{
    analogWrite(IN1,0);
    analogWrite(IN2,SpeedVal);
    
    analogWrite(IN3,0);
    analogWrite(IN4,SpeedVal);
}

void motor_backward(int SpeedVal)
{
    analogWrite(IN1,SpeedVal);
    analogWrite(IN2,0);
    
    analogWrite(IN3,SpeedVal);
    analogWrite(IN4,0);
}

void motor_left(int SpeedVal)
{
    analogWrite(IN1,SpeedVal);
    analogWrite(IN2,0);
    
    analogWrite(IN3,0);
    analogWrite(IN4,SpeedVal);
}

void motor_right(int SpeedVal)
{
    analogWrite(IN1,0);
    analogWrite(IN2,SpeedVal);
    
    analogWrite(IN3,SpeedVal);
    analogWrite(IN4,0);
}

void motor_stop()
{
    analogWrite(IN1,0);
    analogWrite(IN2,0);
    
    analogWrite(IN3,0);
    analogWrite(IN4,0);
}
