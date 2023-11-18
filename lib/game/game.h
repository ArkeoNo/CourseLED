#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include <FastLED.h>

#define NOMBRE_TOURS 3
#define NB_JOUEURS_MAX 3
#define NOMBRE_BOOST 5
#define PUISSANCE_BOOST 5

#define PROBA_MAX_DOUBLER 0.8

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
 * @brief Vérifie si un boutton a été pressé.
 * 
 * @param bp Un tableau contenant l'état des bouttons.
 */
void button_pressed(int *bp);

int getPremierJoueur(player players[]);

/**
 * @brief Spawn tous les boosts à une position aléatoire de la piste.
 * 
 * @param boosts Le tableau de boosts dans lequel le boost sera ajouté.
 */
void spawn_boost(int boosts[NOMBRE_BOOST]);

/**
 * Utilise un boost un joueur donné est positionné dessus puis en fait réaparaitre un de manière alétoire sur la piste.
 * 
 * @param joueur Le joueur pour lequel utiliser le boost.
 * @param boosts Un tableau contenant les boosts disponibles.
 */
void use_boost(player *joueur, int boosts[NOMBRE_BOOST]);

#endif