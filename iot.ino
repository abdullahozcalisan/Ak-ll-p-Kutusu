#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define TRIGGERPIN D1
#define ECHOPIN    D2

char auth[] = "5012b068753f4ef1a61a7f6e7b36c494";

char ssid[] = "İphone";
char pass[] = "bbbbbbbb";

WidgetLED green(V1);
WidgetLED orange(V2);
WidgetLED red(V3); 

void setup() {
  Serial.begin(9600);
pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Blynk.begin(auth, ssid, pass);

}

void loop()
{
 
  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration/2) / 29.1;
  int mesafe = int(distance);
  int thresh [3] = {20,12,4};
  
  Serial.print(mesafe);
  Blynk.run();
   if(distance<=thresh[0]&&distance>=thresh[1]&&distance>=thresh[2]){
    green.on();
    Serial.println(1);
    }
  else if(distance<=thresh[0]&&distance<=thresh[1]&&distance>=thresh[2]){
    green.on();
    orange.on();
    Serial.println(2);
  }
  else if(distance<=thresh[0]&&distance<=thresh[1]&&distance<=thresh[2]){
    green.on();
    orange.on();
    red.on();
    Serial.println(3);
  }
  else{
    green.off();
    orange.off();
    red.off();
    Serial.println(0);
  }
  delay(2500);

}
