//CSCN71030 - Group 13: Arsh Chauhan, Luke Bolhous, Marko Cvetkovic - Summer 2023 - Group assignment: Monster Mash

#define _CRT_SECURE_NO_WARNINGS
#include "GameFunction.h"
#include "Interface.h"
#include "Display.h"

int main()
{
	//Creates array for trophy list and initializes values from file
	int trophies[NUMBER_OF_OPPONENTS] = { 0 };
	FILE* fp1 = fopen("trophies", "r");
	for (int i = 0; i < NUMBER_OF_OPPONENTS; i++)
		fscanf_s(fp1, "%d\n", &trophies[i]);
	fclose(fp1);
	
	//Creates array for monsters
	MONSTSTAT monsters[MONSTER_COUNT] = { 0 }; 	

	//Start game loop
	int difficulty;
	bool continueGame = true;
	do
	{
		//Reset all monster values before each battle starts
		FILE* fp2 = fopen("stats", "r");
		for (int i = 0; i < MONSTER_COUNT; i++)
			fscanf_s(fp2, "%lf\n%lf\n%lf\n%lf\n", &monsters[i].maxHP, &monsters[i].HP, &monsters[i].attack, &monsters[i].defence);
		fclose(fp2);

		//Get main menu input and proceed to the next menu
		switch (mainMenu())
		{
		case 1: //Get difficulty/monster then start the battle
			difficulty = difficultySelection();
			int monsterChoice = monsterSelection() - 1;
			int opponentMonster = rand() % 4;
			printBattleIntro();
			bool playerWon = battleStart(monsters[monsterChoice], monsters[opponentMonster], monsterChoice, opponentMonster + 4, (difficulty / 5) + 0.6);
			//Assigning new trophies
			if (playerWon && trophies[monsterChoice] < difficulty) //If you haven't already beaten a harder monster...
				trophies[monsterChoice] = difficulty;
			break;

		case 2: //Display trophy room
			printTrophies(trophies);
			break;

		case 3: //Exit
			printf("\nThanks for playing!\n");
			continueGame = false;
			break;
		}
	} while (continueGame == true);

	//End game
	FILE* fp3 = fopen("trophies", "w"); // Overwrites previous file
	for (int i = 0; i < NUMBER_OF_OPPONENTS; i++)
	{
		fprintf(fp3, "%d\n", trophies[i]); // Writes updated information into file
	}
	fclose(fp3);
	return 0;
}