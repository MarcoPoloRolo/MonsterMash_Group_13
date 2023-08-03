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
void printBoss(bool status)
{
	printf("        <===_-----_===>   \n");
	printf("        V  /  \\ /  \\  V   \n");
	if (status == true)
	{
		printf("      <===|  O   O  |===> \n");
		printf("      V   |   ===   |   V\n");
	}
	else
	{
		printf("      <===|  X   X  |===> \n");
		printf("      V   |   ___   |   V\n");
	}
	printf("       <===\\       /===>  \n");
	printf("       V    -------    V  \n");
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
	if (t[4] > 0)
	{
		printf("\nMagroth has been defeated!\n");
		printBoss(false);
	}
	else
		printf("\nMystery enemy... Not defeated yet");
	printf("\n\nPress any key to go back: ");
	char c;
	c = _getch(); //Waits for a single keypress from the user, then goes back to main()
	soundEffect(L"menuSelection.wav");
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

void printBattleState(MONSTSTAT player, MONSTSTAT opponent, int p, int o) //displays the current state to the player
{
	system("@cls||clear");
	bool monsterIsAlive;
	//print enemy
	if (o == 8) //Boss is printed differently
	{
		//print healthbar
		printf("            Magroth\n");
		printf("================================\n");
		printf("            Health:\n[");
		for (int i = 0; i < ((int)(ceil(opponent.HP) / 10)); i++)
			printf("|");
		for (int i = ((int)(ceil(opponent.maxHP) / 10)); i > ((int)(ceil(opponent.HP) / 10)); i--)
			printf(" ");
		printf("]\n\n");
		//print boss
		if (opponent.HP > 0)
			monsterIsAlive = true;
		else
			monsterIsAlive = false;
		printBoss(monsterIsAlive);
		printf("\n");
	}
	else //Regular enemy
	{
		if (opponent.HP >= 0)
			printf("\nOpponent's HP: %d / %d", (int)ceil(opponent.HP), (int)ceil(opponent.maxHP));
		else
			printf("\nOpponent's HP: 0 / %d", (int)ceil(opponent.maxHP));
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
		soundEffect(L"winningFanfare.wav");
		printf("\n\nBattle over. You won!");
		printf("\n\nCheat code unlocked: 39772");
		printf("\n\nPress any key to continue: ");
		char c;
		c = _getch();
		soundEffect(L"menuSelection.wav");
	}
	else
	{
		soundEffect(L"battleLost.wav");
		printf("\n\nBattle over. You lost.");
		printf("\n\nPress any key to continue: ");
		char c;
		c = _getch();
		soundEffect(L"menuSelection.wav");
	}
}
void printHelpScreen(void)
{
	system("@cls||clear");
	printf("=============== Help Menu ================\n");
	printf("\nAttack  - Deals a small amount of damage to your opponent.");
	printf("\nDefend  - For the rest of the battle, you will take slightly less damage.");
	printf("\n          Becomes less effective each time you use it.");
	printf("\nSpecial - Either deals a large amount of damage to your opponent, or a small amount to yourself.");
	printf("\n          It's risky, but it might be necessary to win.");
	printf("\nForfeit - Give up the battle. Your opponent wins.");
	printf("\n\nPress any key to go back: ");
	char c;
	c = _getch(); //Waits for a single keypress from the user, then goes back to main()
	soundEffect(L"menuSelection.wav");
	system("@cls||clear");
}

void soundEffect(const wchar_t* pszSound) {
	PlaySound(pszSound, NULL, SND_FILENAME);
}