#include <stdio.h>

int monotono(int n, int *cifre) {
    int current;
    int prev = -1;
    int check = 1;

    *cifre = 0;

    if(n < 10) {
        *cifre = 1;
        return 1;
    }

    current = n % 10;
    (*cifre)++;
    n /= 10;
    
    while(n > 0) {
        prev = current;
        current = n % 10;
        (*cifre)++;

        if(current >= prev) {
            check = 0;
        }

        n /= 10;
    }

    return check;
}

int main(void) {
    int numero = 123;
    int cifre;
    int risultato = monotono(numero, &cifre);

    printf("Numero di cifre: %d\n", cifre);
    if (risultato)
        printf("%d è strettamente monotono crescente.\n", numero);
    else
        printf("%d NON è strettamente monotono crescente.\n", numero);

    return 0;
}
