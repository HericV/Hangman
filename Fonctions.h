//
//  Header.h
//  reprise
//
//  Created by Heric Vignola on 06/07/2014.
//  Copyright (c) 2014 Heric Vignola. All rights reserved.
//

#ifndef reprise_Header_h
#define reprise_Header_h

// On vide le buffer du cin
void emptyBuffer();

// On récupère le premier caractère du cin puis on vide le buffer
char getOneChar();

// ça servira pour plus tard quand on pourra jouer à deux
int selectMode();

// Cette fonction transforme notre chaine de caractère en tiret et cloture la chaine (ça évite d'avoir des erreurs)
void initializeString(char * string, int length);

//Lance le jeu.
void play(int nbPlayer);

#endif
