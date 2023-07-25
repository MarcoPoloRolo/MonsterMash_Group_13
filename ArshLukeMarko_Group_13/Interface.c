#include "Interface.h"


int mainMenu() {
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