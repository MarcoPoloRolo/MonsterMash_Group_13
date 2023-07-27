#include "GameFunction.h"
#include "Display.h"

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

bool battleStart(MONSTSTAT player, MONSTSTAT opponent, int p, int o, double d)
{
	//Setup
	opponent.attack = opponent.attack * d;
	opponent.defence = opponent.defence * d; //Makes opponent's stats harder or easier depending on difficulty choice
	//Start
	int moveChoice;
	double damage;
	bool skipEnemyTurn;
	while (player.HP > 0 && opponent.HP > 0) //Battle starts
	{
		printBattleState(player, opponent, p, o); //print battle state
		skipEnemyTurn = false;
		//Player's turn ---------------------------------------
		printf("Select a move :\n1. Attack\n2. Defend\n3. Special\n4. Forfeit\n5. Help\n"); //print move options
		if (scanf("%d", &moveChoice))
		{
			switch (moveChoice) //move choice logic
			{
			case 1: //Basic attack
				soundEffect(L"attack.wav");
				damage = attackDamage(player, opponent);
				opponent.HP = opponent.HP - damage;
				printBattleState(player, opponent, p, o);
				printf("You attacked your opponent for %.1lf damage.\n", damage);
				break;
			case 2: //Defence 
				soundEffect(L"Defence.wav");
				player.defence = player.defence * DEFENCE_MULTIPLIER;
				printBattleState(player, opponent, p, o);
				printf("Defence increased by 15%%\n");
				break;
			case 3: //Special move
				damage = specialDamage(player, opponent);
				if (damage > 0)
					opponent.HP = opponent.HP - damage;
				else
					player.HP = player.HP + damage; //positive because damage is already negative in this case.
					
				printBattleState(player, opponent, p, o);
				if (damage > 0) {
					soundEffect(L"critical.wav");
					printf("Critical hit! You dealt %.1lf damage to your opponent!\n", damage);
				}
				else {
					soundEffect(L"backfire.wav");
					printf("It backfired! You dealt %.1lf damage to yourself!\n", -damage);
				}
				break;
			case 4: //Forfeit
				player.HP = 0;
				break;
			case 5: //Help
				soundEffect(L"menuSelection.wav");
				printHelpScreen();
				skipEnemyTurn = true;
				break;
			default:
				printf("\nInvalid input. Please enter a number from 1 to 5.");
				delayBetweenTurns();
				skipEnemyTurn = true;
				break;
			}
		}
		//Enemy's turn ----------------------------------------
		if (player.HP > 0 && opponent.HP > 0 && skipEnemyTurn == false)
		{
			printf("\nOpponent's turn");
			delayBetweenTurns(); //Waits a few seconds before clearing screen for opponent's turn
			moveChoice = rand() % 3 + 1; //randomly select move
			switch (moveChoice)
			{
			case 1: //Basic attack
				soundEffect(L"attack.wav");
				damage = attackDamage(opponent, player);
				player.HP = player.HP - damage;
				printBattleState(player, opponent, p, o);
				printf("Your opponent attacked you for %.1lf damage", damage);
				break;
			case 2: //Defence 
				soundEffect(L"Defence.wav");
				player.defence = opponent.defence * DEFENCE_MULTIPLIER;
				printBattleState(player, opponent, p, o);
				printf("Opponent's defence increased by 15%%");
				break;
			case 3: //Special move
				damage = specialDamage(opponent, player);
				if (damage > 0)
					player.HP = player.HP - damage;
				else
					opponent.HP = opponent.HP + damage; //positive because damage is already negative in this case.
				printBattleState(player, opponent, p, o);
				if (damage > 0) {
					soundEffect(L"critical.wav");
					printf("Critical hit! Your opponent dealt %.1lf damage to you!", damage);
				}
				else {
					soundEffect(L"backfire.wav");
					printf("Your opponents attack backfired! It dealt %.1lf damage to itself!", -damage);
				}
				break;
			}
			if (player.HP > 0 && opponent.HP > 0)
				delayBetweenTurns(); //Delay won't happen if battle is over
		}
	}
	if (player.HP <= 0)
	{
		printBattleEnd(false);
		return(false);
	}
	else
	{
		printBattleEnd(true);
		return(true);
	}
}