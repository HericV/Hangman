//
//  dico.c
//  Pendu
//
//  Created by Heric Vignola on 28/02/2014.
//  Copyright (c) 2014 Heric Vignola. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dico.h"

int compteNombreCaracteres()                      //trouve un nombre aleatoir en fonction du nombre de Mots du ficher.
{
    int nombreMots = 0;
    char caractereActuel = 0;
    FILE *fichier = NULL;
    
    fichier = fopen("dico.txt", "r");
    if (fichier == NULL) {
        printf("le fichier dico.txt n'a pas pu s'ouvrir dans la fonction 'compteNombreCaracteres'\n");
        exit(0);
    }
    
    do {
        caractereActuel = getc(fichier);
        if (caractereActuel == '\n') {
            nombreMots++;
        }
    } while (caractereActuel != EOF);
    
    nombreMots ++;
    
    fclose(fichier);
    
    return nombreMots;
}

int nombreAleatoir(int nombreMots)                //Pioche un nombre au hazar dans le fichier 'dico.txt'
{
    int MAX = nombreMots;
    int MIN = 1;
    int nombreAleatoir = 0;
    
    srand(time(NULL));
    
    nombreAleatoir = (rand() % (MAX - MIN + 1)) + MIN;
    
    return nombreAleatoir;
}

int piocherMot(char *motMystere)                  //Pioche un mot dans la liste.
{
    FILE *fichier = NULL;
    int nombre = 0;
    int numeroMotActuel = 1;
    char caractereActuel = 0;
    
    nombre = nombreAleatoir(compteNombreCaracteres());
    
    fichier = fopen("dico.txt", "r");
    
    if (fichier == NULL) {
        printf("Le fichier dico n'a pas pu s'ouvrir.");
        return 0;
    }
    
    while (numeroMotActuel != nombre) {     //se place dans le fichier 'dico.txt' au mot correspondant au chiffre donné.
        caractereActuel = getc(fichier);
        if (caractereActuel == '\n') {
            numeroMotActuel++;
        }
    }
    
    fgets(motMystere, 100, fichier);
    
    motMystere[strlen(motMystere) - 1] = '\0';
    
    fclose(fichier);
    
    return 1;
    
}
