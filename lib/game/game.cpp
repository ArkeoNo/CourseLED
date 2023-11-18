#include <Arduino.h>
#include "game.h"
#include "led.h"

bool init_joueur(struct player *joueur, int id, int pos, int lap){
    joueur->id = id;
    joueur->pos = pos;
    joueur->lap = lap;
    return true;
}

void init_button(void){
    for(int i = 0; i < NB_JOUEURS_MAX; i++){
        pinMode(PIN_BP[i], INPUT_PULLUP);
    }
}

void button_pressed(int bp[NB_JOUEURS_MAX]){
    static int state[NB_JOUEURS_MAX];
    
    for(int i = 0; i < NB_JOUEURS_MAX; i++){
        if(digitalRead(PIN_BP[i]) == HIGH){
            state[i] = 0;
        }
        if(digitalRead(PIN_BP[i]) == LOW && state[i] == 0){
            bp[i] = LOW;
            state[i] = 1;
        }
        else{
            bp[i] = HIGH;
        }
    }
}

int getPremierJoueur(player players[NB_JOUEURS_MAX]) {
    int posMax = 0;
    int idMax = 0;
    for (int i = 0; i < NB_JOUEURS_MAX; i++) {
        if (players[i].pos + (players[i].lap * NUM_LEDS) > posMax) {
            posMax = players[i].pos + (players[i].lap * NUM_LEDS);
            idMax = i;
        }
    }

    return idMax;
}

void spawn_boost(int boosts[NOMBRE_BOOST]){
    for(int i = 0; i < NOMBRE_BOOST; i++){
        boosts[i] = random(0, NUM_LEDS);
    }
}

void use_boost(player *joueur, int boosts[NOMBRE_BOOST], player players[NB_JOUEURS_MAX]){
    for(int i = 0; i < NOMBRE_BOOST; i++){
        if(joueur->pos == boosts[i]){
            for(int j = 0; j < PUISSANCE_BOOST; j++){
                joueur->pos++;
                affichageJeu(players, boosts);
            }
        boosts[i] = random(0, NUM_LEDS);
        }
    }
}

