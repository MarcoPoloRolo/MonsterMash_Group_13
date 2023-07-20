#define _CRT_SECURE_NO_WARNINGS
#include "GameFunction.h"
#include "Utility.h"

int main() {

	MONSTSTAT monsters[MONSTER_COUNT] = { 0 }; //Creates array and initializes values from read only file
	FILE* fp = fopen(FILENAME, "r");
	for (int i = 0; i < MONSTER_COUNT; i++)
		fscanf_s(fp, "%lf\n%lf\n%lf\n", &monsters[i].hitpoints, &monsters[i].attack, &monsters[i].defence);
	fclose(fp);

	for (int i = 0; i < MONSTER_COUNT; i++) //testing initialization
		printf("Monster %d\n%lf\n%lf\n%lf\n", i, monsters[i].hitpoints, monsters[i].attack, monsters[i].defence);

	//pip attacks porkchop
	monsters[7].hitpoints = monsters[7].hitpoints - (monsters[2].attack * monsters[7].defence);
	printf("Porkchop's HP: %lf\n", monsters[7].hitpoints);
	monsters[7].hitpoints = monsters[7].hitpoints - (monsters[2].attack * monsters[7].defence);
	printf("Porkchop's HP: %lf\n", monsters[7].hitpoints);
	monsters[7].hitpoints = monsters[7].hitpoints - (monsters[2].attack * monsters[7].defence);
	printf("Porkchop's HP: %lf\n", monsters[7].hitpoints);

	return 0;
}

/*taunt ideas:
	EAT MY SHORTS
	Where's you learn that move? Kindergarten?
	Losing is a crime and you're about to go to jail.
	You sounded better with your mouth closed.
	You better scramble like an egg before you get folded like an omelette.
	If I had a dollar for every smart thing you did, I'd be homeless.
	I'm busy right now. Can I ignore you some other time?
	If I wanted to lose this battle, I would set my HP equal to your IQ. */