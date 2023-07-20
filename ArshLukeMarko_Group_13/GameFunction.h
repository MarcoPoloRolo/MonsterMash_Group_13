#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define MONSTER_COUNT 8
#define FILENAME "stats"

typedef struct monstStat {
	double hitpoints;
	double attack;
	double defence;
} MONSTSTAT;

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

MONSTSTAT readMonsterFromFile(FILE* fp);