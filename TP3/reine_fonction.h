#ifndef _REINE_FONCTION_H_
#define _REINE_FONCTION_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void printSolution(int solution[], int taille);

void saveSolution(int solution[], int taille, char * fileName);

bool queenIsSafe(int solution[], int x, int y);

void search(int solution[],int taille, int y, char *filename, bool (*pf)(int solution[],int x,int y));

bool bishopIsSafe(int solution[], int x, int y);

bool kingIsSafe(int solution[], int x, int y);

bool knightIsSafe(int solution[], int x, int y);


#endif  //_REINE_FONCTION_H_
