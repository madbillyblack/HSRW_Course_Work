#include <stdio.h>
#include <stdlib.h>

int main()
{
  int power(int x, int n)
    {
        if(n==0)
        {
            return 1;
        }
        else if(n%2==0)
        {
            return power(x,n/2)*power(x, n/2);
        }
        else
        {
            return power(x, n-1)*x;
        }
    }

    int base;
    int exponent;

    printf("Please enter Base x: ");
    scanf("%d", &base);
    printf("\nPlease enter Exponent n: ");
    scanf("%d", &exponent);
    printf("\n%d to the power of %d is %d\n", base, exponent, power(base, exponent));
    return 0;
}
