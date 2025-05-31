#include <stdio.h>

int prossimointero(int num) {
    int MAX = 8;
    int nuovoValore = 0;
    int ordineDiGrandezza = 1;

    int helper;

    while(num > 0) {
        helper = (num % 10) + 1;

        if(helper == 8) helper = 0;

        nuovoValore += helper * ordineDiGrandezza;

        ordineDiGrandezza *= 10;
        num /= 10;
    }

    return nuovoValore;
}

int main() {
    int num;
    printf("Inserisci un numero in base 8: ");
    scanf("%d", &num);

    // Chiamata al sottoprogramma prossimointero (da implementare)
    int risultato = prossimointero(num);

    printf("Il numero modificato è: %d\n", risultato);

    return 0;
}
