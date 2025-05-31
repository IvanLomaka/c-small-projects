#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5

int checkMatrix(int matrix[DIM][DIM])
{
    int i;
    int j;
    int z;
    int seen[DIM + 1];
    int val;

    /* Controlliamo le righe */
    for (i = 0; i < DIM; i++)
    {
        for (z = 0; z <= DIM; z++)
        {
            seen[z] = 0;
        }

        for (j = 0; j < DIM; j++)
        {
            val = matrix[i][j];

            if(val < 1 || val > DIM) return 0;
            
            if (seen[val] != 0) return 0;
            
            seen[val] = 1;
        }
    }

    /* Controlliamo le colonne */
    for (i = 0; i < DIM; i++)
    {
        for (z = 0; z <= DIM; z++)
        {
            seen[z] = 0;
        }

        for (j = 0; j < DIM; j++)
        {
            val = matrix[j][i];
            
            if(val < 1 || val > DIM) return 0;
            
            if (seen[val] != 0) return 0;
            
            seen[val] = 1;
        }
    }

    return 1;
}

int main(void)
{
    int mat[5][5];
    int i;
    int j;

    int matrix[DIM][DIM] = {
        { 1, 2, 3, 4, 5 },
        { 2, 3, 4, 5, 1 },
        { 3, 4, 5, 1, 2 },
        { 4, 5, 1, 2, 3 },
        { 5, 1, 2, 3, 4 }
    };

    srand((unsigned)time(NULL));

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            mat[i][j] = (rand() % 6) + 1;
        }
    }

    printf("%d\n", checkMatrix(matrix));

    return 0;
}
