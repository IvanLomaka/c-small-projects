#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int genera (int c0, int c1, int dim) {
    int numeroFinale = c0 + c1 * 10;
    int nuovaCifra = 0;
    int ordineDiGrandezza = 100;
    int i = 0;

    if(dim < 3) return -1;

    for(i = 3; i <= dim; i++) {
        nuovaCifra = abs(c1 - c0);
        numeroFinale += nuovaCifra * ordineDiGrandezza;

        c0 = c1;
        c1 = nuovaCifra;

        ordineDiGrandezza *= 10;
    }

    return numeroFinale;
}

int main() {
    int c0 = 2, c1 = 5, dim = 5;
    int numero = genera(c0, c1, dim);

    if (numero != -1) {
        printf("Numero bisottratto generato: %d\n", numero);
    } else {
        printf("Non esiste un numero bisottratto con le caratteristiche richieste.\n");
    }

    return 0;
}