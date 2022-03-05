#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include "plateau.h"
#include "snake.h"
#include "pthread.h"
#include "unistd.h"

pthread_mutex_t mutex_plateau = PTHREAD_MUTEX_INITIALIZER;
Plateau plat;
int SCORE=0;
int GAGNANT=-1;

void *fun_snake(void *arg){   
    Snake *s;
    unsigned int id=(uintptr_t) arg;
    initSnake(s, id);
    while (s->score != SCORE)
    {
        deplaceSnake(plat,s, plat.hauteur, plat.largeur);
        pthread_mutex_lock(&mutex_plateau);
        print_snake_on_plat(s, &plat);
        pthread_mutex_unlock(&mutex_plateau);
    }
    return NULL;
}

void *fun_plateau(void *p) {
    while (GAGNANT==-1)
    {
        affichePlateau(*((Plateau*)p));
    }
    return NULL;
}

int main(int argc, char *argv[]){

    int opt, niveau, hauteur, largeur, nb_snake;
    hauteur=25;
    largeur=25;
    niveau=1;
    nb_snake=2;
    
    //Initialisation random
    srand(time(NULL));

    //Initialisation score
    SCORE=rand()%(99-50+1)+50;

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

    pthread_t snake_thread[nb_snake];
    pthread_t plateau_thread;

    for (int i = 0; i < nb_snake; i++){
        pthread_create(&snake_thread[i],NULL,fun_snake,(void *) (i));
        pthread_join(snake_thread[i],NULL);
    }
   
    pthread_create(&plateau_thread,NULL,fun_plateau,(void *) &plat);
    
    pthread_join(plateau_thread, NULL);

//    affichePlateau(plat);
    pthread_exit(NULL);
    
    exit(EXIT_SUCCESS);
}

