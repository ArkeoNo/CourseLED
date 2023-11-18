#ifndef LED_H
#define LED_H

#include <FastLED.h>
#include "game.h"

#define DATA_PIN 6	 // Pin du bandeau LED
#define NUM_LEDS 153 // Nombre de LED du bandeau

const CRGB COULEURS[] = {CRGB::Blue, CRGB::Yellow, CRGB::Red};

/**
 * @brief Initialise les LEDs.
 * 
 */
void initLeds(void);

/**
 * @brief Allume les LEDs aux positions des joueurs.
 * 
 * @param players Le tableau des joueurs.
 */
void allumerLedJoueurs(struct player players[NB_JOUEURS_MAX]);

/**
 * @brief Animation de victoire.
 * 
 * Cette fonction anime la victoire en effectuant une séquence de clignotements des LEDs.
 */
void animVictoire(void);

#endif