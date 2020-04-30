#include "reine_fonction.h"
#include "tets.h"

int main()
{
    /*testprintsol();
    testqueensafe();
    testbishopsafe();
    testkingsafe();
    testknightsafe();*/
    int i,c=0,t=64;
    char filename[]="SaveSolution";
    int tabsol[9];

    bool (*pf)(int solution[],int x,int y);

    printf("Probleme des 8 reines et variantes\n");

    while(c!=1 && c!=2 && c!=3 && c!=4){
        puts("Resoudre \n1 : 8 Reines\n2 : 14 fou\n3 : 16 Rois\n4 : 32 chevalier\n\nVotre choix: ");
        scanf("%d",&c);
    }
    if(c==1){
        pf=&queenIsSafe;
    }
    if(c==2){
        pf=&bishopIsSafe;

    }
    if(c==3){
        pf=&kingIsSafe;
    }
    if(c==4){
        pf=&knightIsSafe;
    }
    for(i=0; i<t; i++)
        tabsol[i]=-1;


    search(tabsol,8,0,filename,(*pf));

    printSolution(tabsol,8);

    return 0;
}
