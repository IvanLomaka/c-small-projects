#include <stdlib.h>
#include <stdio.h>

double *distanzalineare(double start, double stop, int numero, int escludiStop) {
    double *output = NULL;
    int i;
    double diff = stop - start;
    double add;

    if(!escludiStop) {
        add = diff / (numero - 1);
    } else {
        add = diff / numero;
    }


    output = (double *)malloc(sizeof(double) * numero);
    if(output == NULL) return NULL;

    for(i = 0; i < numero; i++) {
        output[i] = start + (add * i);
    }

    return output;
}

int main(void) {
    int i;

    double start1 = 2.0, stop1 = 3.0;
    int numero1 = 5, escludiStop1 = 0;

    double start2 = 2.0, stop2 = 3.0;
    int numero2 = 5, escludiStop2 = 1;

    double *result1;
    double *result2;


    result1 = distanzalineare(start1, stop1, numero1, escludiStop1);
    if (result1 != NULL) {
        printf("Test 1 ([start, stop] incluso):\n");
        for (i = 0; i < numero1; i++) {
            printf("%.2f ", result1[i]);
        }
        printf("\n");
        free(result1);
    } else {
        printf("Errore di allocazione in Test 1.\n");
    }

    result2 = distanzalineare(start2, stop2, numero2, escludiStop2);
    if (result2 != NULL) {
        printf("Test 2 ([start, stop) escluso):\n");
        for (i = 0; i < numero2; i++) {
            printf("%.2f ", result2[i]);
        }
        printf("\n");
        free(result2);
    } else {
        printf("Errore di allocazione in Test 2.\n");
    }

    return 0;
}
