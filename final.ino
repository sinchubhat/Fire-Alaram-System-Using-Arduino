
const int BUZZ=7;

void setup() {
  Serial.begin(9600);
 pinMode(A3,INPUT);
 pinMode(A0,INPUT);
 pinMode(BUZZ,OUTPUT);
 pinMode(4,OUTPUT);
  }

void loop() 
{
  int f=analogRead(A3);
  int c=analogRead(A0);
  if((f<40)|| (c>400))
  {
    digitalWrite(BUZZ,HIGH);
    digitalWrite(4,HIGH);
    Serial.println("high");
    tone(BUZZ, 1000);
    Serial.println(f);
    Serial.println(c);
    SendSMS();
  }
  else
  {
   digitalWrite(BUZZ,LOW);
   Serial.println("LOW");
   Serial.println(f);
   noTone(BUZZ);}
   digitalWrite(4,LOW);
}
void SendSMS()
{Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(1000);
  Serial.println("AT+CMGS=\"+919538917997\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("Fire at https://www.google.co.in/maps/place/Ramaiah+Institute+of+Technology/@13.03096,77.5649075,15z/data=!4m5!3m4!1s0x0:0x6075bd8d8aed97ab!8m2!3d13.03096!4d77.5649075 rush immediately");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(1000);exit (0);
}
