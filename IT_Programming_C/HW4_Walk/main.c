#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 10
#define HEIGHT 10

int main()
{
    srand((unsigned) time(NULL));
    int i, j , x=0, y=0, w=0, z=0, mv = 0;
    char path[HEIGHT][WIDTH];
    char letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for (i=0; i<HEIGHT; i++)
    {
        for (j=0; j<WIDTH; j++)
        {
            path[i][j]='.';
        }
    }
    for (i=0; i<26; i++)
    {
        path[x][y] =  letters[i];
        int check = 0, tried_up = 0, tried_down = 0, tried_left = 0, tried_right = 0;

        while (check==0)
        {
             if ((tried_up == 1)&&(tried_down == 1)&&(tried_left == 1)&&(tried_right == 1))
            {
            printf("   STUCK AT '%c'\n", path[x][y]);
            printf("-------------------\n");
            for (i=0; i<HEIGHT; i++)
            {
                for (j=0; j<WIDTH; j++)
                {
                printf("%c ", path[i][j]);
                }
                printf("\n");
            }
            return 0;
            }
            z=y;
            w=x;
            mv = rand()%4;
            switch (mv)
            {
                case 0:
                    w = x-1;
                    tried_up = 1;
                    break;
                case 1:
                    z = y+1;
                    tried_right = 1;
                    break;
                case 2:
                    w = x+1;
                    tried_down = 1;
                    break;
                case 3:
                    z = y-1;
                    tried_left = 1;
                    break;
            }
            if ((w>-1)&&(w<10)&&(z>-1)&&(z<10)&&(path[w][z]=='.'))
            {
                check = 1;
                x = w;
                y = z;
            }
        }
    }
    printf("     SUCCESS!!!\n");
    printf("-------------------\n");
    for (i=0; i<HEIGHT; i++)
    {
        for (j=0; j<WIDTH; j++)
        {
            printf("%c ", path[i][j]);
        }
        printf("\n");
    }

    return 0;
}
