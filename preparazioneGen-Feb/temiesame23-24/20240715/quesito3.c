#include <stdio.h>

void calcola_cifre_frequenti(int val, int *piu_frequente, int *meno_frequente) {
    int valori[10] = {0};
    int maxFrequenza = 0;
    int minFrequenza = val;
    int i;

    if(val == 0) {
        *piu_frequente = 0;
        *meno_frequente = 0;
        return;
    }

    while(val > 0) {
        valori[val % 10] += 1;

        val /= 10;
    }

    for (i = 0; i < 10; i++) {
        if(minFrequenza > valori[i] && valori[i] > 0) {
            minFrequenza = valori[i];
            *meno_frequente = i;
        }

        if(maxFrequenza < valori[i] && valori[i] > 0) {
            maxFrequenza = valori[i];
            *piu_frequente = i;
        }
    }
}

int main() {
    int val;
    int piu_frequente, meno_frequente;

    // Chiedi all'utente di inserire un valore intero
    printf("Inserisci un numero intero: ");
    scanf("%d", &val);

    // Chiamata al sottoprogramma
    calcola_cifre_frequenti(val, &piu_frequente, &meno_frequente);

    // Stampa dei risultati
    printf("La cifra più frequente in %d è: %d\n", val, piu_frequente);
    printf("La cifra meno frequente in %d è: %d\n", val, meno_frequente);

    return 0;
}
