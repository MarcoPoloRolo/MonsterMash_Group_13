#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define NUMBEROFOPPONENTS 4
#define MONSTER_COUNT 8

typedef struct monstStat {
	double HP;
	double maxHP;
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

double attackDamage(MONSTSTAT, MONSTSTAT);

void delay(int);

void printBattleState(MONSTSTAT, MONSTSTAT, int, int);