/*  test de reprise de programmation apres un bon petit moment de non prog.
 on va partir sur un jeu de plus ou moins. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void emptyBuffer() {
    char c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

char getOneChar() {
    char c;
    c = getchar();
    emptyBuffer();
    return c;
}

void selectMode() {
    char nbPlayers;
    nbPlayers = getOneChar();
    switch (nbPlayers) {
        case '1':
            break;
        case '2':
            break;
        default:
            break;
    }
}

int main(int argc, const char * argv[])
{
    selectMode();
}