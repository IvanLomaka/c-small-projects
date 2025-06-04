#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 35

int compare(char s1[], char s2[]) {
    int i;

    for(i = 0; s1[i] != '\0'; i++) {
        if(s1[i] != ' ' && s1[i] != s2[i]) return 0;
    }

    return 1;
}

int cerca(FILE *fp, char schema[]) {
    int count = 0;
    char buffer[MAX_LEN + 1];

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';

        if(strlen(schema) == strlen(buffer)) {
            if(compare(schema, buffer)) {
                printf("%s, %s\n", schema, buffer);
                count++;
            }
        }
    }

    return count;
}

int main(void) {
    char schema[MAX_LEN + 1];
    FILE *fp;
    int risultato;

    printf("Inserisci lo schema: ");
    fgets(schema, sizeof(schema), stdin);
    schema[strcspn(schema, "\n")] = '\0';

    fp = fopen("./dizionario.txt", "r");
    if (fp == NULL) {
        printf("Errore apertura file.\n");
        return 1;
    }

    risultato = cerca(fp, schema);
    fclose(fp);

    printf("Numero di vocaboli compatibili: %d\n", risultato);

    return 0;
}
