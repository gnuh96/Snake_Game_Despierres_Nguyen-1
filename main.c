#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include "plateau.h"
#include "snake.h"

void *fun_snake(void *p){

}

void *fun_plateau(void *p) {

}

int main(int argc, char *argv[]){

    int opt, niveau, hauteur, largeur, nb_snake;
    hauteur=25;
    largeur=25;
    niveau=1;
    nb_snake=2;
    
    //Initialisation random
    srand(time(NULL));

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

    pthread_t snake_thread[nb_snake];
    pthread_t plateau_thread;

    for (int i = 0; i < nb_snake; i++)
    {
        pthread_create(&snake_thread[i],NULL,fun_snake,NULL);
    }
    pthread_create(&plateau_thread,NULL,fun_plateau,NULL);
    for (int i = 0; i < nb_snake; i++)
    {
        pthread_join(&snake_thread[i],NULL);
    }
    pthread_join(&plateau_thread, NULL);
    affichePlateau(plat);

    exit(EXIT_SUCCESS);
}


