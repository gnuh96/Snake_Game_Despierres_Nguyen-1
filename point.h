#include <stdio.h>
#include <stdlib.h>

typedef struct Point{
    int x;
    int y;
}Point;

void deplace(Point *p, int dx, int dy) {
    p->x = p->x + dx;
    p->y = p->y + dy;
}

void affiche(Point *p) {
    printf("( %d , %d)\n", p->x, p->y);
}

Point initPoint(int largeur, int hauteur){
    Point p;
    p.x=rand()%(largeur+1);
    p.y=rand()%(hauteur+1);

    return p;
}
// int main () {
//     Point p1 = {1,2};
//     affiche(&p1);
//     deplace(&p1, 2, 1);
//     affiche(&p1);
// }