#include <stdio.h>
#include <stdlib.h>
#include "point.h"

typedef struct Snake{
    char id;
    int taille;
    Point *body; //liste des cellules ou le Snake occupe
    int score; //score du snake
}Snake;

Snake initSnake(int i){
    Snake s;
    s.id =  i+'0';
    s.taille = 1;
    s.body=(Point*)malloc(s.taille*sizeof(Point));
    Point p = {1, i+1};
    s.body[0]= p;
    s.score=0;
    return s;
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
void deplaceSnake(Plateau plat, Snake s, int hauteur, int largeur){
    //Deplacement de la tete
    Point tete=deplaceTete(hauteur, largeur);
    
    Point pointTmp1, pointTmp2;
    pointTmp1=s.body[0]; //pointTmp1 prend la position actuelle de la tete
    deplace(&s.body[0],tete.x,tete.y);

    //Recuperation du fruit
    char fruit=getChar(plat, tete.x, tete.y);
    updateScore(fruit, &s.score);

    //Deplacement du reste du corps
    if (s.taille>1)
    {
        for(int i=1;i<s.taille;i++){
            pointTmp2=s.body[i]; //pointTmp2 prend la position actuelle du point
            deplace(&s.body[i], pointTmp1.x, pointTmp1.y); //s.body[i] prend la position du point precedent
            pointTmp1=pointTmp2; //pointTmp1 prend la position en memoire dans pointTmp2
        }
    }
}