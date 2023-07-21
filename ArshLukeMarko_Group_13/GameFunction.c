#include "GameFunction.h"
#include "Utility.h"

//Print Monsters
//Players
void printNibbles(bool status)
{
	printf("\n(\\___/)\n");
	if (status == true)
		printf("(='.'=)\n");
	else
		printf("(=x.x=)\n");
	printf("(\")_(\")\n");
}
void printFelix(bool status)
{
	printf("\n/\\__/\\\n");
	if (status == true)
		printf("(=^.^=)\n");
	else
		printf("(=x.x=)\n");
	printf("(\")_(\")_/\n");
}
void printPip(bool status)
{
	printf("\n  ___\n");
	if (status == true)
		printf(" (o>o)\n");
	else
		printf(" (x>x)\n");
	printf("((___))\n");
	printf("  ^ ^\n");
}
void printBaconBoi(bool status)
{
	printf("\n /\\_/\\\n");
	if (status == true)
		printf("( o.o )\n");
	else
		printf("( x.x )\n");
	printf("( u u )\n");
}
//Opponents
void printChomp(bool status)
{
	printf("\n		(\\___/)\n");
	if (status == true)
		printf("		( o_o )\n");
	else
		printf("		( x_x )\n");
	printf("		(\")_(\")\n");
}
void printTy(bool status)
{
	printf("\n		/\\__/\\\n");
	if (status == true)
		printf("		(=0_0=)\n");
	else
		printf("		(=x_x=)\n");
	printf("		(\")_(\")_/\n");
}
void printJared(bool status)
{
	printf("\n		 _____\n");
	if (status == true)
		printf("		( ovo )\n");
	else
		printf("		( xvx )\n");
	printf("		((___))\n");
	printf("		  ^ ^\n");
}
void printPorkchop(bool status)
{
	printf("\n		 /\\_/\\\n");
	if (status == true)
		printf("		( 'o' )\n");
	else
		printf("		( xox )\n");
	printf("		( v v )\n");
}

double attackDamage(MONSTSTAT attacker, MONSTSTAT defender)
{
	return((attacker.attack * defender.defence) + rand()%10);
}

void delay(int ms) //freezes the program for some number of milliseconds
{
	clock_t start_time = clock();
	while (clock() < start_time + ms);
}

void printBattleState(MONSTSTAT player, MONSTSTAT opponent, int p ,  int o) //displays the current state to the player
{
	printf("\nOpponent's HP: %d / %d", (int)ceil(opponent.HP), (int)ceil(opponent.maxHP));
	//print enemy
	bool opponentIsAlive;
	if (opponent.HP > 0)
		opponentIsAlive = true;
	else
		opponentIsAlive = false;
	switch (o)
	{
	case 4:
		printChomp(opponentIsAlive);
		break;
	case 5:
		printTy(opponentIsAlive);
		break;
	case 6:
		printJared(opponentIsAlive);
		break;
	case 7:
		printPorkchop(opponentIsAlive);
		break;
	}
	//print player
	bool playerIsAlive;
	if (player.HP > 0)
		playerIsAlive = true;
	else
		playerIsAlive = false;
	switch (p)
	{
	case 0:
		printNibbles(playerIsAlive);
		break;
	case 1:
		printFelix(playerIsAlive);
		break;
	case 2:
		printPip(playerIsAlive);
		break;
	case 3:
		printBaconBoi(playerIsAlive);
		break;
	}	
	printf("Your HP: %d / %d\n", (int)ceil(player.HP), (int)ceil(player.maxHP));
}
