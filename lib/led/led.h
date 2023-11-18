#ifndef LED_H
#define LED_H

#include <FastLED.h>
#include "game.h"

#define DATA_PIN 6	 // Pin du bandeau LED
#define NUM_LEDS 120 // Nombre de LED du bandeau

const CRGB COULEURS[] = {CRGB::Blue, CRGB::Red, CRGB::Green};

void initLeds();
void allumerLedJoueurs(struct player players[NB_JOUEURS_MAX]);

#endif