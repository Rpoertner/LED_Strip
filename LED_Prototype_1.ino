#include "FastLED.h"
#define NUM_LEDS 300
#define LED_DATA 4
#define MICROPHONE A5
#define PI 3.14

CRGB leds[NUM_LEDS];
//sudo chmod a+rw /dev/ttyUSB0

void setup() {
  FastLED.addLeds<WS2812B, LED_DATA, GRB>(leds, NUM_LEDS);
  pinMode(MICROPHONE, INPUT);
  Serial.begin(9600);
}

void loop() {

  int soundValue = analogRead(MICROPHONE);
  Serial.println(soundValue);

  /**if(soundValue >= 500){
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
    }**/
    
    pulse();
    //colorWave();
    //fountainPulse();
}

void pulse(){
  for(int offset = 0; offset < 5; ++offset){
    for(int i = 0; i < NUM_LEDS; i = i + 5){
      if(offset == 0){
        leds[i] = CHSV(171, 255, cos8(0));
        leds[i+1] = CHSV(171, 255, cos8(255/10));
        leds[i+2] = CHSV(171, 255, cos8(255/5));
        leds[i+3] = CHSV(171, 255, cos8((3*255)/10));
        leds[i+4] = CHSV(171, 255, cos8((2*255)/5));
      }
      else{
        CRGB temp = leds[i];
        leds[i] = leds[i + 4];
        leds[i + 4] = leds[i + 3];
        leds[i+3] = leds[i+2];
        leds[i +2] = leds[i+1];
        leds[i+1] = temp;
      }
    }
    FastLED.show();
    delay(95);
  }
}

void colorWave(){

    for(int i = 0; i <=255; ++i){
      for(int k = 0; k < NUM_LEDS; ++k){
        leds[k] = CHSV(i, 255, 255);
      }
      FastLED.show();
      delay(1000);
    }
  
}

void fountainPulse(){

  for(int i = 0; i < NUM_LEDS; i++){
      
      leds[i] = CRGB::Red;
  }


  int fullsender = 255 /5;  
  for(int offset = 0; offset < 5; ++offset){
    for(int i = 0; i < NUM_LEDS-5; ++i){
      
      leds[i].fadeLightBy(fullsender * (offset + 1));
    }
    FastLED.show();
    delay(200);
  }
}  
  
