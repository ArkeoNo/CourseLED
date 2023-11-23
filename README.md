# Course Led
### _Projet DN Made 2 EDNA Nantes Arthur Ducroz_

## Description du jeu

- 2 à 3 joeurs font la course sur un circuit sous la forme d'un bandeau de leds. 
- Le premier joueur à faire 3 tours de pistes gagne la partie. 
- Afin de faire avancer leur voiture, les joueurs doivent appuyer sur un bouton. Chaque pression du boutton fait avancer la voiture d'une case. 
- 5 boost sont répartis aléatoirement sur la piste, ils permettent de faire avancer la voiture de 5 cases rapidement en plus de bloquer les autres pendant cette courte période.

## Matériel
- 1 Arduino Uno (ou équivalent)
- 1 Breadboard
- 1 Bandeau de leds ARGB
- 2 à 3 boutons poussoirs
- 1 buzzer piezo electrique 

## Montage 

## Controle des leds
Afin de controler le bandeau de leds, nous utilisons la librairie [FastLED](https://github.com/FastLED/FastLED). À partir de cette librairie, plusieurs procédures ont été créées afin de controler les leds pour le jeu.

### Paramètres :
4 paramètres sont à définit et peuvent être modifiés dans le fichier `leds.h` :

- `NUM_LEDS` : nombre de leds dans le bandeau
- `PIN_LED` : pin de l'arduino sur laquelle est branchée le bandeau
- `const CRGB COULEURS[NB_JOUEURS_MAX]` liste des couleurs des joueurs
- `const CRGB COULEUR_BOOST` couleur des boost

### Fonctions :
3 procédures sont utilisée pour controler les leds :
- `void initLeds()` : initialise le bandeau de leds à partir du numéro de pin et du nombre de leds
- `void affichageJeu(struct player players[NB_JOUEURS_MAX], int boosts[NOMBRE_BOOST]);` : affiche le jeu sur le bandeau de leds
- `void animVictoire(int idGagnant)` : affiche l'animation de victoire du joueur gagnant



