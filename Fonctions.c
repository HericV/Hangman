
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int demandeNombreJoueurs()          // Demande le nombre de joueurs avant de lancer une partie.
{
    int nombreDeJoueurs = 0;
    
    while (nombreDeJoueurs != 1 && nombreDeJoueurs != 2)
    {
        printf("Combien de joueurs vont participer?\n");
        printf("1. 1 joueur\n");
        printf("2. 2 joueurs\n");
        
        scanf("%d", &nombreDeJoueurs);
        
        printf("\n");
        
        switch (nombreDeJoueurs) {
            case 1:
                nombreDeJoueurs = 1;
                break;
            case 2:
                nombreDeJoueurs = 2;
                break;
            default:
                printf("Reponse incorrecte!\n\n\n");
                break;
        }
    }
    return nombreDeJoueurs;
}

void modeUnJoueur()                 // Lance le mode un joueur
{
    printf("Mode un joueur en cours de programmation\n");
}

char getcharnb(int length) {
    char c;
    for (int i = 0; i < length; i++) {
        
    }
    return c;
}

void modeDeuxJoueurs()              // Lance le mode deux joueurs
{
    
    int chiffreChoisis;
    int chiffre
    
    printf("Joueur 1, Quel chiffre choisissez vous entre 1 et 100?\n");
    
    scanf("%d", &chiffreChoisis);
    
    printf("\n\n\n\n\n\n");
    printf("Joueur 2 quel est le chiffre mistère?\n");
    printf("Chiffre mistère est =");
    scanf("%d",)
}