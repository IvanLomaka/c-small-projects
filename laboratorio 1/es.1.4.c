#include <stdio.h>

void triangolo_tartaglia(int n) {
    int triangle[n][n], i, j;

    for (i = 0; i < n; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int num1 = -1, i, j;

    while(num1 < 0 || num1 > 10) {
        printf("Enter a positive number to be displayed: ");
    
        scanf("%d", &num1);
    }

    triangolo_tartaglia(num1);

    return 0;
}
