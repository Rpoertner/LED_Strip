#include "FastLED.h"
#define NUM_LEDS 300
#define LED_DATA 4
#define MICROPHONE A5
#define PI 3.14

CRGBArray<NUM_LEDS> leds;
//sudo chmod a+rw /dev/ttyUSB0

void setup() {
  FastLED.addLeds<WS2812B, LED_DATA, GRB>(leds, NUM_LEDS);
  pinMode(MICROPHONE, INPUT);
  Serial.begin(9600);
}

void loop() {

  int soundValue = analogRead(MICROPHONE);
  Serial.println(soundValue);

   if(soundValue >= 500){
    fountainPulse();
    FastLED.show(); 
   }
    
    //pulse();
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

  int stage0 = 255/5;
  int stage1 = (2*255)/5;
  int stage2 = (3*255)/5;
  int stage3 = (4*255)/5;
  int stage4 = 255;

  for(int i = 0; i < 14; ++i){
    for(int k = 4; k < NUM_LEDS; k = k + 10){

      if(i == 0){
          leds[k] = CHSV(255, 255, stage0);
          leds[k-1]= CRGB::Black;
          leds[k-2]= CRGB::Black;
          leds[k-3]= CRGB::Black;
          leds[k-4]= CRGB::Black;
      }
      else if(i == 1){
          leds[k]= CHSV(255, 255, stage1);
          leds[k-1]= CHSV(255, 255, stage0);
          leds[k-2]=CRGB::Black;
          leds[k-3]=CRGB::Black;
          leds[k-4]=CRGB::Black;
      }
      else if(i == 2){
          leds[k]= CHSV(255, 255, stage2);
          leds[k-1]= CHSV(255, 255, stage1);
          leds[k-2]= CHSV(255, 255, stage0);
          leds[k-3]=CRGB::Black;
          leds[k-4]=CRGB::Black;
      }
      else if(i == 3){
          leds[k]= CHSV(255, 255, stage3);
          leds[k-1]= CHSV(255, 255, stage2);
          leds[k-2]= CHSV(255, 255, stage1);
          leds[k-3]= CHSV(255, 255, stage0);
          leds[k-4]=CRGB::Black;
      }
      else if(i == 4){
         leds[k]= CHSV(255, 255, stage4);
          leds[k-1]= CHSV(255, 255, stage3);
          leds[k-2]= CHSV(255, 255, stage2);
          leds[k-3]= CHSV(255, 255, stage1);
          leds[k-4]= CHSV(255, 255, stage0);
      }
      else if(i == 5){
          leds[k] =CHSV(255, 255, stage3);
          leds[k-1]= CHSV(255, 255, stage4);
          leds[k-2] =CHSV(255, 255, stage3);
          leds[k-3] =CHSV(255, 255, stage2);
          leds[k-4] =CHSV(255, 255, stage1);
      }
      else if(i == 6){
          leds[k] =CHSV(255, 255, stage2);
          leds[k-1] =CHSV(255, 255, stage3);
          leds[k-2] =CHSV(255, 255, stage4);
          leds[k-3] =CHSV(255, 255, stage3);
          leds[k-4] =CHSV(255, 255, stage2);
      }
      else if(i == 7){
          leds[k] =CHSV(255, 255, stage1);
          leds[k-1]= CHSV(255, 255, stage2);
          leds[k-2]= CHSV(255, 255, stage3);
          leds[k-3]= CHSV(255, 255, stage4);
          leds[k-4]= CHSV(255, 255, stage3);
      }
      else if(i == 8){
        leds[k]= CHSV(255, 255, stage0);
          leds[k-1]= CHSV(255, 255, stage1);
          leds[k-2]= CHSV(255, 255, stage2);
          leds[k-3] =CHSV(255, 255, stage3);
          leds[k-4]= CHSV(255, 255, stage4);
      }
      else if(i == 9){
          leds[k]=CRGB::Black;
          leds[k-1]= CHSV(255, 255, stage0);
          leds[k-2] =CHSV(255, 255, stage1);
          leds[k-3] =CHSV(255, 255, stage2);
          leds[k-4] =CHSV(255, 255, stage3);
      }
      else if(i == 10){
          leds[k]=CRGB::Black;
          leds[k-1]=CRGB::Black;
          leds[k-2] =CHSV(255, 255, stage0);
          leds[k-3] =CHSV(255, 255, stage1);
          leds[k-4] =CHSV(255, 255, stage2);
      }
      else if(i == 11){
          leds[k]=CRGB::Black;
          leds[k-1]=CRGB::Black;
          leds[k-2]=CRGB::Black;
          leds[k-3]= CHSV(255, 255, stage0);
          leds[k-4]= CHSV(255, 255, stage1);
      }
      else if(i == 12){
        leds[k] = CRGB::Black;
          leds[k-1]=CRGB::Black;
          leds[k-2]=CRGB::Black;
          leds[k-3]=CRGB::Black;
          leds[k-4]= CHSV(255, 255, stage0);
      }
      else if(i == 13){
        leds[k-4]= CRGB::Black;
        }
      leds(k+1, k+5) = leds(k, k-4);
    }
    FastLED.show();
      delay(70); 
  }
}  
  
