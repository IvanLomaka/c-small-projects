#include <stdio.h>

#define CIFRE 10

int cifra(int valore) {
    int numeri[CIFRE] = { 0 };
    int maxValue = 0;
    int i;

    while(valore > 0) {
        numeri[valore % 10] += 1;
        valore /= 10;
    }

    for (i = 0; i < CIFRE; i++) {
        if(numeri[i] >= numeri[maxValue]) maxValue = i;
    }

    return maxValue;
}

int cifrav2(int valore) {
    int numeri[CIFRE] = { 0 };
    int maxEvenValue = 0;
    int maxOddValue = 1;
    int i;

    while(valore > 0) {
        numeri[valore % 10] += 1;
        valore /= 10;
    }

    for (i = 0; i < CIFRE; i += 2) {
        if(numeri[i] > numeri[maxEvenValue]) maxEvenValue = i;
    }

    for (i = 1; i < CIFRE; i += 2) {
        if(numeri[i] >= numeri[maxOddValue]) maxOddValue = i;
    }

    if(numeri[maxEvenValue] >= numeri[maxOddValue]) return maxEvenValue;

    return maxOddValue;
}

int main(void) {
    int valore = 447721;

    int risultato = cifrav2(valore);
    printf("La cifra più frequente è: %d\n", risultato);

    return 0;
}
