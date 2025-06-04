#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 25

char *check(char tentativo[], char soluzione[]) {
    char *output = NULL;
    char *soluzioneCopia;
    char dim = strlen(tentativo);
    int i, j;
    int check;

    soluzioneCopia = malloc(sizeof(char) * dim);
    if(soluzioneCopia == NULL) return NULL;
    strcpy(soluzioneCopia, soluzione);

    output = malloc(sizeof(char) * dim);
    if(output == NULL) {
        free(soluzioneCopia);
        return NULL;
    }

    for(i = 0; i < dim; i++) {
        if(soluzioneCopia[i] == tentativo[i]) {
            output[i] = '=';
            soluzioneCopia[i] = '=';
        }
    }

    for(i = 0; i < dim; i++) {
        check = 0;
        if(output[i] != '=') {
            for(j = 0; j < dim && !check; j++) {
                if(soluzioneCopia[j] == tentativo[i]) check = 1;
            }

            if(check) {
                output[i] = '+';
                soluzioneCopia[j] = '+';
            } else {
                output[i] = 'X';
            }
        }
    }

    free(soluzioneCopia);

    return output;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char input[MAX_LEN + 1];
    char *output;
    char buffer[MAX_LEN + 1];
    char filename[] = "./dizionario.txt";

    scanf("%s", input);

    fp = fopen(filename, "r");
    if(fp == NULL) return 1;

    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if(strlen(buffer) == strlen(input)) {
            output = check(buffer, input);
            printf("%s, %s\n", buffer, output);
            free(output);
        }
    }

    fclose(fp);

    return 0;
}
