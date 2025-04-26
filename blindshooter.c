#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

char* pos[16] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"};

//Prints the battlefield
void print_grid ()
{
    printf("\n _____ _____ _____ _____\n");
    printf("|     |     |     |     |\n");
    printf("|  %s  |  %s  |  %s  |  %s  |\n", pos[0], pos[1], pos[2], pos[3]);
    printf("|_____|_____|_____|_____|\n");
    printf("|     |     |     |     |\n");
    printf("|  %s  |  %s  |  %s  |  %s  |\n", pos[4], pos[5], pos[6], pos[7]);
    printf("|_____|_____|_____|_____|\n");
    printf("|     |     |     |     |\n");
    printf("|  %s  |  %s |  %s |  %s |\n", pos[8], pos[9], pos[10], pos[11]);
    printf("|_____|_____|_____|_____|\n");
    printf("|     |     |     |     |\n");
    printf("|  %s |  %s |  %s |  %s |\n", pos[12], pos[13], pos[14], pos[15]);
    printf("|_____|_____|_____|_____|\n\n");
}

//Checks if the field was hit already
bool check_if_hit (int index)
{
    if (strncmp(pos[index], "X", 1) == 0 || strncmp(pos[index], "X ", 2) == 0) return true;
    else return false;
}

//Marks the field as hit
void mark_as_hit (int index)
{
    if (index > 8) pos[index] = "X ";
    else pos[index] = "X";
}

//Handles computer's turn
int computer_turn (int secret)
{
    int hit;
    do {
        hit = rand() % 16;
    } while (check_if_hit(hit));

    printf("Computer aims for: %d\n", hit+1);
    return hit;
}

//The player won
void win (int secret)
{
    printf("\nYOU WIN!\n");
    printf("You found the target: %d\n", secret);
    printf("You are better than the computer :D\n");
}

//The player lost
void lose (int secret)
{
    printf("\nYOU LOSE!\n");
    printf("Computer found the target: %d\n", secret);
    printf("Computer outplayed you xD\n");
}

int main ()
{
    int target;
    bool turn;
    int num;
    int index;

    //Chooses the target
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    srand(ts.tv_nsec);
    target = rand() % 16;

    printf("BLIND SHOOTER (CLI GAME)\n");
    printf("Find the target before the computer does.\n");
    turn = true;

    while (1)
    {
        if (turn)
        {
            print_grid();
            printf("Your turn.\n");
            printf("What number are you aiming for (1-16): ");
            if (!scanf("%d", &num) || num > 16 || num < 1)
            {
                printf("\nEnter a number from 1 to 16.\n");
                while (getchar() != '\n');
                continue;
            }
            index = num - 1;

            if (check_if_hit(index)) 
            {
                printf("\nAim at target that was not hit yet.\n");
                continue;
            }

            if (index == target)
            {
                win(target+1);
                break;
            }

            mark_as_hit(index);
            printf("You missed!\n");
            turn = false;
        }

        else 
        {
            printf("\nComputer's turn.\n");
            index = computer_turn(target);

            if (index == target)
            {
                lose(target+1);
                break;
            }

            mark_as_hit(index);
            printf("Computer missed!\n");
            turn = true;
        }
    }

    return 0;
}
