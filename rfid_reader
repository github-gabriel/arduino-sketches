#include <MFRC522.h>
#include <SPI.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

int GREEN_LED = 4;
int RED_LED = 3;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}


void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if (!mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  if (content.substring(1) == "79 C4 C8 7E") 
  {
    Serial.println("Authorized Access");
    digitalWrite(GREEN_LED, HIGH);
  }
  else{
    Serial.println("Access Denied");
    digitalWrite(RED_LED, HIGH);
  }
  delay(1000);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
}
