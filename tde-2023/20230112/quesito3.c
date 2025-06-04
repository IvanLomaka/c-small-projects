#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 30

int contaCaratteri(FILE *fp) {
    int caratteri = 0;
    char c;

    while((c = fgetc(fp)) != EOF) {
        caratteri += 1;
    }

    return caratteri;
}

int main(void) {
    FILE *fp = NULL;

    char filename[MAX_LEN + 1];
    char maxCaratteriNome[MAX_LEN + 1];

    int check;
    int c;
    int caratteriSum;
    int maxCaratteri;

    check = 1;
    caratteriSum = 0;
    maxCaratteri = 0;
    while(check && scanf("%s", filename) == 1) {
        fp = fopen(filename, "r");
        if(fp != NULL) {
            c = contaCaratteri(fp);

            if(c > maxCaratteri) {
                maxCaratteri = c;
                strcpy(maxCaratteriNome, filename);
            }
            caratteriSum += c;

            fclose(fp);
        } else {
            check = 0;
        }
    }

    printf("MAX CARATTERI NOME: %s, SOMMA CARATTERI: %d\n", maxCaratteriNome, caratteriSum);

    return 0;
}
