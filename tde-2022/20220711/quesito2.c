#include <stdlib.h>
#include <stdio.h>

int monotono(int n, int *cifre) {
    int check;
    int current;
    int prev;

    if(n < 10) {
        (*cifre)++;
        return 1;
    }

    current = n % 10;
    (*cifre)++;
    n /= 10;

    check = 1;

    while(n > 0) {
        prev = current;
        current = n % 10;
        (*cifre)++;
        n /= 10;

        if(current <= prev) check = 0;
    }

    return check;
}

int main(void) {
    int numero;
    int num_cifre = 0;
    int risultato;

    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Errore: inserire un numero strettamente positivo.\n");
        return 1;
    }

    risultato = monotono(numero, &num_cifre);

    if (risultato == 1) {
        printf("Il numero %d è monotono decrescente.\n", numero);
    } else {
        printf("Il numero %d NON è monotono decrescente.\n", numero);
    }

    printf("Numero di cifre: %d\n", num_cifre);

    return 0;
}
