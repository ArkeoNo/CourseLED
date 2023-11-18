#include <Arduino.h>
#include "game.h"
#include "led.h"

bool init_joueur(struct player *joueur, int id, int pos, int lap){
    joueur->id = id;
    joueur->pos = pos;
    joueur->lap = lap;
    return true;
}

void button_pressed(void){
    digitalWrite(LED_BUILTIN, CHANGE);
    while(digitalRead(INTERUPT_PIN) == HIGH); // Moyen moyen en vrai mais bon => Ajouter un "ou si 100ms écoulées"

}

bool init_button(void){
    pinMode(INTERUPT_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(INTERUPT_PIN), button_pressed, RISING);
    return true;
}

