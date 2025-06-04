#include <stdlib.h>
#include <stdio.h>

void calcoloVettore(double valori[], int lenValori, double pesi[], int lenPesi, int *index, double *values) {
    int i, j;
    double currentSum;

    *index = -1;
    *values = 0.0;

    if(lenPesi <= lenValori) {
        for(i = 0; i <= lenValori - lenPesi; i++) {
            currentSum = 0.0;

            for(j = 0; j < lenPesi; j++) {
                currentSum += valori[i + j] * pesi[j];
            }

            if(currentSum > *values || *index == -1) {
                *index = i;
                *values = currentSum;
            }
        }
    }
}

int main(void) {
    double valori1[] = {1.0, -2.0, 2.5, -5.0};
    double pesi1[] = {-3.0, 5.5};
    double pesi2[] = {-3.0, 5.5, 8.0, 2.1, 4.6};

    int index;
    double value;

    calcoloVettore(valori1, 4, pesi1, 2, &index, &value);
    printf("Indice: %d, Valore: %.2f\n", index, value);

    calcoloVettore(valori1, 4, pesi2, 5, &index, &value);
    printf("Indice: %d, Valore: %.2f\n", index, value);

    return 0;
}
