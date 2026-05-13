#include "esp_sleep.h"

#define BUTTON_PIN 18 //definiranje pina za tipkalo 
#define LED_PIN 2 //definiranje pina za led 


RTC_DATA_ATTR int wakeCount = 0; //definiranje rtc memorije

void setup() {
  Serial.begin(115200); //pokretanje serial monitora
  delay(500); 

  pinMode(LED_PIN, OUTPUT); //led izlaz
  pinMode(BUTTON_PIN, INPUT_PULLUP); //tipkalo ulaz

  wakeCount++; 
  Serial.print("Probudio se: ");
  Serial.println(wakeCount);

  Serial.println("Cekam klik tipke...");

  //sustav čeka klik
  while (digitalRead(BUTTON_PIN) == HIGH) {
  }

  delay(200); 

  Serial.println("Tipka pritisnuta → radim...");
  //led blinka 10 puta
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);
    delay(300);
  }

  Serial.println("Zavrseno → idem u sleep");
  
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_18, 0); //probudi se kad se nešto dogodi na pinu 18

  delay(500);
  esp_deep_sleep_start();
}

void loop() {
  // ne koristi se
}
