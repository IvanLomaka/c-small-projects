#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Dichiarazione del sottoprogramma
char* estraiParteStringa(const char* seq, char ch, int dir) {
    char* buffer = (char*)malloc(strlen(seq) + 1); // Allocazione dinamica
    int i;
    int counter = 0;

    if (buffer == NULL) {
        printf("Errore di allocazione memoria.\n");
        return NULL;
    }

    for (i = 0; seq[i] != '\0'; i++) {
        if (dir % 2 == 0) {
            if (seq[i] == ch) {
                buffer[i] = '\0';
                return buffer;
            }
            buffer[i] = seq[i];
        } else {
            if (seq[i] == ch) {
                buffer[0] = '\0';
                counter = 0;
            } else {
                buffer[counter] = seq[i];
                counter++;
            }
        }
    }
    buffer[counter] = '\0'; // Terminazione della stringa
    return buffer;
}

int main() {
    char seq[] = "abracadabra";
    char ch = 'b';   // Esempio di carattere
    int dir = 5;     // Esempio di direzione (pari)

    // Chiamata al sottoprogramma
    char* result = estraiParteStringa(seq, ch, dir);

    if (result != NULL) {
        // Stampa del risultato
        printf("Risultato: %s\n", result);

        // Libera la memoria allocata
        free(result);
    }

    return 0;
}
