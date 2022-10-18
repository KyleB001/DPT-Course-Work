#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number, guess;
    char reply;

    srand((unsigned int)time(NULL));

    number = rand() % 100 + 1;
    printf("Im thinking of a number between 1 and 100 \n");

    while(guess != number){
        printf("Enter your guess :");
        scanf("%d", &guess);
        if(guess > number){
            printf("lower \n");
        }
        if(guess < number){
            printf("higher \n");
        }
    }
    printf("well done you won the game \n");

    
    // game logic
    printf("please improve this boring game");

    return 0;
}