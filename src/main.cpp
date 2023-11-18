#include <Arduino.h>
#include <FastLED.h>
#include "led.h"
#include "game.h"

struct player players[NB_JOUEURS_MAX];

void setup() {
  Serial.begin(9600);//  init communication via port usb
  Serial.println("Initialisation du jeu...");
  /*Initialisation du jeu*/
  for(int i = 0; i < NB_JOUEURS_MAX; i++) init_joueur(&players[i], i, 0, 0); // Initialisation des joueurs
  initLeds();  // Initialisation des leds
}


void loop() {
  players[0].pos = (players[0].pos + 1)%NUM_LEDS;
  allumerLedJoueurs(players);
  delay(10);
}
  

