#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cercacerniera(char s1[], char s2[]) {
    int posizione = -1;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i, j;
    int checkC = 1;

    for(i = 0; i < len1; i++) {

        checkC = 0;

        for(j = 0; j < i; j++) {
            if(s1[j] == s2[len2 - i + j]) {
                checkC = 1;
            } else {
                checkC = 0;
                break;
            }
        }

        if(checkC) {
            posizione = len2 - i;
        }
    }

    if(posizione == 0) {
        return -1;
    }

    return posizione;
}

char *cerniera(char s1[], char s2[], int inizio) {
    char *unione = NULL;
    int i = 0;
    int j = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dim = (len2 + len1) - (len2 - inizio) - inizio + 1;

    unione = (char *)malloc(sizeof(char) * dim);
    if(unione == NULL) return NULL;

    for(i = len1 - inizio; i < len1; i++) {
        unione[j] = s1[i];
        j++;
    }

    for(i = 0; i < inizio; i++) {
        unione[j] = s2[i];
        j++;
    }

    unione[j] = '\0';

    return unione;
}

int main(int argc, char *argv[]) {
    char *output = NULL;
    int inizio;

    if(argc > 3) {
        return 1;
    }

    inizio = cercacerniera(argv[1], argv[2]);
    if(inizio != -1) {
        output = cerniera(argv[1], argv[2], inizio);

        printf("%s\n", output);

        free(output);
    }

    return 0;
}
