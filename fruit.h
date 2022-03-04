#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining a struct for elements place (x,y) on the board
typedef struct fruit {
    char fruit_type; // 'F' : Fraise, 'C' : Cerise, 'B' : Banana, 'P' : Pomme
    int x; //ligne
    int y; //collone
} fruit;