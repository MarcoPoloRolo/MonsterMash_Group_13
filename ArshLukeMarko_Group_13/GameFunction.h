#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define DEFENCE_MULTIPLIER 0.85
#define NUMBER_OF_OPPONENTS 5
#define MONSTER_COUNT 9
#define DELAY_TIME 500

typedef struct monstStat {
	double maxHP;
	double HP;
	double attack;
	double defence;
} MONSTSTAT;

double attackDamage(MONSTSTAT, MONSTSTAT);
double specialDamage(MONSTSTAT, MONSTSTAT);

void delay(int);

bool battleStart(MONSTSTAT, MONSTSTAT, int, int, double);