#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rimuoviInterpunzione(char str[]) {
    int caratteriRimossi = 0;
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i ++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || (str[i] == ' ')) {
            str[i - caratteriRimossi] = str[i];
        } else {
            caratteriRimossi ++;
        }
    }

    str[len - caratteriRimossi] = '\0';

    return caratteriRimossi;
}

int main(void) {
    char testo[] = "Ciao! Mi chiamo Luca, ho 23 anni e studio ingegneria al Politecnico di Milano. Amo programmare, leggere libri (soprattutto di fantascienza), e fare sport: calcio, corsa... e ogni tanto palestra!";

    int rimossi = rimuoviInterpunzione(testo);

    printf("Caratteri rimossi: %d\n", rimossi);
    printf("Testo pulito: %s\n", testo);

    return 0;
}
