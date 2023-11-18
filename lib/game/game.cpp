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
    for(int i = 0; i < NB_JOUEURS_MAX; i++){
        bp[i] = digitalRead(PIN_BP[i]);
    }
}

