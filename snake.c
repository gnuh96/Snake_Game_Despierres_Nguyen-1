#include <stdio.h>
#include <stdlib.h>
#include <point.c>

typedef struct Snake{
    int taille;
    Point *listePoint; //liste des cellules ou le Snake occupe
}Snake;