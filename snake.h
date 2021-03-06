#include <stdio.h>
#include <stdlib.h>
#include "point.h"

typedef struct Snake{
    char id;
    int taille;
    Point *body; //liste des cellules ou le Snake occupe
    int score; //score du snake
}Snake;


void print_snake_on_plat(Snake* s, Plateau* plat) {
    for (int i = 0; i < s->taille; i++) {
        plat->map[s->body[i].x][s->body[i].y] = s->id;
    }
}

void initSnake(Snake s, int i, Plateau *plat){
    printf("\nInitialisation Snake\n");
    s.id =  i+'0';
    printf("\nid\n");
    s.taille = 1;
    printf("\nTaille\n");
    s.body=(Point*)malloc(s.taille*sizeof(Point));
    Point p = initPoint(plat->largeur, plat->hauteur);
    s.body[0]= p;
    s.score=0;
    printf("\nInitialisation Snake 2\n");
        //Affichage du snake sur le plateau
    for(int i=0;i<s.taille;i++){
        plat->map[s.body[i].x][s.body[i].y]=s.id;
        printf("ID : %d",s.id);
    }
}

int max(int n, int m) {
    if (n>m){
        return n;
    }
    else
        return m;
}

void updateScore(char fruit, int *score){
    switch (fruit){

    case 'F': //Fraise
        *score+=5;
        break;
    case 'C': //Cerises
        *score+=3;
        break;
    case 'B': //Banane
        *score+=2;
        break;
    case 'P': //Pomme
        *score+=1;
        break;
    case 'X':
        *score-=15;
    default:
        break;
    }
}

void afficheScore(Snake s){
    printf("Snake %c : %d\n", s.id, s.score);
}

Point deplaceTete(int hauteur, int largeur){
    int x, y;
    x=rand()% largeur;
    y=rand()% hauteur;
    Point p={x,y};
    return p;
}

//A tester
void deplaceSnake(Plateau *plat, Snake *s, int hauteur, int largeur){
    //Deplacement de la tete
    Point tete=deplaceTete(hauteur, largeur);
    
    //Recuperation du fruit
    char fruit=getChar(plat, tete.x, tete.y);
    updateScore(fruit, &s->score);
    //Booleen pour verifier l'ajout d'un point au snake
    int ajout=0;

    Point pointTmp1, pointTmp2;
    pointTmp1=s->body[0]; //pointTmp1 prend la position actuelle de la tete
    deplace(&s->body[0],tete.x,tete.y);

    //Ajout d'un nouveau fruit
    if(fruit!='.'){
        updateFruit(plat);
        ajout=1;
    }

    //Deplacement du reste du corps
    if (s->taille>1)
    {
        for(int i=1;i<s->taille;i++){
            pointTmp2=s->body[i]; //pointTmp2 prend la position actuelle du point
            deplace(&s->body[i], pointTmp1.x, pointTmp1.y); //s.body[i] prend la position du point precedent
            pointTmp1=pointTmp2; //pointTmp1 prend la position en memoire dans pointTmp2
        }
    }

    //Verification que le snake est sous la taille max
    if(s->taille<max(plat->hauteur, plat->largeur)){
        //Ajout d'un point
        s->body[s->taille]=initPoint(pointTmp1.x, pointTmp1.y);
    }

    //Affichage du snake sur le plateau
    for(int i=0;i<s->taille;i++){
        plat->map[s->body[i].x][s->body[i].y]=s->id;
    }
}