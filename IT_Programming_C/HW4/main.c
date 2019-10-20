#include <stdio.h>
#include <stdlib.h>
#define N 7


int main()
{
   int i, j, tmp, ctr = 0;
   int a[N]={7,0,17,12,1,23,-3};
    printf("Original Array:");
    for(i=0; i<N; i++)
    {
        printf(" %d", a[i]);
    }
    //printf("\nNew Array:\n");
    for (i=0; i<N; i++)
    {
        printf("\n After Pass #%d:", i+1);
        for (j=0; j<N-1-i; j++)
        {
            ctr=ctr+1;
            if(a[j]>a[j+1])
            {
            tmp=a[j];
            a[j]=a[j+1];
            a[j+1]=tmp;
            }
        }
        for (j=0; j<N; j++)
            printf(" %d", a[j]);

    }
    //for(i=0; i<N; i++)
    //{
    //    printf(" %d", a[i]);
    //}
    printf("\n\n");
    printf("Number of checks: %d\n", ctr);
    return 0;
}
