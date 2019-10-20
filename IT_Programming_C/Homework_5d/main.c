#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{

    float ave(int a[], int n)
    {
        int i;
        float sum = 0;

        for (i=0; i<n; i++)
        {
            sum = sum + a[i];
        }
        return sum/n;
    }

    int neg(int a[], int n)
    {
        int i, sum = 0;
        for (i=0; i<n; i++)
        {
            if(a[i]<0)
            {
                sum = sum + 1;
            }
        }
        return sum;
    }

    int sm(int a[], int n)
        {
        int i, min = a[0];
        for(i=1; i<n; i++)
        {
            if (min>a[i])
            {
                min=a[i];
            }
        }
        return min;
        }

    int arr[N] = {10,-9,8,-7,6,-5,4,-3,2,-1};

    printf("ARRAY:\n");

    int i;
    for (i=0; i<N; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nArray average: %0.2f", ave(arr,N));
    printf("\n\nQuantity of Negative Numbers in Array: %d ", neg(arr,N));
    printf("\n\nMinimum Value in Array: %d \n", sm(arr,N));
    return 0;
}
