#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sys/time.h"
#include "sdkconfig.h"
#include "esp_deep_sleep.h"
#include <WiFi.h>

#define GPIO_DEEP_SLEEP_DURATION     10  // sleep 10 seconds and then wake up
#define LED_PIN                      2

RTC_DATA_ATTR static time_t last;        // remember last boot in RTC Memory

void setup(){
  
}

void loop() {
  WiFi.mode(WIFI_OFF);
  btStop(); // btStart();
  struct timeval now;
  pinMode(LED_PIN, OUTPUT);      // set the LED pin mode
  printf("Starting ESP32 after deep-sleep\n");
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  gettimeofday(&now, NULL);
  printf("deep sleep (%lds since last reset, %lds since last boot)\n",now.tv_sec,now.tv_sec-last);
  last = now.tv_sec;
  esp_deep_sleep(1000000LL * GPIO_DEEP_SLEEP_DURATION);
}

