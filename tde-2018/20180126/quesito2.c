#include <stdio.h>

int calcolaDivisori(int n) {
    int numeroDivisori = 0;
    int i;

    for (i = 2; i < (n / 2) + 1; i++) {
        if((n % i) == 0) numeroDivisori ++;
    }

    return numeroDivisori;
}

int main(void) {
    FILE *divisori;
    int numeroDiCoppie = 0;
    int numeroDivisori;
    int input;

    divisori = fopen("ris.txt", "w");
    if(divisori == NULL) {
        return 1;
    }

    if (scanf("%d", &input) != 1) {
        fprintf(stderr, "Errore di input.\n");
        return 1;
    }

    while(input > 0) {
        numeroDiCoppie ++;
        numeroDivisori = calcolaDivisori(input);

        fprintf(divisori, "%d %d\n", input, numeroDivisori);

        if (scanf("%d", &input) != 1) {
            fprintf(stderr, "Errore di input.\n");
            return 1;
        }
    }

    printf("%d\n", numeroDiCoppie);

    fclose(divisori);

    return 0;
}
