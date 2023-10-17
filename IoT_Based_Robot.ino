#define BLYNK_TEMPLATE_ID "TMPLd3ikGQbO"
#define BLYNK_TEMPLATE_NAME "IoT based Robot"
#define BLYNK_AUTH_TOKEN "13rCylQM3A1U7Iv8dICUgZMBP_nsdBz-"
// Motor A connections
//int enA = 9;
int in1 = 12;
int in2 = 14;
// Motor B connections
//int enB = 9;
int in3 = 27;
int in4 = 26;
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "impulsetech";
char pass[] = "impulse567";
BlynkTimer timer;


BLYNK_WRITE(V0)
{
  int switch0 = param.asInt(); // parameter as int 
  if(switch0 == HIGH)
  {    
      // for forward 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4, HIGH);
  delay(10);
  
   }  
  else
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    delay(10);
   }  
}

BLYNK_WRITE(V1)
{
  int switch1 = param.asInt(); // parameter as int 
  if(switch1 == HIGH)
  {    
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    delay(10);
    }  
  else
  {
     digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    delay(10);
    }  
}

BLYNK_WRITE(V2)
{
  int switch2 = param.asInt(); // parameter as int 
  if(switch2 == HIGH)
  {    
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    delay(10);
    }  
  else
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    delay(10);
    }  
}

BLYNK_WRITE(V3)
{
  int switch3 = param.asInt(); // parameter as int 
  if(switch3 == HIGH)
  {    
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    delay(10);
    }  
  else
  {
     digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    delay(10);
    }  
}

void setup() {

  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
   timer.run();
}
