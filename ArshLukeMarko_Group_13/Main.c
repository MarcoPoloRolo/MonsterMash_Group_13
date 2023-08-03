//CSCN71030 - Group 13: Arsh Chauhan, Luke Bolhous, Marko Cvetkovic - Summer 2023 - Group assignment: Monster Mash

#define _CRT_SECURE_NO_WARNINGS
#include "GameFunction.h"
#include "Interface.h"
#include "Display.h"

int main(int argc, char* argv[])
{
	//Resetting the randomness
	srand(time(NULL));

	bool bossMode = false;
	if (argc > 1 && strcmp(argv[1], "39772") == 0)
		bossMode = true; //If code is entered, user has access to a secret boss

	//Creates array for trophy list and initializes values from file
	int trophies[NUMBER_OF_OPPONENTS] = { 0 };
	FILE* fp1 = fopen("trophies", "r");
	for (int i = 0; i < NUMBER_OF_OPPONENTS; i++)
		fscanf_s(fp1, "%d\n", &trophies[i]);
	fclose(fp1);
	
	//Creates array for monsters
	MONSTSTAT monsters[MONSTER_COUNT] = { 0 }; 	

	//Start game loop
	int difficulty = 2; //Default is normal mode
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
			soundEffect(L"menuSelection.wav");
			if (!bossMode)
			{
				difficulty = difficultySelection(); //Get desired difficulty
				soundEffect(L"menuSelection.wav");
			}
			int monsterChoice = monsterSelection() - 1; //Get users monster
			soundEffect(L"menuSelection.wav");
			int opponentMonster;
			if (bossMode)
				opponentMonster = 4;
			else
				opponentMonster = rand() % 4;

			printBattleIntro();
			printBattleState(monsters[monsterChoice], monsters[opponentMonster + 4], monsterChoice, opponentMonster + 4); //print battle state
			if (bossMode)
				soundEffect(L"bossFightStart.wav");
			else
				soundEffect(L"battleStart.wav");
			bool playerWon = battleStart(monsters[monsterChoice], monsters[opponentMonster + 4], monsterChoice, opponentMonster + 4, ((double)difficulty / 5) + 0.6);
			//Assigning new trophies
			if (playerWon && trophies[opponentMonster] < difficulty) //If you haven't already beaten a harder monster...
				trophies[opponentMonster] = difficulty;
			break;

		case 2: //Display trophy room
			soundEffect(L"menuSelection.wav");
			printTrophies(trophies);
			break;

		case 3: //Exit
			continueGame = false;
			break;
		}
	} while (continueGame == true);

	//End game
	printf("\nThanks for playing!\n");
	soundEffect(L"gameExit.wav");

	FILE* fp3 = fopen("trophies", "w"); // Overwrites previous file
	for (int i = 0; i < NUMBER_OF_OPPONENTS; i++)
	{
		fprintf(fp3, "%d\n", trophies[i]); // Writes updated information into file
	}
	fclose(fp3);
	return 0;
}