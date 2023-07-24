#define _CRT_SECURE_NO_WARNINGS
#include "GameFunction.h"
#include "Utility.h"

int main()
{
	//Creates array for trophy list and initializes from file
	int trophies[NUMBER_OF_OPPONENTS] = { 0 };
	FILE* fp2 = fopen("trophies", "r");
	for (int i = 0; i < NUMBER_OF_OPPONENTS; i++)
		fscanf_s(fp2, "%d\n", &trophies[i]);
	fclose(fp2);
	
	//Battle setup -----------------------------------------------------------------------------------------------
	MONSTSTAT monsters[MONSTER_COUNT] = { 0 }; //Creates array and initializes values from read only file
	FILE* fp1 = fopen("stats", "r");
	for (int i = 0; i < MONSTER_COUNT; i++)
		fscanf_s(fp1, "%lf\n%lf\n%lf\n%lf\n", &monsters[i].maxHP, &monsters[i].HP, &monsters[i].attack, &monsters[i].defence);
	fclose(fp1);

	int player = 2; //Players monster choice (0-3), currently hardcoded
	int opponent = 7; //opponents monsters (4-7)

	int menuChoice;
	double difficultyMultiplier;
	printf("Select difficulty:\n1. Easy\n2. Normal\n3. Hard\n");
	if (scanf("%d", &menuChoice))
	{
		difficultyMultiplier = ((double)menuChoice / 5) + 0.6; //Either 0.8x, 1x, or 1.2x;
		monsters[opponent].attack = monsters[opponent].attack * difficultyMultiplier;
		monsters[opponent].defence = monsters[opponent].defence * difficultyMultiplier;
	} //Makes opponent's stats harder or easier depending on difficulty choice

	//Battle start -----------------------------------------------------------------------------------------------
	double damage;
	srand(time(NULL));
	while (monsters[player].HP > 0 && monsters[opponent].HP > 0) //Battle starts
	{
		printBattleState(monsters[player], monsters[opponent], player, opponent); //print battle state
		//Player's turn ---------------------------------------
		printf("Select a move :\n1. Attack\n2. Defend\n3. Special\n4. Forfeit\n"); //print move options
		if (scanf("%d", &menuChoice))
		{
			switch (menuChoice) //move choice logic
			{
			case 1: //Basic attack
				damage = attackDamage(monsters[player], monsters[opponent]);
				monsters[opponent].HP = monsters[opponent].HP - damage;
				printBattleState(monsters[player], monsters[opponent], player, opponent);
				printf("You attacked your opponent for %.1lf damage.\n", damage);
				break;
			case 2: //Defence 
				monsters[player].defence = monsters[player].defence * DEFENCE_MULTIPLIER;
				printBattleState(monsters[player], monsters[opponent], player, opponent);
				printf("Defence increased by 20%%\n");
				break;
			case 3: //Special move
				damage = specialDamage(monsters[player], monsters[opponent]);
				if (damage > 0)
					monsters[opponent].HP = monsters[opponent].HP - damage;
				else
					monsters[player].HP = monsters[player].HP + damage; //positive because damage is already negative in this case.
				printBattleState(monsters[player], monsters[opponent], player, opponent);
				if (damage > 0)
					printf("Critical hit! You dealt %.1lf damage to your opponent!\n", damage);
				else
					printf("It backfired! You dealt %.1lf damage to yourself!\n", -damage);
				break;
			case 4: //Forfeit
				monsters[player].HP = 0;
				break;
			}
		}
		//Enemy's turn ----------------------------------------
		if (monsters[player].HP > 0 && monsters[opponent].HP > 0)
		{
			printf("\nOpponent's turn");
			for (int i = 0; i < 5; i++)
			{
				delay(800);
				printf(".");
			}
			menuChoice = rand() % 3+1; //randomly select move
			switch (menuChoice) //logic for player's move choice
			{
			case 1: //Basic attack
				damage = attackDamage(monsters[opponent], monsters[player]);
				monsters[player].HP = monsters[player].HP - damage;
				printBattleState(monsters[player], monsters[opponent], player, opponent);
				printf("Your opponent attacked you for %.1lf damage.", damage);
				break;
			case 2: //Defence 
				monsters[opponent].defence = monsters[opponent].defence * DEFENCE_MULTIPLIER;
				printBattleState(monsters[player], monsters[opponent], player, opponent);
				printf("Opponent's defence increased by 20%%");
				break;
			case 3: //Special move
				damage = specialDamage(monsters[opponent], monsters[player]);
				if (damage > 0)
					monsters[player].HP = monsters[player].HP - damage;
				else
					monsters[opponent].HP = monsters[opponent].HP + damage; //positive because damage is already negative in this case.
				printBattleState(monsters[player], monsters[opponent], player, opponent);
				if (damage > 0)
					printf("Critical hit! Your opponent dealt %.1lf damage to you!", damage);
				else
					printf("Your opponents attack backfired! It dealt %.1lf damage to itself!", -damage);
				break;
			}
			for (int i = 0; i < 5; i++)
			{
				printf(".");
				delay(800);
			}
		}
	}
	if (monsters[player].HP <= 0) //end game logic, with trophies
		printf("\nBattle over. You lost.\n");
	else
		printf("\nBattle over. You won!\n");

	return 0;
}