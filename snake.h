#include <stdio.h>
#include <stdlib.h>
#include <point.h>

typedef struct Snake{
    int taille;
    Point *body; //liste des cellules ou le Snake occupe
}Snake;

