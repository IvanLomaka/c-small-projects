#include <stdio.h>

void trovaSottosequenzaCrescente(int valori[], int lenValori, int *inizio, int *lunghezza) {
    int i;
    int currentValue = valori[0];
    *inizio = 0;
    *lunghezza = 0;
    int inizioContatore = 0;
    int lunghezzaContatore = 0;
    
    for (i = 0; i < lenValori; i++) {
        if (currentValue > valori[i]) {
            if(lunghezzaContatore > *lunghezza) {
                *lunghezza = lunghezzaContatore;
                *inizio = inizioContatore;
            }
            inizioContatore = i;
            lunghezzaContatore = 1;
        } else {
            lunghezzaContatore += 1;
        }
        
        currentValue = valori[i];
    }

    if (lunghezzaContatore > *lunghezza) {
        *lunghezza = lunghezzaContatore;
        *inizio = inizioContatore;
    }
}

int main() {
    int valori[] = {2, 1, 4, 7, 3, 6, 11, 12, 21, 15, 4, 8};
    int len = sizeof(valori) / sizeof(valori[0]);
    int inizio, lunghezza;

    // Chiamata alla tua funzione per trovare la sottosequenza crescente
    // Passa inizio e lunghezza per ottenere i risultati
    trovaSottosequenzaCrescente(valori, len, &inizio, &lunghezza);

    // Usa inizio e lunghezza per il risultato, ad esempio:
    printf("Sottosequenza inizia a indice: %d, con lunghezza: %d\n", inizio, lunghezza);

    return 0;
}
