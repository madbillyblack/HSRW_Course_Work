#include <stdio.h>


int main()
{
    int (i);
    printf("Enter a two-digit number:");
    scanf("%d", &i);
    i = (i %10)*10 + i / 10;
    printf("The reversal is: %d", i);
    return 0;
}
