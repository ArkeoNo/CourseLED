#include "led.h"
#include "game.h"
#include <FastLED.h>

CRGB leds[NUM_LEDS];

void initLeds() {
    FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(255);
    FastLED.clear();
    FastLED.show();
}

void allumerLedJoueurs(struct player players[NB_JOUEURS_MAX]) {
    for (int i = 0; i < NB_JOUEURS_MAX; i++) {
        leds[players[i].pos] = COULEURS[players[i].id];
    }
    FastLED.show();
}
