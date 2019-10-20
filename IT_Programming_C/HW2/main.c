#include <stdio.h>


int main()
{
    int i;
    printf("Enter a two-digit number:");
    scanf("%d", &i);
    i = (i %10)*10 + i / 10;
    if i < 10
    {
         printf("What part of two digit number did you not understand?");
    }
    else if i > 99
    {
        printf("I'm going to pretend you didn't just do that.");
    }
    else
    {
        printf("The reversal is: %d", i);
    }

    return 0;
}
