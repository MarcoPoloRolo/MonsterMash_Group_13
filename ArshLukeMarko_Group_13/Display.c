#include "GameFunction.h"
#include "Display.h"

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
	printf("\n /\\_/\\\n");
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
	printf("\n		 /\\_/\\\n");
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

void printBattleState(MONSTSTAT player, MONSTSTAT opponent, int p, int o) //displays the current state to the player
{
	system("@cls||clear");
	//print enemy
	if (opponent.HP >= 0)
		printf("\nOpponent's HP: %d / %d", (int)ceil(opponent.HP), (int)ceil(opponent.maxHP));
	else
		printf("\nOpponent's HP: 0 / %d", (int)ceil(opponent.maxHP));
	bool monsterIsAlive;
	if (opponent.HP > 0)
		monsterIsAlive = true;
	else
		monsterIsAlive = false;
	switch (o)
	{
	case 4:
		printChomp(monsterIsAlive);
		break;
	case 5:
		printTy(monsterIsAlive);
		break;
	case 6:
		printJared(monsterIsAlive);
		break;
	case 7:
		printPorkchop(monsterIsAlive);
		break;
	}
	//print player
	if (player.HP > 0)
		monsterIsAlive = true;
	else
		monsterIsAlive = false;
	switch (p)
	{
	case 0:
		printNibbles(monsterIsAlive);
		break;
	case 1:
		printFelix(monsterIsAlive);
		break;
	case 2:
		printPip(monsterIsAlive);
		break;
	case 3:
		printBaconBoi(monsterIsAlive);
		break;
	}
	if (player.HP >= 0)
		printf("Your HP: %d / %d\n\n", (int)ceil(player.HP), (int)ceil(player.maxHP));
	else
		printf("Your HP: 0 / %d\n\n", (int)ceil(player.maxHP));
}

void printTrophies(int t[])
{
	system("@cls||clear");
	printf("=============== Trophies ================\n");
	printf("\n Chomp - Highest difficulty beaten: ");
	printDifficulty(t[0]);
	printChomp(false);
	printf("\n  Ty - Highest difficulty beaten: ");
	printDifficulty(t[1]);
	printTy(false);
	printf("\n Jared - Highest difficulty beaten: ");
	printDifficulty(t[2]);
	printJared(false);
	printf("\nPorkchop - Highest difficulty beaten: ");
	printDifficulty(t[3]);
	printPorkchop(false);
	printf("\n\nPress any key to go back: ");
	char c;
	c = _getch(); //Waits for a single keypress from the user, then goes back to main()
	system("@cls||clear");
}

void printDifficulty(int i) //Only used by printTrophies function
{
	if (i == 0)
		printf("None");
	else if (i == 1)
		printf("Easy");
	else if (i == 2)
		printf("Normal");
	else
		printf("Hard");
}

void printBattleIntro()
{ //Countdown to add tension
	printf("\nBattle starting in ");
	for (int i = 3; i > 0; i--)
	{
		printf("%d, ", i);	
		delay(DELAY_TIME);
	}
}

void delayBetweenTurns()
{
	for (int i = 0; i < 5; i++)
	{
		delay(DELAY_TIME);
		printf(".");
	}
}

void printBattleEnd(bool playerWon)
{
	if (playerWon)
	{
		printf("\n\nBattle over. You won!\n");
		int r = rand() % 10;
		if (r == 0)
			printf("\nCheat code unlocked: 39772");
		else if (r == 1)
			printf("\nCheat code unlocked: 82650");
		else if (r == 2)
			printf("\nCheat code unlocked : 21567");
		else if (r == 3)
			printf("\nCheat code unlocked: 91659");
		printf("\n\nPress any key to continue: ");
		char c;
		c = _getch();
	}
	else
	{
		printf("\n\nBattle over. You lost.");
		printf("\n\nPress any key to continue: ");
		char c;
		c = _getch();
	}
}