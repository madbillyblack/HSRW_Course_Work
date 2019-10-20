#include <stdio.h>
#include <stdlib.h>
#define N 6

int main()
{
    float quadratic(float variable)
    {
        int i;
        float varacc = 1, result = 0;
        float coefficient[N] = {-3.14, 1, 0, -23, 1.3, 4};

        for (i=0; i<N; i++)
        {

            result+=coefficient[i]*varacc;
            varacc*=variable;
        }
        return result;
    }




    float x;
    printf("Input desired 'x' value for function f(x):");
    scanf("%f", &x);
    printf("\nf(%0.2f) = %0.2f\n\n", x, quadratic(x));
    return 0;
}
