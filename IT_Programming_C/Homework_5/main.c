#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int power(int base, int exponent)
    {
        int result = 1;
        int i;
        for (i=0; i<exponent; i++)
        {
            result *= base;
        }

        return result;
    }
    int get_digit(int n, int k)
    {
       int result;
       result = (n/power(10, k-1))%10;
       return result;
    }



    /*int number, digit;
    printf("Please enter number:");
    scanf("%d", &number);
    printf("\nPlease enter digit:");
    scanf("%d", &digit);*/
    //printf("\nDigit #%d is %d", power, get_digit(number, power));
    //printf("%d:%d", number, power);
    //printf("\n%d", power(10, digit - 1));

    return 0;
}
