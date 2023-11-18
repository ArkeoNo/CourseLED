#include "led.h"
#include "game.h"
#include <FastLED.h>

CRGB leds[NUM_LEDS];

void initLeds(void) {
    FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(255);
    FastLED.clear();
    leds[NUM_LEDS - 1] = CRGB::White; // Pour tester
    FastLED.show();
}

void allumerLedJoueurs(struct player players[NB_JOUEURS_MAX]) {
    FastLED.clear();
    for (int i = 0; i < NB_JOUEURS_MAX; i++) {
        leds[players[i].pos] = COULEURS[players[i].id];
    }
    FastLED.show();
}

void animVictoire(void){
    for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::White;
        leds[i-1] = CRGB::Black;
        FastLED.show();
        delay(10);
    }
}
