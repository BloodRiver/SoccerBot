#include <Servo.h>

#define ENA            11
#define ENB            12
#define IN1             8
#define IN2             7
#define IN3             2
#define IN4             4
#define KICKER_SERVO    9

int motor_speed = 255;
int incomingByte = 0;
int angle = 90;

Servo kicker;

void left_motors_forward()
{
  analogWrite(ENA, motor_speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void left_motors_backward()
{
  analogWrite(ENA, motor_speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void right_motors_forward()
{
  analogWrite(ENB, motor_speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right_motors_backward()
{
  analogWrite(ENB, motor_speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void move_forward()
{
  left_motors_forward();
  right_motors_forward();
}


void move_backward()
{
  left_motors_backward();
  right_motors_backward();
}


void turn_left()
{
  left_motors_backward();
  right_motors_forward();
}


void turn_right()
{
  right_motors_backward();
  left_motors_forward();
}


void forward_left()
{
  right_motors_forward();
}


void forward_right()
{
  left_motors_forward();
}


void back_left()
{
  right_motors_backward();
}


void back_right()
{
  left_motors_backward();
}


void stop_moving()
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


void kick_left()
{
  while (angle-- > 0)
  {
    kicker.write(angle);
  }
}


void kick_right()
{
  while (angle++ < 180)
  {
    kicker.write(angle);
  }
}


void setup() {
  Serial.begin(9600);
  kicker.attach(KICKER_SERVO);
  kicker.write(angle);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void loop() {

    if (Serial.available() > 0)
    {
      incomingByte = Serial.read();
    }

    switch(incomingByte)
    {
       case 'S':
       {
         stop_moving();
         incomingByte='*';
         break;
       }
       case 'B':
       {
         move_backward();
         incomingByte='*';
         break;
       }
       case 'F':
       {
         move_forward();
         incomingByte='*';
         break;
       }
       case 'L':
       {
         turn_left();
         incomingByte='*';
         break;
       }
       case 'R':
       {
         turn_right();
         incomingByte='*';
         break;
       }
       case 'G':
       {
         forward_left();
         incomingByte='*';
         break;
       }
       case 'I':
       {
         forward_right();
         incomingByte='*';
         break;
       }
       case 'H':
       {
         back_left();
         incomingByte='*';
         break;
       }
       case 'J':
       {
         back_right();
         incomingByte='*';
         break;
       }
       case '1':
       {
         motor_speed = 20;
         incomingByte = '*';
         break;
       }
       case '2':
       {
         motor_speed = 40;
         incomingByte = '*';
         break;
       }
       case '3':
       {
         motor_speed = 60;
         incomingByte = '*';
         break;
       }
       case '4':
       {
         motor_speed = 80;
         incomingByte = '*';
         break;
       }
       case '5':
       {
         motor_speed = 100;
         incomingByte = '*';
         break;
       }
       case '6':
       {
         motor_speed = 120;
         incomingByte = '*';
         break;
       }
       case '7':
       {
         motor_speed = 140;
         incomingByte = '*';
         break;
       }
       case '8':
       {
         motor_speed = 160;
         incomingByte = '*';
         break;
       }
       case '9':
       {
         motor_speed = 200;
         incomingByte = '*';
         break;
       }
       case 'q':
       {
         motor_speed = 255;
         incomingByte = '*';
         break;
       }
       case 'w':
       {
         kick_left();
         incomingByte = '*';
         break;
       }
       case 'W':
       {
         angle = 90;
         kicker.write(angle);
         incomingByte = '*';
         break;
       }
       case 'e':
       {
         kick_right();
         incomingByte = '*';
         break;
       }
       case 'E':
       {
         angle = 90;
         kicker.write(angle);
         incomingByte = '*';
         break;
       }
     }
}
