#include <stdio.h>
#include <stdlib.h>
#define N 40

int main()
{
    int i = 0;
    int fib[N] = {1, 1};
    for (i=2; i<N; i++)
        fib[i]=fib[i-2]+fib[i-1];
    printf("Fibonacci's Sequence:\n");
    for (i=0; i<N; i++)
        printf("%d\n", fib[i]);
    return 0;
}
