#define _CRT_SECURE_NO_WARNINGS
#include "GameFunction.h"
#include "Interface.h"
#include "Display.h"

int main()
{
	//Creates array for trophy list and initializes values from file
	int trophies[NUMBER_OF_OPPONENTS] = { 0 };
	FILE* fp2 = fopen("trophies", "r");
	for (int i = 0; i < NUMBER_OF_OPPONENTS; i++)
		fscanf_s(fp2, "%d\n", &trophies[i]);
	fclose(fp2);
	
	//Creates array for monsters and initializes values from read only file
	MONSTSTAT monsters[MONSTER_COUNT] = { 0 }; 
	FILE* fp1 = fopen("stats", "r");
	for (int i = 0; i < MONSTER_COUNT; i++)
		fscanf_s(fp1, "%lf\n%lf\n%lf\n%lf\n", &monsters[i].maxHP, &monsters[i].HP, &monsters[i].attack, &monsters[i].defence);
	fclose(fp1);

	//Start game
	bool continueGame = true;
	do
	{
		switch (mainMenu()) //Get main menu input and proceed to the next menu
		{
		case 1:
			//get difficulty level then start the battle
			printf("unfinished");
			break;
		case 2:
			printTrophyRoom(trophies);
			break;
		case 3:
			printf("Exiting the game...\n");
			continueGame = false;
			break;
		}
	} while (continueGame == true);

	/*int player = 2; //Players monster choice (0-3), currently hardcoded
	int opponent = 7; //opponents monsters (4-7)

	int menuChoice;
	printf("Select difficulty:\n1. Easy\n2. Normal\n3. Hard\n");
	scanf("%d", &menuChoice);
	double difficultyMultiplier = ((double)menuChoice / 5) + 0.6;
	printf("%lf", difficultyMultiplier);*/
	return 0;
}