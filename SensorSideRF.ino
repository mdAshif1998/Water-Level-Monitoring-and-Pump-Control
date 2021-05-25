
#include <VirtualWire.h> //Load the library
#include <Wire.h> 


const int trigPin  = 5;
const int echoPin  = 6;
long duration;
int distance;
String str_distance;
String str_out;
int value = 0;
char *data;




void setup()
{
  vw_set_tx_pin(7);          // Sets pin D12 as the TX pin
  vw_setup(1000);          // Bits per sec
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  


  
}
void loop(){
   levelCheck();
  
   
  str_distance = String(distance);

  str_out = str_distance;
 
  static char *msg = str_out.c_str();
   vw_send((uint8_t *)msg, strlen(msg)); 
   vw_wait_tx();
  if(distance <= 19 && value == 0){
    delay(3000);
    if(distance <= 19 && value == 0){
     data = "a"; 
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(100);
    value = 1;
    }
  }
   /*else if(distance > 80){
    delay(3000);
    levelCheck();
    if(distance > 80){
    data="b";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(100);
    value = 0;
    }
  }*/
   delay(200);
  
}

void levelCheck(){
   digitalWrite(trigPin, LOW);
  delay(50);
  digitalWrite(trigPin, HIGH);
  delay(50);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/ 2;
  if(distance <19){
    distance = 0;
   }
  Serial.print("Distance: ");
  Serial.println(distance);
}
 
