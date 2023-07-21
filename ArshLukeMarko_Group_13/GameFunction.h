#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct monstStat {
	double HP;
	double maxHP;
	double attack;
	double defence
} MONSTSTAT;

void game();

char* setUsername() {
	printf("Enter username: \n");

}