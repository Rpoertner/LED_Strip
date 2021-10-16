#include "FastLED.h"
#define NUM_LEDS 300
#define LED_DATA 4
#define MICROPHONE A5


CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_DATA, GRB>(leds, NUM_LEDS);
  pinMode(MICROPHONE, INPUT);
  Serial.begin(9600);
}

void loop() {

  int soundValue = analogRead(MICROPHONE);
  Serial.println(soundValue);

  if(soundValue >= 600){
    for(int i = 0; i < NUM_LEDS; ++i){
      leds[i] = CRGB::Blue;
      }
      FastLED.show();
      delay(300);
      for(int i = 0; i < NUM_LEDS; ++i){
      leds[i] = CRGB::Black;
      }
      FastLED.show();
      delay(300);
    }
 
}

void pulse(CRGB leds[]){
  
  
  }
