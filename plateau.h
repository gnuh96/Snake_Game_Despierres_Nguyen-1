#include <stdio.h>
#include <stdlib.h>

typedef struct Plateau{
    int hauteur;
    int largeur;
    int niveau;
    char **map;
}Plateau;

Plateau initPlateau(int hauteur, int largeur, int niveau){
    Plateau plat;
    plat.hauteur=hauteur;
    plat.largeur=largeur;
    plat.niveau=niveau;
   
    plat.map = (char **)malloc(sizeof(char*) * hauteur);
        for (int i = 0; i < hauteur; i++)
        {
            plat.map[i] = (char *)malloc(sizeof(char) * largeur);
        }

    int espaceLargeur, espaceHauteur;
    espaceHauteur=hauteur/10;
    espaceLargeur=largeur/10;

    switch (niveau){
    case 1:
        for(int i=0;i<plat.hauteur;i++){
            for(int j=0;j<plat.largeur;j++){
                plat.map[i][j]='.';
            }
        }
        break;
    case 2:
        for(int i=0;i<plat.hauteur;i++){
            for(int j=0;j<plat.largeur;j++){
                if(j==0||j==plat.largeur-1||i==0||i==plat.hauteur-1)
                    plat.map[i][j]='X';
                else
                    plat.map[i][j]='.';
            }
        }
        break;
    case 3:
        for(int i=0;i<plat.hauteur;i++){
            for(int j=0;j<plat.largeur;j++){
                if(plat.largeur>=10&&plat.hauteur>=10){
                   if(i==espaceHauteur||i==espaceHauteur+1||i==plat.hauteur-espaceHauteur-2||i==plat.hauteur-espaceHauteur-1){
                       if((j==espaceLargeur||j==espaceLargeur+1||j==plat.largeur-espaceLargeur-2||j==plat.largeur-espaceLargeur-1)){
                           plat.map[i][j]='X';
                       }
                       else
                          plat.map[i][j]='.'; 
                    }
                      else
                        plat.map[i][j]='.'; 
                }    
            }
        }
        break;
    case 4:
         for(int i=0;i<plat.hauteur;i++){
            for(int j=0;j<plat.largeur;j++){

                if((plat.largeur<=19&&plat.largeur>9)||(plat.hauteur<=19&&plat.hauteur>9)){
                   if(i==espaceHauteur+1||i==espaceHauteur+2||i==plat.hauteur-espaceHauteur-3||i==plat.hauteur-espaceHauteur-2){
                       if((j==espaceLargeur+1||j==espaceLargeur+2||j==plat.largeur-espaceLargeur-3||j==plat.largeur-espaceLargeur-2)){
                           plat.map[i][j]='X';
                       }
                       else
                          plat.map[i][j]='.'; 
                    }
                      else
                        plat.map[i][j]='.'; 
                }    

                if(plat.largeur>19||plat.hauteur>19){
                   if(i==espaceHauteur||i==espaceHauteur+1||i==plat.hauteur-espaceHauteur-2||i==plat.hauteur-espaceHauteur-1){
                       if((j==espaceLargeur||j==espaceLargeur+1||j==plat.largeur-espaceLargeur-2||j==plat.largeur-espaceLargeur-1)){
                           plat.map[i][j]='X';
                       }
                       else
                          plat.map[i][j]='.'; 
                    }
                      else
                        plat.map[i][j]='.'; 
                }    
                
                if(j==0||j==plat.largeur-1||i==0||i==plat.hauteur-1){
                    plat.map[i][j]='X';
                }
            }
        }
        break;
    }

    return plat;
}

void affichePlateau(Plateau plat){
    for(int i=0;i<plat.hauteur;i++){
        for(int j=0;j<plat.largeur;j++){
            printf("%c",plat.map[i][j]);
            if(j==plat.largeur-1)
                printf("\n");
        }
    }
}

char getChar(Plateau plat, int x, int y){
    return(plat.map[x][y]);
}