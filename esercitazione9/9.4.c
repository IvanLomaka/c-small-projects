// 9.4 Scrivi un programma in C che dichiari un array di stringhe, inizializzando
// un array di stringhe (array di puntatori a carattere) con valori predefiniti, come
// nomi di frutta. Utilizza un puntatore a puntatore (char **) per attraversare e
// manipolare l’array di stringhe. Scambia due stringhe nell’array utilizzando una
// funzione che accetta puntatori a puntatori. Esegui le operazioni di visualizzazione
// dell’array originale di stringhe, scambia due stringhe specificate nell’array
// e visualizza l’array dopo lo scambio.

#include <stdio.h>

// Funzione per scambiare due stringhe utilizzando puntatori a puntatori
void scambiaStringhe(char** str1, char** str2) {
    char* temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int main() {
    // Inizializzazione di un array di stringhe
    const char* frutta[] = {
        "Mela",
        "Banana",
        "Arancia",
        "Pera",
        "Uva"
    };

    // Calcolo del numero di elementi nell'array
    int numFrutta = sizeof(frutta) / sizeof(frutta[0]);

    // Puntatore a puntatore per attraversare l'array
    char** ptr = (char**)frutta;

    // Stampa dell'array originale
    printf("Array originale:\n");
    for (int i = 0; i < numFrutta; i++) {
        printf("%d. %s\n", i + 1, *(ptr + i));
    }

    // Specifica degli indici delle stringhe da scambiare
    int indice1, indice2;
    printf("\nInserisci due indici da scambiare (1-%d): ", numFrutta);
    scanf("%d %d", &indice1, &indice2);

    // Validazione degli indici
    if (indice1 < 1 || indice1 > numFrutta || indice2 < 1 || indice2 > numFrutta) {
        printf("Indici non validi. Terminazione programma.\n");
        return 1;
    }

    // Scambio delle stringhe
    scambiaStringhe(&ptr[indice1 - 1], &ptr[indice2 - 1]);

    // Stampa dell'array dopo lo scambio
    printf("\nArray dopo lo scambio:\n");
    for (int i = 0; i < numFrutta; i++) {
        printf("%d. %s\n", i + 1, *(ptr + i));
    }

    return 0;
}
