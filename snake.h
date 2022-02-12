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
    default:
        break;
    }
}

void afficheScore(Snake s){
    printf("Snake %c : %d\n", s.id, s.score);
}

Point deplaceSnake(int hauteur, int largeur){
    int x, y;
    x=rand()% largeur;
    y=rand()% hauteur;
    Point p={x,y};
    return p;
}