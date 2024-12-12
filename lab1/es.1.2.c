#include <stdio.h>

int main()
{
    int num1 = -1, i, j;

    while(num1 < 0 || (num1 > 0 && num1 > 16)) {
        printf("Enter a positive number to be displayed: ");
    
        scanf("%d", &num1);
    }

    for(i = 1; i <= num1; i++) {
        for (j = num1; j > 0; j--) {
            if (j < (i + 1)) {
                printf("#");
            } else {
                printf(" ");
            }
        }

        printf("  ");

        for (j = 0; j < num1; j++) {
            
            if (j >= i) {
                printf(" ");
            } else {
                printf("#");

            }

        }

        printf("\n");
    }

    return 0;
}
