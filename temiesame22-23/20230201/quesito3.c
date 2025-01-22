#include <stdio.h>

// Sottoprogramma per alternare le cifre di due numeri
int alternaCifre(int num1, int num2) {
    int risultato = 0;
    int moltiplicatore = 1;

    while (num1 > 0 || num2 > 0) {
        if (num1 > 0) {
            risultato += (num1 % 10) * moltiplicatore;
            num1 /= 10;
            moltiplicatore *= 10;
        }
        if (num2 > 0) {
            risultato += (num2 % 10) * moltiplicatore;
            num2 /= 10;
            moltiplicatore *= 10;
        }
    }

    return risultato;
}

int main() {
    int num1 = 121;
    int num2 = 35365;
    int risultato = alternaCifre(num1, num2);
    printf("Risultato: %d\n", risultato);  // Dovrebbe stampare 35316251
    return 0;
}