#include <Arduino.h>
#include <FastLED.h>
#include "led.h"
#include "game.h"

struct player players[NB_JOUEURS_MAX];

void setup() {
  Serial.begin(9600);//  init communication via port usb
  Serial.println("Initialisation du jeu");

  /*Initialisation du jeu*/

  // Initialisation des joueurs
  for(int i = 0; i < NB_JOUEURS_MAX; i++){
    if(init_joueur(&players[i], i, 0, 0));
    else Serial.println("Erreur lors de l'initialisation du joueur");
  }

  // Initialisation des leds
  initLeds();


}


void loop() {
  allumerLedJoueurs(players);
}
