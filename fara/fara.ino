#include <FastLED.h>
#define NUM_LEDS 26
#define DATA_PIN 3
#define CLOCK_PIN 13


CRGB leds[NUM_LEDS];

void setup() { 
     FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical
}



void clear(){
    for(int i=0; i<NUM_LEDS ;i++)
        leds[i]=CRGB::Black;
    //FastLED.show();
}

void white(){
    for(int i=0; i<NUM_LEDS ;i++)
        leds[i]=CRGB::White;
    FastLED.show();
}

void color(CRGB c){
    for(int i=0; i<NUM_LEDS ;i++)
        leds[i]=c;
    FastLED.show();
}

void litgh(int l){
  for(int i=0; i<NUM_LEDS ;i++)
    leds[(i+0)%NUM_LEDS]=CRGB::White;
  FastLED.show();
}


void circle(){
  for(int i=0; i<NUM_LEDS ;i++){
    clear();    
    leds[(i+0)%NUM_LEDS]=CRGB::White;
    leds[(i+1)%NUM_LEDS]=CRGB::White;
    leds[(i+2)%NUM_LEDS]=CRGB::White;
    leds[(i+(NUM_LEDS/2)+0)%NUM_LEDS]=CRGB::White;
    leds[(i+(NUM_LEDS/2)+1)%NUM_LEDS]=CRGB::White;
    leds[(i+(NUM_LEDS/2)+2)%NUM_LEDS]=CRGB::White;
    FastLED.show();
    delay(50);
  }
}


void strobe(){
  int d=200;
  for(int i=0;i<5;i++){
    litgh(1);
    delay(50);
    clear();  
    FastLED.show();    
    delay(125);
    }
}

void police(){
    for(int i=0; i<NUM_LEDS ;i++){
      for(int r=0;r<NUM_LEDS/4 ;r++){
            leds[(i+r)%NUM_LEDS]=CRGB::Blue;
      }
      for(int r=0;r<NUM_LEDS/4 ;r++){
            leds[(i+(NUM_LEDS/2)+r)%NUM_LEDS]=CRGB::Red;
      }      
    FastLED.show();
    delay(25);
    clear();
  }
}


void police2(){
  for(int i=0;i<4;i++){
    for(int i=0; i<NUM_LEDS ;i++)
        leds[i]=CRGB::Red;
    FastLED.show();
    delay(250);
    for(int i=0; i<NUM_LEDS ;i++)
        leds[i]=CRGB::Blue;
    FastLED.show();
    delay(250);    
  }
}

void usiali(CRGB c,CRGB p){
  for(int i=0; i<NUM_LEDS ;i++){
    for(int q=0;q<NUM_LEDS/3;q++){
      leds[(i+q)%NUM_LEDS]=c;
      leds[(i+(NUM_LEDS/2)+q)%NUM_LEDS]=c;
    }
    FastLED.show();
    delay(50);
    color(p);
  }
}



void loop() { 
  while(1){
    clear();
    for(int i=0;i<254;i++){
      for(int l=0;l<NUM_LEDS;l++)
        leds[l] += CRGB( 1, 0, 0);
      FastLED.show();
      delay(4);             
    }
    for(int i=0;i<254;i++){
      for(int l=0;l<NUM_LEDS;l++)
        leds[l] -= CRGB( 1, 0, 0);
      FastLED.show();
      delay(4);             
    }


    for(int i=0;i<254;i++){
      for(int l=0;l<NUM_LEDS;l++)
        leds[l] += CRGB( 0, 1, 0);
      FastLED.show();
      delay(4);             
    }
    for(int i=0;i<254;i++){
      for(int l=0;l<NUM_LEDS;l++)
        leds[l] -= CRGB( 0, 1, 0);
      FastLED.show();
      delay(4);             
    }


    for(int i=0;i<254;i++){
      for(int l=0;l<NUM_LEDS;l++)
        leds[l] += CRGB( 0, 0, 1);
      FastLED.show();
      delay(4);             
    }
    for(int i=0;i<254;i++){
      for(int l=0;l<NUM_LEDS;l++)
        leds[l] -= CRGB( 0, 0, 1);
      FastLED.show();
      delay(4);             
    }    

    
  

    usiali(CRGB::Green,CRGB(50,50,50));
    usiali(CRGB::Green,CRGB::White);
    usiali(CRGB::Green,CRGB(50,50,50));    
    
    usiali(CRGB::Yellow,CRGB(50,50,50));
    usiali(CRGB::Yellow,CRGB::White);
    usiali(CRGB::Yellow,CRGB(50,50,50));    
    police();
    police();
    police2();    
    circle();
    circle();
    //clear();
    strobe();  
    strobe();  
    color(CRGB::White);
    delay(4000);
  }

  for(int i=0;i<13;i++){
      leds[i] = CRGB::Red;
  }
  
  for(int i=13;i<26;i++){
      leds[i] = CRGB::Blue;
  }
  FastLED.show();
  delay(500);
    for(int i=0;i<13;i++){
      leds[i] = CRGB::Blue;
  }
  
  for(int i=13;i<26;i++){
      leds[i] = CRGB::Red;
  }
  FastLED.show();
  delay(500);
}
