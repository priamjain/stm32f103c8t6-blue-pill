#include <EEPROM.h>
int data[3];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{
  for(int i=0;i<3;i++)
  {
    data[i]=Serial.parseInt();
  }
  switch(data[0])
  {
  case 1:
  EEPROM.write(data[1],data[2]);
  Serial.println(EEPROM.read(data[0]));
  break;
  
  case 2:
  int val = EEPROM.read(data[1]);
  Serial.println(val);
  break;
  } 
}
}
