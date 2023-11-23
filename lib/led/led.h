#ifndef LED_H
#define LED_H

#include <FastLED.h>
#include "game.h"

#define DATA_PIN 6	    // Pin du bandeau LED
#define NUM_LEDS 153    // Nombre de LED du bandeau 153

const CRGB COULEURS[NB_JOUEURS_MAX] = {CRGB::Blue, CRGB::Yellow, CRGB::Red};    // Couleurs des joueurs dans l'ordre des joueurs
const CRGB COULEUR_BOOST = CRGB::Magenta;					                    // Couleur des boosts

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
void affichageJeu(struct player players[NB_JOUEURS_MAX], int boosts[NOMBRE_BOOST]);

/**
 * @brief Animation de victoire.
 * 
 * Cette fonction anime la victoire en effectuant une séquence de clignotements des LEDs.
 */
void animVictoire(int idGagnant);

#endif