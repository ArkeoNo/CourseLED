#include "led.h"
#include <FastLED.h>

CRGB leds[NUM_LEDS];

void initLeds() {
    FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(255);
    FastLED.clear();
    FastLED.show();
}

void allumerLedJoueur(struct player* ptr_player) {
   leds[ptr_player->pos] = COULEURS[ptr_player->num];  // Allume la led du joueur
}
