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
	printf("\n(\\___/)\n");
	if (status == true)
		printf("( o_o )\n");
	else
		printf("( x_x )\n");
	printf("(\")_(\")\n");
}
void printTy(bool status)
{
	printf("\n/\\__/\\\n");
	if (status == true)
		printf("(=0_0=)\n");
	else
		printf("(=x_x=)\n");
	printf("(\")_(\")_/\n");
}
void printJared(bool status)
{
	printf("\n _____\n");
	if (status == true)
		printf("( ovo )\n");
	else
		printf("( xvx )\n");
	printf("((___))\n");
	printf("  ^ ^\n");
}
void printPorkchop(bool status)
{
	printf("\n /\\_/\\\n");
	if (status == true)
		printf("( 'o' )\n");
	else
		printf("( xox )\n");
	printf("( v v )\n");
}

MONSTSTAT readMonsterFromFile(FILE* fp)
{


}