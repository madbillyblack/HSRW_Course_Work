#include <stdio.h>
#include <stdlib.h>

void decimal(float f, int *whole, int *fraction)
{
    whole = &f;
    *fraction = (f-*whole)*100;
}


int main()
{
    float num;
    int *big, *sml;
    printf("Please enter number:\n");
    scanf("%0.2f", &num);

    decimal(num, big, sml);
    printf("\n%d and %d/100", *big, *sml);

    return 0;
}
