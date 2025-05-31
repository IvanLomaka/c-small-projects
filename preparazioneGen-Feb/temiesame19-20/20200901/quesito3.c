#include <stdio.h>

int power(int base, int exp) {
    int n = base;
    int i = 0;

    if(exp == 0) return 1;
    if(exp == 1) return base;

    for (i = 1; i < exp; i++) {
        n *= base;
    }

    return n;
}

int checkNarciso(int value, int ordine) {
    int count = 0;
    int backup = value;
    int currentNumber;
    
    while (value > 0) {
        currentNumber = value % 10;
        count += power(currentNumber, ordine);
        value /= 10;
    }

    if(count == backup) return 1;
    
    return 0;
}

void trovanarcisisti(int numero[], int tipo[], int ordine, int lunghezza) {
    int i = 0;

    for (i = 0; i < lunghezza; i++) {
        tipo[i] = checkNarciso(numero[i], ordine);
    }
}

int main() {
    int numero[] = {153, 9474, 9475, 407, 371, 123};
    int lunghezza = sizeof(numero) / sizeof(numero[0]);
    int tipo[lunghezza];
    int ordine = 4; // Modifica a piacere

    trovanarcisisti(numero, tipo, ordine, lunghezza);

    printf("Numeri narcisisti di ordine %d:\n", ordine);
    for (int i = 0; i < lunghezza; i++) {
        if (tipo[i]) {
            printf("%d\n", numero[i]);
        }
    }

    return 0;
}