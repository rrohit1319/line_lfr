
int RS = D5;
int LS = D6;
int RMF = D1;
int LMF = D2;
int RMB = D3;
int LMB = D4;
int LL = D7;
int RL = D8;
void setup() {
pinMode (RS,INPUT);
pinMode (LS,INPUT);
pinMode (RMF,OUTPUT);
pinMode (LMF,OUTPUT);
pinMode (RMB,OUTPUT);
pinMode (LMB,OUTPUT);

pinMode (LL,OUTPUT);
pinMode (RL,OUTPUT);
}
void loop(){
RS = digitalRead (D5);
LS = digitalRead (D6);
if ((RS==1)&&(LS==1))
{
digitalWrite (RMF,LOW);
digitalWrite (RMB,LOW);
digitalWrite (LMF,LOW);
digitalWrite (LMB,LOW);

digitalWrite (LL,LOW);
digitalWrite (RL,LOW);


}
if ((RS==0)&&(LS==0))
{
digitalWrite (RMF,HIGH);
digitalWrite (LMF,HIGH);
digitalWrite (RMB,LOW);
digitalWrite (LMB,LOW);


digitalWrite (LL,HIGH);
digitalWrite (RL,HIGH);
}
if ((RS==1)&&(LS==0))
{
digitalWrite (RMF,LOW);
digitalWrite (LMF,HIGH);
digitalWrite (RMB,LOW);
digitalWrite (LMB,LOW);

digitalWrite (LL,HIGH);
digitalWrite (RL,LOW);
}
if ((RS==0)&&(LS==1))
{
digitalWrite (RMF,HIGH);
digitalWrite (LMF,LOW);
digitalWrite (RMB,LOW);
digitalWrite (LMB,LOW);

digitalWrite (LL,LOW);
digitalWrite (RL,HIGH);
}
}
