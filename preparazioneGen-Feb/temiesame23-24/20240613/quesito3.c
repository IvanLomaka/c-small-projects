#include <stdio.h>

void disparipari(int value, int *valueDispari, int *valuePari) {
    int ordineDiGrandezza = 1;
    *valueDispari = 0;
    *valuePari = 0;

    while(value > 0) {
        *valueDispari += (value % 10) * ordineDiGrandezza;
        value /= 10;

        if(value > 0) {
            *valuePari += (value % 10) * ordineDiGrandezza;
            value /= 10;
            ordineDiGrandezza *= 10;
        }
    }
}

int main() {
    int num = 274820012;
    int pari, dispari;

    disparipari(num, &dispari, &pari);

    printf("Cifre in posizione pari: %d\n", pari);
    printf("Cifre in posizione dispari: %d\n", dispari);

    return 0;
}