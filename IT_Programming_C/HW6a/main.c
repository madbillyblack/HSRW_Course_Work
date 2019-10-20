#include <stdio.h>
#include <stdlib.h>


int main()
{
    int f(int n)
    {
        if (n==0)
        {
            return 0;
        }
        else
        {
            return f(n-1)+2;
        }
    }

    int g(int n)
    {
        if (n==0)
        {
            return 1;
        }
        else
        {
            return f(g(n-1));
        }
    }
    int a[11];
    int i;
    for (i=0; i<11; i+1)
    {
        a[i] = i;
        printf("\nf(%d) = %d     g(%d) = %d", i, f(i), i, g(i));
    }
    return 0;
}
