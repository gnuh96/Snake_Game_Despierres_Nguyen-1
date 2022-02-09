#include <stdio.h>
#include <stdlib.h>
#include <point.h>

typedef struct Snake{
    int id;
    int taille;
    Point *body; //liste des cellules ou le Snake occupe
}Snake;

Snake initSnake(int i){
    Snake s;
    s.id = i;
    s.taille = 1;
    s.body=(Point*)malloc(s.taille*sizeof(Point));
    Point p = {1, i+1};
    s.body[0]= p;
}

