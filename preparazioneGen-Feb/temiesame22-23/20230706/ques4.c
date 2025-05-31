#include <stdio.h>

#define DIMR 5
#define DIMC 5

void visualizzaCoordinate(int M[][DIMC], int nR, int nC)
{
    int i, j = 0;
    int x, y = 0;

    int sum = 0;

    for (i = 0; i < nR; i++)
    {
        for (j = 0; j < nC; j++)
        {
            sum = 0;

            for (x = -1; x <= 1; x++)
            {
                for (y = -1; y <= 1; y++)
                {
                    if (x == 0 && y == 0) continue;
                    
                    if (i + x >= 0 && i + x < nR && j + y >= 0 && j + y < nC) {
                        sum += M[i + x][j + y];
                    }
                }
            }

            if (M[i][j] == sum)
            {
                printf("%d, %d\n", i, j);
            }
        }
    }
}

int main(void)
{
    int M[DIMR][DIMC] = {
        {1, 2, 1, 4, 5},
        {0, 0, 0, 0, 0},
        {2, 9, 0, 3, 1},
        {1, 5, 1, 1, 8},
        {2, 2, 2, 2, 1}};

    visualizzaCoordinate(M, DIMR, DIMC);

    return 0;
}
