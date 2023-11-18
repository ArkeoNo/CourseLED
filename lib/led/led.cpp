#include "led.h"
#include "game.h"
#include <FastLED.h>

CRGB leds[NUM_LEDS];

void initLeds(void) {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(80);
    FastLED.clear();
    leds[NUM_LEDS - 1] = CRGB::White; // Pour tester
    FastLED.show();
}

void affichageJeu(struct player players[NB_JOUEURS_MAX], int boosts[NOMBRE_BOOST]) {
    FastLED.clear();
    for (int i = 0; i < NB_JOUEURS_MAX; i++) {
        leds[players[i].pos] = COULEURS[players[i].id];
    }
    for (int i = 0; i < NOMBRE_BOOST; i++) {
        leds[boosts[i]] = COULEUR_BOOST;
    }
    FastLED.show();
}

void animVictoire(int idGagnant) {
    FastLED.clear();
    FastLED.show();

    for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = COULEURS[idGagnant];
        leds[i-1] = CRGB::Black;
        FastLED.show();
        delay(14);
    }
}
