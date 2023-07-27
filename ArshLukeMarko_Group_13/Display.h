#pragma once
#include "GameFunction.h"
#include <stdbool.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>

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
void printBoss(bool);

void printTrophies(int[]);
void printDifficulty(int);

void printBattleState(MONSTSTAT, MONSTSTAT, int, int);
void printBattleIntro();
void delayBetweenTurns();
void printBattleEnd(bool);
void printHelpScreen();

void soundEffect(const wchar_t* pszSound);