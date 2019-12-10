#define pwm PA6
#define dir PB4
#define fb PA7
volatile long count = 0;
long reqcount =0;
boolean flag=HIGH;
int x;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pwm,PWM);
pinMode(dir,OUTPUT);
pinMode(fb,INPUT);
attachInterrupt(digitalPinToInterrupt(fb),enc,FALLING);
pwmWrite(pwm,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(count);
  
  if(Serial.available())
  {
    x=Serial.parseInt();
    reqcount=x*1365;
    flag=1;
  }
  
  if(reqcount==count )
  {
    Serial.println("loop1");
    pwmWrite(pwm,0);
    
  }
  else if(reqcount>count) //&& flag==1)
  { digitalWrite(dir,HIGH); 
    Serial.println("loop2");
    pwmWrite(pwm,30000);
    //digitalWrite(dir,HIGH); 
    while(reqcount>count){Serial.println(count);}
    pwmWrite(pwm,0);
    ///flag=0; 
  }
  else if(reqcount<count) //&& flag==1)
  { digitalWrite(dir,LOW);
    Serial.println("loop3");
    pwmWrite(pwm,30000);
    //digitalWrite(dir,LOW);
    while(reqcount<count){Serial.println(count);}
    pwmWrite(pwm,0);
   // flag=0;
  

}
}

void enc()
{
  if(digitalRead(dir))
  count++;
  else
  count--;
}
