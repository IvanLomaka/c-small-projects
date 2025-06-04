#include <stdlib.h>
#include <stdio.h>

void calcoloQuartili(int nums[], int len, double *q1, double *q2, double *q3) {
    int *numbers;
    int i, j, temp;

    numbers = (int *)malloc(sizeof(int) * len);
    if(numbers != NULL) {
        for(i = 0; i < len; i++) {
            numbers[i] = nums[i];
        }

        for(i = 0; i < len; i++) {
            for(j = 0; j < len - 1; j++) {
                if(numbers[j] > numbers[j + 1]) {
                    temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
        }
    }

    if(len % 2 == 0) {
        *q2 = numbers[len / 2];
    } else {
        *q2 = (numbers[len / 2] + numbers[(len / 2) + 1]) / 2;
    }
    
    if(len % 4 == 0) {
        *q1 = numbers[len / 4];
        *q3 = numbers[(3 * len) / 4];
    } else {
        *q1 = (numbers[len / 4] + numbers[(len / 4) + 1]) / 2;
        *q3 = (numbers[(3 * len) / 4] + numbers[((3 * len) / 4) + 1]) / 2;
    }
    
    free(numbers);
}

int main(void) {
    int dati[] = {12, 7, 3, 21, 13, 8, 9, 5, 15, 18};
    int n = sizeof(dati) / sizeof(dati[0]);
    double q1, q2, q3;

    calcoloQuartili(dati, n, &q1, &q2, &q3);

    printf("Q1: %.2f\n", q1);
    printf("Q2 (mediana): %.2f\n", q2);
    printf("Q3: %.2f\n", q3);

    return 0;
}
