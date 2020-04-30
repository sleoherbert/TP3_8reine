#include "reine_fonction.h"


void printSolution(int solution[], int taille){
    int i,j;
    int gtab[taille][taille];

    for (i = 0; i < taille; i++)
        for (j = 0; j < taille; j++)
            gtab[i][j]=0;


    //Solution[] vers gtab[][]
    for(i=0; i<taille;i++){
        for(j=0; j<taille; j++){
            if(solution[i*j]!=-1)
                gtab[i][j]=1;
        }
    }

    for(i=0; i<taille;i++){
        for(j=0; j<taille; j++){
            printf("%d ",gtab[i][j]);
        }
        puts("");
    }
}


void saveSolution(int solution[], int taille, char * fileName){
  FILE *fichier = NULL;
  int i;
  fichier = fopen(fileName,"w");
  if(fichier!=NULL){
    for(i=0;i<taille;i++){
        fprintf(fichier,"%d : %d \n", i, solution[i]);
    }
  }
  fclose(fichier);
}

bool queenIsSafe(int solution[], int x, int y){ //x col, y rangée
    int i,j,taille=8;
    int gtab[taille][taille];

    //initialiser gtab
    for (i = 0; i < taille; i++)
        for (j = 0; j < taille; j++)
            gtab[i][j]=0;

    //Solution[] vers gtab[][]
    for(i=0; i<taille;i++){
        for(j=0; j<taille; j++){
            if(solution[i*j]!=-1)
                gtab[i][j]=1;
        }
    }


    //Verifier la rangée et la colonne
    for(i=0;i<taille;i++)
    {
        if((gtab[y][i] == 1) || (gtab[i][x] == 1))
            return false;
    }
    //verifier les diagonals
    for(i=0;i<taille;i++)
    {
        for(j=0;j<taille;j++)
        {
            if(((i+j) == (y+x)) || ((i-j) == (y-x)))
            {
                if(gtab[i][j] == 1)
                    return false;
            }
        }
    }

    return true;
}

bool bishopIsSafe(int solution[], int x, int y){//x col, y rangée
    int i,j,taille=8;

    int gtab[taille][taille];

    //initialiser gtab
    for (i = 0; i < taille; i++)
        for (j = 0; j < taille; j++)
            gtab[i][j]=0;

    //Solution[] vers gtab[][]
    for(i=0; i<taille;i++){
        for(j=0; j<taille; j++){
            if(solution[i*j]!=-1)
                gtab[i][j]=1;
        }
    }

    //verifier les diagonals
    for(i=0;i<taille;i++)
    {
        for(j=0;j<taille;j++)
        {
            if(((i+j) == (y+x)) || ((i-j) == (y-x)))
            {
                if(gtab[i][j] == 1)
                    return false;
            }
        }
    }

    return true;
}

bool kingIsSafe(int solution[], int x, int y){//x col, y rangée
    int i,j,taille=8;
    int gtab[taille][taille];

    //initialiser gtab
    for (i = 0; i < taille; i++)
        for (j = 0; j < taille; j++)
            gtab[i][j]=0;

    //Solution[] vers gtab[][]
    for(i=0; i<taille;i++){
        for(j=0; j<taille; j++){
            if(solution[i*j]!=-1)
                gtab[i][j]=1;
        }
    }


    //vérifier toute les cases voisines
    if(y >=0 && y< taille && x>=0 && x< taille){
        if(y>0 && x>0 && gtab[y-1][x-1]==1){
            return false;
        }
        if(y>0 && gtab[y-1][x]==1){
            return false;
        }
        if(y>0 && x+1<taille && gtab[y-1][x+1]==1){
            return false;
        }
        if(x>0 && gtab[y][x-1]==1){
            return false;
        }
        if(x+1< taille && gtab[y][x+1]==1){
            return false;
        }
        if(y+1<taille && x>0 && gtab[y+1][x-1]==1){
            return false;
        }
        if(y+1<taille && gtab[y+1][x]==1){
            return false;
        }
        if(y+1<taille && x+1<taille && gtab[y+1][x+1]==1){
            return false;
        }
    }

    return true;
}

bool knightIsSafe(int solution[], int x, int y){//x col, y rangée
    int i,j,taille=8;
    int gtab[taille][taille];

    //initialiser gtab
    for (i = 0; i < taille; i++)
        for (j = 0; j < taille; j++)
            gtab[i][j]=0;

    //Solution[] vers gtab[][]
    for(i=0; i<taille;i++){
        for(j=0; j<taille; j++){
            if(solution[i*j]!=-1)
                gtab[i][j]=1;
        }
    }

    if(y >=0 && y< taille && x>=0 && x< taille){
        //vérifier haut gauche
        if(y>0 && x-1>0 && gtab[y-1][x-2]==1){
            return false;
        }
        if(y-1>0 && x>0 && gtab[y-2][x-1]==1){
            return false;
        }

        //verifier haut droite
        if(y>0 && x+2<taille && gtab[y-1][x+2]==1){
            return false;
        }
        if(y-1>0 && x+1<taille && gtab[y-2][x+1]==1){
            return false;
        }

        //verifier bas gauche
        if(y+2<taille && x>0 && gtab[y+2][x-1]==1){
            return false;
        }
        if(y+1<taille && x-1>0 && gtab[y+1][x-2]==1){
            return false;
        }

        //verifier bas droite
        if(y+2<taille && x+1<taille && gtab[y+2][x+1]==1){
            return false;
        }
        if(y+1<taille && x+2<taille && gtab[y+1][x+2]==1){
            return false;
        }
    }

    return true;
}


void search(int solution[],int taille, int y, char *filename, bool (*pf)(int solution[],int x,int y)){
    int i,j;

    bool exit = false;
    int gtab[taille][taille];

    //initialiser gtab
    for (i = 0; i < taille; i++)
        for (j = 0; j < taille; j++)
            gtab[i][j]=0;

    //Solution[] vers gtab[][]
    for(i=0; i<taille;i++){
        for(j=0; j<taille; j++){
            if(solution[i*j]!=-1)
                gtab[i][j]=1;
        }
    }

    //verifier si on peu
    if(y>=taille)
        exit = true;

    if(exit == false){
        for(j=0;j<taille;j++)
        {
            //Verifer si on peu placer l'objet
            if(((*pf)(solution,j,y))==true && (gtab[y][j]!=1))
            {
                gtab[y][j] = 1;
                solution[y+j]=j;

                //verifier si on peut mettre le prochain objey .
                if(y == taille){
                    exit = true;
                    gtab[y][j] = 0;
                    solution[y+j]=-1;
                }
            }
        }
        if(exit != true){
            y++;
            j=0;
            search(solution,taille,y,filename,(*pf));
        }
    }
    saveSolution(solution,34,filename);
}
