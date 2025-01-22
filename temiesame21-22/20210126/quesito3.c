#include <stdio.h>

// Dichiarazione del sottoprogramma
int conta_cifre_duplicate(int val) {
    int valori[10] = {0};
    int contatore = 0;
    int i;

    while (val > 0) {
        valori[val % 10] += 1;
        val /= 10;
    }

    for (i = 0; i < 10; i++) {
        if(valori[i] > 1) contatore++;
    }

    return contatore;    
}

int main() {
    int valore;
    int risultato;

    printf("Inserisci un numero intero: ");
    scanf("%d", &valore);

    // Chiamata al sottoprogramma
    risultato = conta_cifre_duplicate(valore);

    // Visualizza il risultato
    printf("Il numero di cifre che compaiono più di una volta è: %d\n", risultato);

    return 0;
}
