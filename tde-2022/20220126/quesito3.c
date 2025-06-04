#include <stdio.h>

#define CIFRE 10

int ripetizioni(int n) {
    int values[CIFRE] = { 0 };
    int numbers;
    int i;

    while(n > 0) {
        values[n % 10] += 1;
        n /= 10;
    }

    numbers = 0;
    for (i = 0; i < CIFRE; i++) {
        if(values[i] >= 2) numbers ++;
    }

    return numbers;
}

int main(void) {
    int numero, risultato;

    numero = 3282821;

    risultato = ripetizioni(numero);

    printf("Numero di cifre ripetute: %d\n", risultato);

    return 0;
}
