#include <stdio.h>
#include <stdlib.h>

int main()
{

    int exp (int base, int power)
    //Exponent Function for Integers
    {
        int i, result = 1;
        for (i=1; i<=power; i++)
        {
            result=result*base;
        }
        return result;

    }

    int digit(int n, int k)
    /*Main Function: Divides int n by 10^(k-1)
    then takes the remainder when that number is
    divided by 10.*/
    {
        int result;
        result = (n/exp(10, k-1))%10;
        return result;
    }

    int number, dgt;
    printf("Enter number:");
    scanf("%d", &number);
    printf("\nEnter digit:");
    scanf("%d", &dgt);
    printf("\nDigit #%d (from the right) is: %d\n\n", dgt, digit(number, dgt));
    return 0;
}
