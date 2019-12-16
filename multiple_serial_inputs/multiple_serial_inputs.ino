int data[3];
void setup() {
   Serial.begin(9600);

}

void loop() {
  if(Serial.available())
  {
 for(int i=0;i<3;i++)
 {
  data[i]=Serial.parseInt();
 }
  for(int i=0;i<3;i++)
 {
  Serial.println(data[i]);
 }
 
  }
}
