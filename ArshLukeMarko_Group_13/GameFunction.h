#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct monstStat {
	double hitpoints;
	double attack;
	double defense;
	int speed;
	bool isAlive;
} MONSTSTAT;

void game();