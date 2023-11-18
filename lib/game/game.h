#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include <FastLED.h>

#define NOMBRE_TOURS 3
#define NB_JOUEURS_MAX 3

const int PIN_BP[] {2, 3, 4}; // Pins des bouttons

/**
 * @struct player
 * @brief Représente un joueur dans le jeu.
 * 
 * Cette structure contient les informations relatives à un joueur, telles que son identifiant, sa position et son tour.
 */
struct player {
	int id;
    int pos;
    int lap;
};

/**
 * @brief Initialise un joueur avec les informations spécifiées.
 * 
 * @param joueur Un pointeur vers la structure du joueur à initialiser.
 * @param id L'identifiant du joueur.
 * @param pos La position du joueur.
 * @param lap Le tour du joueur.
 * @return true si l'initialisation a réussi, sinon false.
 */
bool init_joueur(struct player *joueur, int id, int pos, int lap);

/**
 * @brief Initialise l'interruption sur les bouttons.
 */
void init_button(void);

/**
 * @brief Routine d'interruption des bouttons.
 */
void button_pressed(int *bp);

#endif