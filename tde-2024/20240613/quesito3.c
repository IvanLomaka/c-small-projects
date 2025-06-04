#include <stdio.h>

void pariDispari(int n, int *dispari, int *pari) {
    int ordineDiGrandezza = 1;

    *dispari = 0;
    *pari = 0;

    while(n > 0) {
        *dispari += (n % 10) * ordineDiGrandezza;
        n /= 10;
        *pari += (n % 10) * ordineDiGrandezza;
        n /= 10;
        ordineDiGrandezza *= 10;
    }
}

int main(void) {
    int num = 274820012;
    int pari, dispari;

    pariDispari(num, &dispari, &pari);

    printf("Cifre in posizioni dispari: %d\n", dispari);
    printf("Cifre in posizioni pari:    %d\n", pari);

    return 0;
}
