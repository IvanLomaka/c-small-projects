#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void meanvarstd(int seq[], int len, double *mean, double *var, double *stdev) {
    double sum = 0.0;
    int i;

    for (i = 0; i < len; i++) {
        sum += seq[i];
    }

    *mean = sum / len;
    sum = 0;

    for (i = 0; i < len; i++) {
        sum += (seq[i] - *mean) * (seq[i] - *mean);
    }

    *var = sum / len;
    *stdev = sqrt(*var);
}

void meanvarstdpos(int seq[], int len, double *mean, double *var, double *stdev) {
    double sum = 0.0;
    int i;
    int newlen = len;

    for (i = 0; i < len; i++) {
        if(seq[i] >= 0) {
            sum += seq[i];
        } else {
            newlen --;
        }
    }

    *mean = sum / newlen;
    sum = 0;

    for (i = 0; i < len; i++) {
        if(seq[i] >= 0) {
            sum += (seq[i] - *mean) * (seq[i] - *mean);
        }
    }

    *var = sum / newlen;
    *stdev = sqrt(*var);
}


int main(void) {
    int seq[] = {4, -2, 7, 0, 3, -5, 10};
    int n = sizeof(seq) / sizeof(seq[0]);

    double mean, var, stdev;

    printf("Tutti i valori:\n");
    meanvarstd(seq, n, &mean, &var, &stdev);
    printf("Media: %.2f, Varianza: %.2f, Deviazione standard: %.2f\n", mean, var, stdev);

    printf("\nSolo valori positivi:\n");
    meanvarstdpos(seq, n, &mean, &var, &stdev);
    printf("Media: %.2f, Varianza: %.2f, Deviazione standard: %.2f\n", mean, var, stdev);

    return 0;
}
