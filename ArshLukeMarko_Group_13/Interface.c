#include "Interface.h"
#include "Display.h"


int mainMenu()
{
    system("@cls||clear");
    int menuChoice;
    bool validInput = true;
    printf("======= Welcome to the Monster Mash =======\n\n");
    do {
        printf("Please select an option:\n"); //Present options
        printf("1. Play Game\n");
        printf("2. Check Trophies\n");
        printf("3. Exit\n");

        if (scanf_s("%d", &menuChoice) && menuChoice >= 1 && menuChoice <= 3) //Successful input
            return(menuChoice);
        else //Input was not an integer, clear the input buffer and try again
        {
            system("@cls||clear");
            printf("Invalid input. Please enter a number from 1 to 3.\n\n");
            scanf_s("%*[^\n]"); // Clear the input buffer
            validInput = false;
        }
    } while (!validInput);
    return(-1); //In case of unforseen bug
}

int difficultySelection(void)
{
    system("@cls||clear");
    int menuChoice;
    bool validInput = true;
    printf("========== Play Game ==========\n\n");
    do {
        printf("Please select which difficulty:\n"); //Present options
        printf("1. Easy\n");
        printf("2. Normal\n");
        printf("3. Hard\n");

        if (scanf_s("%d", &menuChoice) && menuChoice >= 1 && menuChoice <= 3) //Successful input
            return(menuChoice);
        else //Input was not an integer, clear the input buffer and try again
        {
            system("@cls||clear");
            printf("Invalid input. Please enter a number from 1 to 3.\n\n");
            scanf_s("%*[^\n]"); // Clear the input buffer
            validInput = false;
        }
    } while (!validInput);
    return(-1); //In case of unforseen bug
}

int monsterSelection(void)
{
    system("@cls||clear");
    int menuChoice;
    bool validInput = true;
    printf("========== Monster Selection ==========\n\n");
    do {
        printf("Please select a monster to play as:\n"); //Present options
        printf("\n1. Nibbles");
        printNibbles(true);
        printf("\n2. Felix");
        printFelix(true);
        printf("\n3. Pip");
        printPip(true);
        printf("\n4. BaconBoi");
        printBaconBoi(true);
        printf("\n");
        if (scanf_s("%d", &menuChoice) && menuChoice >= 1 && menuChoice <= 4) //Successful input
            return(menuChoice);
        else //Input was not an integer, clear the input buffer and try again
        {
            system("@cls||clear");
            printf("Invalid input. Please enter a number from 1 to 4.\n\n");
            scanf_s("%*[^\n]"); // Clear the input buffer
            validInput = false;
        }
    } while (!validInput);
    return(-1); //In case of unforseen bug
}