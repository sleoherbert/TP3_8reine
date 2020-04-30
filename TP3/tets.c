#include "tets.h"

int testprintsol(){

    int solution[4];
    solution[0]=1;
    solution[1]=3;
    solution[2]=0;
    solution[3]=2;

    printf("test solution\n");

    printSolution(solution,4);


    return 0;
}


int testqueensafe(){
    int i;
    int solution[64];

    for(i=0;i<64;i++)
        solution[i]=-1;


    solution[0]=1;
    solution[1]=3;
    solution[2]=0;

    bool a = false;

    printSolution(solution,8);
    a=queenIsSafe(solution,4,6);


    if(a==true){
        printf("queen is safe\n");
    }else{
        printf("queen is not safe\n");
    }

    return 0;
}

int testbishopsafe(){
    int i;
    int solution[64];

    for(i=0;i<64;i++)
        solution[i]=-1;


    solution[0]=1;
    solution[4]=3;
    solution[7]=0;

    bool a = false;

    printSolution(solution,8);
    a=bishopIsSafe(solution,4,6);


    if(a==true){
        printf("bishop is safe\n");
    }else{
        printf("bishop is not safe\n");
    }

    return 0;
}

int testkingsafe(){
    int i;
    int solution[64];

    for(i=0;i<64;i++)
        solution[i]=-1;


    solution[0]=1;
    solution[4]=3;
    solution[7]=4;
    solution[2]=5;
    solution[1]=7;
    solution[7]=0;
    solution[5]=6;
    solution[0]=2;
    solution[5]=4;

    bool a = false;

    printSolution(solution,8);
    a=kingIsSafe(solution,4,6);


    if(a==true){
        printf("king is safe\n");
    }else{
        printf("king is not safe\n");
    }

    return 0;
}


int testknightsafe(){
    int i;
    int solution[64];

    for(i=0;i<64;i++)
        solution[i]=-1;


    solution[0]=1;
    solution[4]=3;
    solution[7]=4;
    solution[2]=5;
    solution[1]=7;
    solution[7]=0;
    solution[5]=6;

    bool a = false;

    printSolution(solution,8);
    a=knightIsSafe(solution,4,6);


    if(a==true){
        printf("knight is safe\n");
    }else{
        printf("knight is not safe\n");
    }

    return 0;
}
