#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void analizza(char str[], char *lettera, int *conteggio) {
    int strLen = strlen(str);
    int i = 0;

    *lettera = str[0];
    *conteggio = 1;

    for (i = 1; i < strLen; i++) {
        if(*lettera == str[i]) {
            *conteggio += 1;
        }
        if(*lettera > str[i]) {
            *conteggio = 1;
            *lettera = str[i];
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *filename;
    int maxCount = 0;
    char lettera;
    int conteggio;
    char buffer[31];

    if(argc != 2) {
        return 1;
    }

    filename = fopen(argv[argc - 1], "r");
    if(filename == NULL) {
        return 1;
    }

    while(fgets(buffer, sizeof(buffer), filename) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        analizza(buffer, &lettera, &conteggio);

        if(conteggio > maxCount) maxCount = conteggio;
    }

    // Stampa il risultato
    printf("La prima lettera nell'ordine alfabetico è '%c' e compare %d volte.\n", lettera, conteggio);

    return 0;
}
