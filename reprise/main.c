/*  test de reprise de programmation apres un bon petit moment de non prog.
 on va partir sur un jeu de plus ou moins. */


/* Trucs a prevoir pour la suite:
 Modifier les choses a afficher pour que le rendu soit plus agreable.
 Selection aleatoire des mots dans un fichier texte
 Choix de la difficulté qui influe sur le nombre de chances
 Représentation graphique d'un pendu (En console bien sure!)
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Fonctions.h"



int main(int argc, const char * argv[])
{
    int nbPlayer;
    nbPlayer = selectMode();
    
    play(nbPlayer);
}