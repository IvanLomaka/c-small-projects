#include <stdio.h>

void visualizzaFormato(int val, char car) {
    int ordineDiGrandezza = 1;
    int copiaVal = val;
    int loopIteration = 0;
    int i = 0;

    // capisco ordine di grandezza di val
    while (copiaVal > 10) {
        copiaVal = (copiaVal / 10);
        ordineDiGrandezza *= 10;
    }

    while(ordineDiGrandezza > 0) {
        loopIteration = val / ordineDiGrandezza;
        val = val % ordineDiGrandezza;
        ordineDiGrandezza /= 10;

        for (i = 0; i < loopIteration; i++) {
            printf("%c", car);
        }

        printf("\n");
    }
}

int main() {
    int val = 2421451;  // Esempio di valore
    char car = '*';   // Esempio di carattere

    // Chiamata alla funzione che visualizza val nel formato richiesto
    visualizzaFormato(val, car);

    return 0;
}
