#include <VirtualWire.h>
#include <SoftwareSerial.h>
 
SoftwareSerial nodemcu(2,3);
const int relay = 4;
char msg[40];
int i;
String cdata;
/*const int relay1 = 5;
const int relay2 = 6;
const int relay4 = 7;*/
void setup()
{
  Serial.begin(9600); 
  nodemcu.begin(115200);
  pinMode(relay, OUTPUT);
  /*pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay4, OUTPUT);*/
  digitalWrite(relay,LOW);
  /*digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
  digitalWrite(relay4,LOW);*/
  vw_set_rx_pin(7);       //Sets pin D12 as the RX Pin
    vw_setup(1000);       // Bits per sec
    vw_rx_start();   
  
  }
void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; 
if (vw_get_message(buf, &buflen))
    {
        for (i = 0; i < buflen; i++)
         {
          msg[i] = char(buf[i]);
           //lcd.write(buf[i]); 
          //Serial.print(buf[i]);        
         }
          msg[buflen] = '\0';
          Serial.println(msg);
          cdata = msg;
          Serial.println(cdata); 
          nodemcu.println(cdata);
          cdata = "";         
      
      if(buf[0]=='a')
      {  
        digitalWrite(relay, HIGH);
        /*digitalWrite(relay1, HIGH);
        digitalWrite(relay2, HIGH);
        digitalWrite(relay4, HIGH);
        digitalWrite(relay4, LOW);*/
        
      } 
       else
      {
       digitalWrite(relay, LOW);
       /*digitalWrite(relay1, LOW);
       digitalWrite(relay2, LOW);
       delay(2000);
       digitalWrite(relay, HIGH);
       digitalWrite(relay1, HIGH);
       digitalWrite(relay2, HIGH);
       delay(10000);
       digitalWrite(relay4, LOW);*/
       
      }
      
    
}
} 
