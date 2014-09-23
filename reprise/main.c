/*  test de reprise de programmation apres un bon petit moment de non prog.
 on va partir sur un jeu de plus ou moins. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

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
void selectMode() {
    char nbPlayers;
    nbPlayers = getOneChar();
    switch (nbPlayers) {
        case '1':
            break;
        default:
            break;
    }
}

// Cette fonction transforme notre chaine de caractère en tiret et cloture la chaine (ça évite d'avoir des erreurs)
void initializeString(char * string, int length) {
    for(int i = 0; i < length; i++) {
        string[i] = '_';
        printf("%c ", string[i]);
    }
    string[length] = '\0';
}

void play() {
    // Il faudra ensuite aller chercher un mot aléatoire dans une base de donnée (ça peut être un fichier texte)
    char word[] = "Looser";
    char answer[strlen(word)];
    // Le joueur peut se tromper 3 fois
    int attempts = 3;
    printf("Vous avez %d essai%s !\n", attempts, (attempts <= 1) ? "" : "s");
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
            } else if (word[i] == toupper(c)) {
                isInWord = true;
                answer[i] = toupper(c);
            // Ici minuscule (T remplira T et t par exemple)
            } else if (word[i] == tolower(c)) {
                isInWord = true;
                answer[i] = tolower(c);
            }
        }
        // On affiche le mot à trou complété avec les lettres
        for(int i = 0; i < strlen(word); i++) {
            printf("%c ", answer[i]);
        }
        printf("\n");
        // Si la lettre n'est pas dans le mot
        if(!isInWord) {
            attempts--;
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

int main(int argc, const char * argv[])
{
    play();
}