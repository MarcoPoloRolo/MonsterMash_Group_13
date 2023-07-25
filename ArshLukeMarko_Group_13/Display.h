#pragma once
#include <stdbool.h>
#include <stdio.h>

//Print monster functions
//Players
void printNibbles(bool);
void printFelix(bool);
void printPip(bool);
void printBaconBoi(bool);
//Opponents
void printChomp(bool);
void printTy(bool);
void printJared(bool);
void printPorkchop(bool);

void printBattleState(MONSTSTAT, MONSTSTAT, int, int);