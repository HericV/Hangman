/*  test de reprise de programmation apres un bon petit moment de non prog.
 on va partir sur un jeu de plus ou moins.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, const char * argv[])
{
    int nombreDeJoueurs = 0;
    
    
    while (nombreDeJoueurs != 1 && nombreDeJoueurs != 2)
    {
        printf("Combien de joueurs ont participer?\n");
        printf("1. 1 joueur\n");
        printf("2. 2 joueurs\n");
    
        scanf("%d", &nombreDeJoueurs);
    
        printf("\n");
    
        switch (nombreDeJoueurs) {
            case 1:
                printf("Mode 1 joueur en cours de programmation.\n");
                nombreDeJoueurs = 1;
                break;
            case 2:
                printf("Mode 2 joueurs en cours de programmation.\n");
                nombreDeJoueurs = 2;
                break;
            default:
                printf("Reponse incorrecte!\n\n\n");
                break;
        }
    }
}