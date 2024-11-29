#include <stdio.h>

int main() {
    int initialNum, num1 = -1, num2 = -1, cifre_num_1 = 0, i;


    while(num1 < 0) {
        printf("Enter a positive number to be displayed: ");
    
        scanf("%d", &num1);
    }

    initialNum = num1;

    do {
        num1 = num1 / 10;
        cifre_num_1 ++;
    } while(num1 > 0);

    printf("%d, %d \n", num1, cifre_num_1);

    while((num2 < 0) || (num2 < cifre_num_1)) {
        printf("Padding spaces ");
    
        scanf("%d", &num2);

        if(num2 < cifre_num_1) {
            printf("Larger number \n");
        }
    }

    for (i = 0; i < (num2 - cifre_num_1); i++) {
        printf("%d", 0);
    }

    printf("%d\n", initialNum);

    return 0;
}