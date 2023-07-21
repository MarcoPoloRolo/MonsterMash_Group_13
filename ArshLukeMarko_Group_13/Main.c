#define _CRT_SECURE_NO_WARNINGS
#include "GameFunction.h"
#include "Utility.h"

int main()
{
	//Creates array and initializes values from read only file
	MONSTSTAT monsters[MONSTER_COUNT] = { 0 };
	FILE* fp1 = fopen("stats", "r");
	for (int i = 0; i < MONSTER_COUNT; i++)
		fscanf_s(fp1, "%lf\n%lf\n%lf\n%lf\n", &monsters[i].maxHP, &monsters[i].HP, &monsters[i].attack, &monsters[i].defence);
	fclose(fp1);

	//Creates array for trophy list and initializes from file
	int trophies[NUMBEROFOPPONENTS] = { 0 };
	FILE* fp2 = fopen("trophies", "r");
	for (int i = 0; i < NUMBEROFOPPONENTS; i++)
		fscanf_s(fp2, "%d\n", &trophies[i]);
	fclose(fp2);

	//Battle start
	int player = 1; //Players character choice (0-3), currently hardcoded
	int opponent = 5; //opponents characters (4-7)
	int menuChoice, damage;
	srand(time(NULL));
	printBattleState(monsters[player], monsters[opponent], player, opponent); //print battle state
	while (monsters[player].HP > 0 && monsters[opponent].HP > 0) //Battle starts
	{		
		//Player's turn ---------------------------------------
		printf("\nSelect a move :\n1. Attack\n2. Defend\n3. Special\n4. Forfeit\n"); //print move options
		if (scanf("%d", &menuChoice))
		{
			switch (menuChoice) //move choice logic
			{
			case 1: //Basic attack
				damage = attackDamage(monsters[player], monsters[opponent]);
				monsters[opponent].HP = monsters[opponent].HP - damage;
				system("@cls||clear");
				printBattleState(monsters[player], monsters[opponent], player, opponent);
				printf("\nYou attacked your opponent for %d damage.\n", (int)ceil(damage));
				break;
			case 2: //Defence 

				break;
			case 3: //Special

				break;
			case 4: //Forfeit
				monsters[player].HP = 0;
				break;
			default:
				break;
			}
		}

		//Enemy's turn ----------------------------------------
		//randomly select move
		//logic for player's move choice
		//tell the player what the enemy did (with time delays)
	}
	return 0;
}