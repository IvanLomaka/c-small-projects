#include <stdio.h>
#include <stdbool.h>

int verifica(int numero) {
    int currentNumber = 0;
    int previusNumber = 10;
    int adiacenti = 0;

    int decrescenti = 1;

    while(numero > 0 && decrescenti) {
        currentNumber = numero % 10;
        printf("Current number: %d, Previus number: %d\n", currentNumber, previusNumber);
        numero /= 10;

        if (currentNumber == previusNumber) {
            adiacenti = 1;
        }

        if (currentNumber <= previusNumber) {
            previusNumber = currentNumber;
        } else {
            decrescenti = 0;
        }

    }

    if (adiacenti == 1 && decrescenti == 1) return 1;

    return 0;
}

int main() {
    // Esempio di utilizzo del sottoprogramma verifica
    int numero = 1223456; // Puoi cambiare questo valore per testare

    if (verifica(numero)) {
        printf("Il numero è una combinazione valida.\n");
    } else {
        printf("Il numero non è una combinazione valida.\n");
    }

    return 0;
}