#include "GameFunction.h"

double attackDamage(MONSTSTAT attacker, MONSTSTAT defender)
{
	return((attacker.attack * defender.defence) + rand()%10);
}
double specialDamage(MONSTSTAT attacker, MONSTSTAT defender)
{
	if ((rand() % 10) + 1 <= 5) //50% chance of the attack hitting
		return(((attacker.attack * defender.defence) + rand() % 10) * 2); //double the regular damage
	else
		return(((attacker.attack * defender.defence) + rand() % 10) / -2); //half the regular damage. Negative to signify it hits the player
}

void delay(int ms) //freezes the program for some number of milliseconds
{
	clock_t start_time = clock();
	while (clock() < start_time + ms);
}

void battleStart(MONSTSTAT player, MONSTSTAT opponent, int p, int o, double d)
{
	//Setup
	opponent.attack = opponent.attack * d;
	opponent.defence = opponent.defence * d; //Makes opponent's stats harder or easier depending on difficulty choice
	//Start
	int moveChoice;
	double damage;
	srand(time(NULL));
	while (player.HP > 0 && opponent.HP > 0) //Battle starts
	{
		printBattleState(player, opponent, p, o); //print battle state
		//Player's turn ---------------------------------------
		printf("Select a move :\n1. Attack\n2. Defend\n3. Special\n4. Forfeit\n"); //print move options
		if (scanf("%d", &moveChoice))
		{
			switch (moveChoice) //move choice logic
			{
			case 1: //Basic attack
				damage = attackDamage(player, opponent);
				opponent.HP = opponent.HP - damage;
				printBattleState(player, opponent, p, o);
				printf("You attacked your opponent for %.1lf damage.\n", damage);
				break;
			case 2: //Defence 
				player.defence = player.defence * DEFENCE_MULTIPLIER;
				printBattleState(player, opponent, p, o);
				printf("Defence increased by 20%%\n");
				break;
			case 3: //Special move
				damage = specialDamage(player, opponent);
				if (damage > 0)
					opponent.HP = opponent.HP - damage;
				else
					player.HP = player.HP + damage; //positive because damage is already negative in this case.
				printBattleState(player, opponent, p, o);
				if (damage > 0)
					printf("Critical hit! You dealt %.1lf damage to your opponent!\n", damage);
				else
					printf("It backfired! You dealt %.1lf damage to yourself!\n", -damage);
				break;
			case 4: //Forfeit
				player.HP = 0;
				break;
			}
		}
		//Enemy's turn ----------------------------------------
		if (player.HP > 0 && opponent.HP > 0)
		{
			printf("\nOpponent's turn");
			for (int i = 0; i < 5; i++)
			{
				delay(DELAY_TIME);
				printf(".");
			}
			moveChoice = rand() % 3 + 1; //randomly select move
			switch (moveChoice) //logic for player's move choice
			{
			case 1: //Basic attack
				damage = attackDamage(opponent, player);
				player.HP = player.HP - damage;
				printBattleState(player, opponent, p, o);
				printf("Your opponent attacked you for %.1lf damage.", damage);
				break;
			case 2: //Defence 
				player.defence = opponent.defence * DEFENCE_MULTIPLIER;
				printBattleState(player, opponent, p, o);
				printf("Opponent's defence increased by 20%%");
				break;
			case 3: //Special move
				damage = specialDamage(opponent, player);
				if (damage > 0)
					player.HP = player.HP - damage;
				else
					opponent.HP = opponent.HP + damage; //positive because damage is already negative in this case.
				printBattleState(player, opponent, p, o);
				if (damage > 0)
					printf("Critical hit! Your opponent dealt %.1lf damage to you!", damage);
				else
					printf("Your opponents attack backfired! It dealt %.1lf damage to itself!", -damage);
				break;
			}
			for (int i = 0; i < 5; i++)
			{
				printf(".");
				delay(DELAY_TIME);
			}
		}
	}
	if (player.HP <= 0) //end game logic, with trophies
		printf("\nBattle over. You lost.\n");
	else
		printf("\nBattle over. You won!\n");
}