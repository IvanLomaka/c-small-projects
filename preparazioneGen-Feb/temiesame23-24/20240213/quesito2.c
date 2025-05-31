#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calibra(char seq[], int *valor1, int *valor2) {
    char valore[3] = {'A', 'A', '\0'};
    char scambio;
    int i;

    for (i = 0; i < strlen(seq); i++) {
        if (seq[i] >= '0' && seq[i] <= '9') {
            if(valore[0] == 'A') {
                valore[0] = seq[i];
            } else {
                valore[1] = seq[i]; 
            }
        }
    }

    // scambio
    *valor1 = atoi(valore);

    scambio = valore[0];
    valore[0] = valore[1];
    valore[1] = scambio;

    *valor2 = atoi(valore);
}

int main() {
    // Stringa di esempio
    char seq[] = "a1b2c3d4e5f6";

    // Dichiarazione delle variabili per i risultati
    int valore1, valore2;

    // Chiamata al sottoprogramma calibra (presumendo sia già implementato)
    calibra(seq, &valore1, &valore2);

    // Stampa dei risultati
    printf("Valore 1: %d\n", valore1);
    printf("Valore 2: %d\n", valore2);

    return 0;
}
