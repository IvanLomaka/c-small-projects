#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 80

int mediaTroncata(char filename[]) {
    FILE *fp = NULL;

    char buffer[MAX_LEN + 2];

    int count;
    int sum;
    int i;
    int currentLen;
    int dim;
    int media;

    fp = fopen(filename, "r");
    if(fp == NULL) return -1;

    count = 0;
    sum = 0;
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        dim = strlen(buffer);
        currentLen = 0;

        for (i = 0; i < dim; i++) {
            if (buffer[i] == '*') {
                currentLen++;
            } else {
                if (currentLen > 0) {
                    sum += currentLen;
                    count++;
                    currentLen = 0;
                }
            }
        }

        if (currentLen > 0) {
            sum += currentLen;
            count++;
        }
    }

    fclose(fp);

    if (count == 0) return 0;

    media = sum / count;

    for(i = 0; i < media; i++) {
        printf("*");
    }

    printf("\n");

    return media;
}

int main(void) {
    int media = mediaTroncata("input.txt");
    if (media >= 0) {
        printf("Media troncata: %d\n", media);
    } else {
        printf("Errore apertura file.\n");
    }
    return 0;
}
