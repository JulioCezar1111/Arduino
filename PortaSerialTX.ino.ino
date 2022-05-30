//sensores
#define U2 8
#define U3 9
#define U4 10
#define U5 11

//Lampadas
#define L1 16
#define L2 17

//Variaveis
String RxData;
int CanalA8, CanalA9, CanalA10, CanalA11;

//Metodos
void ConfigPlaca()
{
  pinMode(U2, INPUT);// LM35
  pinMode(U3, INPUT);// LM35
  pinMode(U4, INPUT);// LM35
  pinMode(U5, INPUT);// LM35
  
  pinMode(L1, OUTPUT);//SIST ON
  pinMode(L2, OUTPUT);// SIST OFF
  digitalWrite(L1,0);//SIST ON
  digitalWrite(L2,1); // SIST OFF
  Serial.begin(9600);
}

void RxControle()
{
  if(Serial.available() > 0)
  {
   RxData = Serial.readStringUntil('\r');
   
   if(RxData.indexOf("[SISTON]") != -1)
   {
    digitalWrite(L1,1);
    digitalWrite(L2,0);
   }

   if(RxData.indexOf("[SISTOFF]") != -1)
   {
    digitalWrite(L1,0);
    digitalWrite(L2,1);
   }
  }
}

void TxLM35()
{
  
  // LM35 resolução de 0,01V / Grau
  // AD resolução 0,004887V por word

  CanalA8 = analogRead(U2) * (0.004887 / 0.01);
  CanalA9 = analogRead(U3) * (0.004887 / 0.01);
  CanalA10 = analogRead(U4) * (0.004887 / 0.01);
  CanalA11 = analogRead(U5) * (0.004887 / 0.01);
  
  if(digitalRead(L1) == 1)
  {
    Serial.print(CanalA8);
    Serial.print(":");
    Serial.print(CanalA9);
    Serial.print(":");
    Serial.print(CanalA10);
    Serial.print(":");
    Serial.println(CanalA11);
    delay(100);
  } 
}

void setup() 
{
 ConfigPlaca();
}

void loop() 
{
 RxControle();
 TxLM35();  
}
