#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


int LDR1 = 13;
int LDR2 = 15;
int Aprev = 0;
int Bprev = 0;
int relay1 = 14;
int relay2 = 12;
int count = 0;
int LDR1Value = 1;
int LDR2Value = 1;

char auth[] = "B-I9lSS9kWWymZjjgZ_aRWQnElC49fYG";
char ssid[] = "Automated Smart Living";
char pass[] = "ruetipe15";

  
void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

}

void loop() {
  Blynk.run();
  LDR1Value = digitalRead(LDR1);
  LDR2Value = digitalRead(LDR2);
  /*Serial.print(LDR1Value);
    Serial.print("    ");
    Serial.print(LDR2Value);
    Serial.println();
  */

  if ((Aprev == 1) && (Bprev == 1)) {

    if ((LDR1Value == 0) && (LDR2Value == 1)) {
      count = count + 1;
      Serial.print("Count: ");
      Serial.print(count);
      Serial.println();
    }
    else if ((LDR1Value == 1) && (LDR2Value == 0)) {
      count = count - 1;
      Serial.print("Count: ");
      Serial.print(count);
      Serial.println();
    }
  }
  /*if ((count >= 1) && (count <= 5)) {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, HIGH);
    }
    if (count >= 6) {
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);*/

  if (count <= 0) {
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
  }

  Blynk.virtualWrite(V1, count);
  


  Aprev = LDR1Value;
  Bprev = LDR2Value;



  delay(4);

}


