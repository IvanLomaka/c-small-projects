#include <stdio.h>

// Dichiarazione del sottoprogramma
int sommaCifreSingolaCifra(int valore) {
    int somma = 0;
    int ordineDiGrandezza = 1;
    int valoreCopia = valore;

    while(valoreCopia > 10) {
        valoreCopia /= 10;
        ordineDiGrandezza *= 10;
    }

    printf("Ordine di grandezza: %d", ordineDiGrandezza);

    while(valore > 0) {
        somma += valore / ordineDiGrandezza;
        valore = valore % ordineDiGrandezza;
        ordineDiGrandezza /= 10;
    }

    return somma;
}

int main() {
    int valore = 123;  // Esempio di valore di input

    // Chiamata alla funzione e stampa del risultato
    int risultato = sommaCifreSingolaCifra(valore);
    printf("La somma delle cifre ridotta a una sola cifra è: %d\n", risultato);

    return 0;
}
