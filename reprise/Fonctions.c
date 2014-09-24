#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "dico.h"




// On vide le buffer du cin
void emptyBuffer() {
    char c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

// On récupère le premier caractère du cin puis on vide le buffer
char getOneChar() {
    char c;
    c = (char)getchar();
    emptyBuffer();
    return c;
}

// ça servira pour plus tard quand on pourra jouer à deux
int selectMode() {
    char nbPlayers = '\0';
    int choixNbPlayer;
    
    do {
        printf("Combien de joueurs vont participer?\n");
        printf("1 -> 1 joueur\n");
        printf("2 -> 2 joueurs\n");
        printf("Votre choix? ");
        choixNbPlayer = getOneChar();
        printf("\n");
        
        switch (choixNbPlayer) {
            case  49:
                nbPlayers = 1;
                printf("\n\n\n\n\n\n\n\n\n\n");
                break;
            case 50:
                nbPlayers = 2;
                printf("\n\n\n\n\n\n\n\n\n\n");
                break;
            default:
                printf("%c n'est pas une réponse valide.\n\n\n", choixNbPlayer);
                break;
        }
    } while (nbPlayers != 1 && nbPlayers != 2);
    
    return nbPlayers;
}

// Cette fonction transforme notre chaine de caractère en tiret et cloture la chaine (ça évite d'avoir des erreurs)
void initializeString(char * string, int length) {
    for(int i = 0; i < length; i++) {
        string[i] = '_';
        printf("%c ", string[i]);
    }
    string[length] = '\0';
}

// Lance le jeu.
void play(int nbPlayer) {
    
    char word[100] = "";
    
    if (nbPlayer == 1) {
        piocherMot(word);
    } else {
        printf("Joueur 1 Quel mot mystere choisissez-vous?\n");
        printf("Mot mystere = ");
        scanf("%s", word);
        emptyBuffer();
        printf("\n\n\n\n\n\n\n\n\n\n");
        }
    
    
    char answer[strlen(word)];
    // Le joueur peut se tromper 3 fois
    int attempts = 3;
    printf("Joueur 2, vous avez %d essai%s !\n", attempts, (attempts <= 1) ? "" : "s");
    printf("Le mot mystere est = ");
    // On remplis la réponse avec des tirets de la même longueur que le mot demandé
    initializeString(answer, (int)strlen(word));
    printf("\n");
    // Tant que la réponse et le mot demandé ne corresponde pas et qu'il nous reste un essai
    while (strcmp(answer, word) != 0 && attempts > 0) {
        printf("\nEntrer une lettre :\n");
        // On récupère un caractère du cin
        char c = getOneChar();
        bool isInWord = false;
        // Pour chaque caractère du mot demandé
        for(int i = 0; i < strlen(word); i++) {
            // On vérifie si le mot contient la lettre
            if(word[i] == c) {
                isInWord = true;
                answer[i] = c;
                // Ici on vérifie la lettre majuscule (t remplira T et t par exemple)
            } else if (word[i] == (c - 32)) {
                isInWord = true;
                answer[i] = (c - 32);
                // Ici minuscule (T remplira T et t par exemple)
            } else if (word[i] == (c + 32)) {
                isInWord = true;
                answer[i] = (c + 32);
            }
        }
        
        printf("\n\n\n\n\n\n\n\n\n\n");
        
        // On affiche le mot à trou complété avec les lettres
        for(int i = 0; i < strlen(word); i++) {
            printf("%c ", answer[i]);
        }
        printf("\n\n");
        // Si la lettre n'est pas dans le mot
        if(!isInWord) {
            attempts--;
            printf("Et non la lettre ''%c'' n'est pas dans le mot mystère!\n", c);
            // Si il n'y a plus d'essai possible
            if (attempts == 0) {
                printf("Perdu !\n");
                exit(2);
                // On affiche le nombre d'essais restants
            } else {
                printf("\nIl ne vous reste que %d essai%s !\n", attempts, (attempts <= 1) ? "" : "s");
            }
        }
    }
    // On gagne !
    printf("\nLe mot était %s\n", word);
    printf("Vous avez gagné ! (avec %d essai%s restant%s)\n", attempts, (attempts <= 1) ? "" : "s", (attempts <= 1) ? "" : "s");
    

    
    exit(1);
}