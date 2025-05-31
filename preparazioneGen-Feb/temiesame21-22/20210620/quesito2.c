#include <stdio.h>

// Dichiarazione della funzione monotono
int monotono(int numero, int *numCifre) {
    *numCifre = 0;
    int decrescente = 1;
    int last = -1;

    while(numero > 0) {
        if(last == -1) {
            last = numero % 10;
        } else {
            if(last < (numero % 10)) {
                decrescente = 0;
            }
        }

        numero /= 10;

        *numCifre += 1;
    }

    if(decrescente) {
        return 0;
    } else {
        printf("cazzo %d\n", *numCifre);
        return *numCifre;
    }
}

int main() {
    int numero = 87;
    int numCifre;
    int risultato;

    risultato = monotono(numero, &numCifre);

    printf("Numero: %d\n", numero);
    printf("Risultato: %d\n", risultato);
    printf("Numero di cifre: %d\n", numCifre);

    return 0;
}
