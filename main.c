#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "plateau.h"

int main(int argc, char *argv[]){

    int opt, niveau, hauteur, largeur, nb_snake;
    hauteur=25;
    largeur=25;
    niveau=1;
    nb_snake=2;
    
    //Lecture des arguments
    while ((opt = getopt(argc, argv, ":if:n:m:l:")) != -1) {
        switch (opt) {
        case 'n': //hauteur
            hauteur = atoi(optarg);
            break;
        case 'm': //largeur
            largeur=atoi(optarg);
            break;
        case 'l': //niveau
            niveau=atoi(optarg);
            break;
         }
    }
    for(; optind < argc; optind++){     
        nb_snake=atoi(argv[optind]);
    }

    printf("Hauteur : %d\n", hauteur);
    printf("Largeur : %d\n", largeur);
    printf("Niveau de depart :%d\n", niveau);
    printf("Nombre de snakes: %d\n", nb_snake);
    
   Plateau plat=initPlateau(hauteur,largeur,niveau);
   affichePlateau(plat);
    exit(EXIT_SUCCESS);
}


