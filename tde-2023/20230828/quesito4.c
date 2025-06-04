#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int contaChar(FILE *fp) {
    int conta = 0;
    int c;
    
    while((c = getc(fp))!= EOF) {
        conta++;
    }

    return conta;
}

int main(int argc, char *argv[]) {
    FILE *fp;

    int charMax = -1;
    int indexMax;

    int chars;

    int empty = 0;
    int nonAcess = 0;

    int i;

    if(argc < 2) return 1;

    for(i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");

        if(fp != NULL) {
            chars = contaChar(fp);
            if(chars == 0) {
                empty++;
            }

            if(chars > charMax) {
                indexMax = i;
                charMax = chars;
            }

            fclose(fp);
        } else {
            nonAcess++;
        }
    }

    printf("file in elenco: %d\n", argc - 1);
    printf("file non accessibili: %d\n", nonAcess);
    printf("file vuoti: %d\n", empty);
    printf("nome file di dimensione maggiore: %s\n", argv[indexMax]);
    printf("numero di caratteri del file piu' grande: %d\n", charMax);

    return 0;
}
