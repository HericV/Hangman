/*  test de reprise de programmation apres un bon petit moment de non prog.
 on va partir sur un jeu de plus ou moins.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fonctions.h"


int main(int argc, const char * argv[])
{
    int nombreDeJoueurs = demandeNombreJoueurs();
    
    if (nombreDeJoueurs == 1) {
        modeUnJoueur();
    } else {
        modeDeuxJoueurs();
    }
    
    
}