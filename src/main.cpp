#include <Arduino.h>
#include <FastLED.h>
#include "led.h"
#include "game.h"

struct player players[NB_JOUEURS_MAX];


void setup() {
  Serial.begin(9600); //  init communication via port usb

  // pinMode(PIN_BUZZER, OUTPUT); //  init pin buzzer
  // analogWrite(PIN_BUZZER, 140);
  // delay(400);
  // analogWrite(PIN_BUZZER, 0);
  
  // tone(PIN_BUZZER, 440, 200);
  // delay(1000);
  // noTone(PIN_BUZZER);

pinMode(PIN_BUZZER, OUTPUT);
  for(int i = 0; i < 3; i++){
    tone(PIN_BUZZER, musique_demarrage[i], 200);
    delay(200);
  }

  
  /*Initialisation du jeu*/
  Serial.println("Initialisation du jeu...");
  randomSeed(analogRead(0)); //  Initialisation de la fonction random
  initLeds();  // Initialisation des leds
  init_button();  // Initialisation des boutons
}

void loop() {
  // Initialisation de la partie
  bool partieEnCours = true;
  for (int i = 0; i < NB_JOUEURS_MAX; i++) {
    init_joueur(&players[i], i, 0, 0); // Initialisation des joueurs
  }
  int boosts[NOMBRE_BOOST];
  spawn_boost(boosts); // Initialisation des boosts

  // Boucle de jeu
  while (partieEnCours) { // Boucle de jeu
    int bp[NB_JOUEURS_MAX];
    button_pressed(bp);
    for (int i = 0; i < NB_JOUEURS_MAX; i++) {
      // Si un joueur finit la partie, on sort de la boucle
      if (!partieEnCours) break;

      // Avancer le joueur si son bouton est pressé
      if (bp[i] == LOW) {
        float nombreAleatoire = random(1, 100);
        int idPremier = getPremierJoueur(players); // Récupère l'id du premier joueur
        int ecartPremier = 0;  // Ecart à 0 par défaut
        if (idPremier != i) {
          ecartPremier = players[idPremier].pos + players[idPremier].lap * NUM_LEDS - players[i].pos - players[i].lap * NUM_LEDS;
        }
        float nombreMinDoubler = 100 * PROBA_MAX_DOUBLER * (ecartPremier) / (NOMBRE_TOURS * NUM_LEDS);
        
        if (idPremier != i) {
          Serial.print("Joueur ");
          Serial.print(i);
          Serial.print(" : nombreAleatoire=");
          Serial.print(nombreAleatoire);
          Serial.print(",\tnombreMinDoubler=");
          Serial.print(nombreMinDoubler);
          Serial.print(",\tecartPremier=");
          Serial.print(ecartPremier);
          Serial.print(",\tx2=");
          Serial.println(nombreAleatoire <= nombreMinDoubler);
        }

        if (nombreAleatoire <= nombreMinDoubler) {
          players[i].pos += 2;
        } else {
          players[i].pos += 1;
        }
        use_boost(&players[i], boosts, players);
      }

      // Si le joueur a fini un tour, on incrémente son compteur de tours
      if (players[i].pos >= NUM_LEDS) {
        players[i].pos %= NUM_LEDS;
        players[i].lap++;

        // Si le joueur a fini la course, on affiche l'animation de victoire
        if (players[i].lap >= NOMBRE_TOURS) {
          animVictoire(i);

          // On sort de la boucle de jeu
          partieEnCours = false;
        }
      }
    }
    affichageJeu(players, boosts);
  }
}
