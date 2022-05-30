// INCLUSÃO DE BIBLIOTECAS
#include <SoftwareSerial.h>
#include <Servo.h>

// DEFINIÇÕES DE PINOS
#define pinRx 8
#define pinTx 9

#define M1A 2
#define M1B 3
#define M2A 4
#define M2B 7
#define ENA 5
#define ENB 6

#define pinServo 10

// DEFINIÇÕES
#define LIGADO HIGH
#define DESLIGADO LOW

// INSTANCIANDO OBJETOS
SoftwareSerial btSerial(pinRx, pinTx); // RX, TX
Servo s;

// DECLARAÇÃO DE VARIÁVEIS
char comando;
int pos;

// IMPLEMENTO DE FUNÇÕES

void moveFrente(){
  digitalWrite(M1A, 1);
  digitalWrite(M1B, 0);

  digitalWrite(M2A, 1);
  digitalWrite(M2B, 0);
}

void frenteDireita(){
  digitalWrite(M1A, 1);
  digitalWrite(M1B, 0);

  digitalWrite(M2A, 0);
  digitalWrite(M2B, 0);
}

void frenteEsquerda(){
  digitalWrite(M1A, 1);
  digitalWrite(M1B, 0);

  digitalWrite(M2A, 0);
  digitalWrite(M2B, 1);
}

void moveRe(){
  digitalWrite(M1A, 0);
  digitalWrite(M1B, 1);

  digitalWrite(M2A, 0);
  digitalWrite(M2B, 1);
}

void reDireita(){
  digitalWrite(M1A, 0);
  digitalWrite(M1B, 1);

  digitalWrite(M2A, 1);
  digitalWrite(M2B, 0);
}

void reEsquerda(){
  digitalWrite(M1A, 0);
  digitalWrite(M1B, 1);

  digitalWrite(M2A, 0);
  digitalWrite(M2B, 1);
}

void direita(){
  digitalWrite(M1A, 0);
  digitalWrite(M1B, 0);

  digitalWrite(M2A, 1);
  digitalWrite(M2B, 0);
}

void esquerda(){
  digitalWrite(M1A, 0);
  digitalWrite(M1B, 0);

  digitalWrite(M2A, 0);
  digitalWrite(M2B, 1);
}

void parar(){
  digitalWrite(M1A, 0);
  digitalWrite(M1B, 0);

  digitalWrite(M2A, 0);
  digitalWrite(M2B, 0);
}

void LigarServoMotor()
{
  s.write(150);
  delay(500);
  s.write(85);
}

void PararServoMotor()
{
  delay(10);
  s.write(85);
  delay(10);
}

void setup() 
{
  Serial.begin(9600);
  btSerial.begin(9600);

  s.attach(pinServo);
  s.write(85);

  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, 100);
  analogWrite(ENB, 100);



  Serial.println("Fim Setup");
  delay(2000);
}

void loop() 
{
  
  if (btSerial.available() > 0)
  {
   comando = btSerial.read(); 
   switch (comando) 
   {
    case 'F': 
      
        moveFrente();
        break;
      
    case 'I': 
      
        frenteDireita();
        break;
      
    case 'G': 
      
        frenteEsquerda();
        break;
      
    case 'R': 
      
        direita();
        break;
      
    case 'L': 
      
        esquerda();
        break;
      
    case 'B': 
      
        moveRe();
        break;
      
    case 'H': 
      
        reEsquerda();
        break;
      
    case 'J': 
      
        reDireita();
        break;
    case 'A':
        LigarServoMotor();  
    default:   
      parar();
      PararServoMotor();
      break;
   }
  }
}


