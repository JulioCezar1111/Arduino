#define IN1 13
#define IN2 12
#define IN3 11
#define IN4 10
#define AN0 0
#define AN1 1

void ConfigPlaca()
{
pinMode(AN0, INPUT);
pinMode(AN1, INPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
digitalWrite(IN1, 0);
digitalWrite(IN2, 0);
digitalWrite(IN3, 0);
digitalWrite(IN4, 0);
}

void ControleMotor()
{
if(analogRead(AN0) >= 800 && analogRead(AN1) >= 800)
{
digitalWrite(IN1, 1);
digitalWrite(IN2, 0);
digitalWrite(IN3, 1);
digitalWrite(IN4, 0);
}
if(analogRead(AN0) >= 800 && analgogRead(AN1) <=200)
{
digitalWrite(IN1, 1);
digitalWrite(IN2, 0);
digitalWrite(IN3, 0);
digitalWrite(IN4, 1);
}
if(analogRead(AN0) <= 200 && analogRead(AN1) >= 800)
{
digitalWrite(IN1, 0);
digitalWrite(IN2, 1);
digitalWrite(IN3, 1);
digitalWrite(IN4, 0);
}
}

void setup()
{
ConfigPlaca();
}

void loop()
{
ControleMotor();
}
