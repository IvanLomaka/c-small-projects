#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *max(char stringa[]) {
    int lenStringa = strlen(stringa);
    int i = 0;

    int dimensioneSottostringa = 0;
    char *sottoStringa = (char *)malloc(sizeof(char) * (lenStringa + 1));
    if(sottoStringa == NULL) return NULL;

    int dimMaxSottostringa = 0;
    char *maxSottostringa = NULL;

    for (i = 0; i < lenStringa; i++) {
        if(stringa[i] == ' ') {
            sottoStringa[dimensioneSottostringa] = '\0';
            if(dimensioneSottostringa > dimMaxSottostringa) {
                if(maxSottostringa != NULL) free(maxSottostringa);

                dimMaxSottostringa = dimensioneSottostringa;
                maxSottostringa = (char *)malloc(sizeof(char) * (dimensioneSottostringa + 1));
                if(maxSottostringa == NULL) return NULL;
                strcpy(maxSottostringa, sottoStringa);
            }

            dimensioneSottostringa = 0;
        } else {
            sottoStringa[dimensioneSottostringa] = stringa[i];
            dimensioneSottostringa ++;
        }
    }

    if(dimensioneSottostringa > dimMaxSottostringa) {
        sottoStringa[dimensioneSottostringa + 1] = '\0';
        if(dimensioneSottostringa > dimMaxSottostringa) {
            if(maxSottostringa != NULL) free(maxSottostringa);

            dimMaxSottostringa = dimensioneSottostringa;
            maxSottostringa = (char *)malloc(sizeof(char) * (dimensioneSottostringa + 1));
            if(maxSottostringa == NULL) return NULL;
            strcpy(maxSottostringa, sottoStringa);
        }
    }

    return maxSottostringa;
}

int main() {
    char stringa[] = "questa frase viene utilizzata per collaudare il sottoprogramma che avete sviluppato e vedere se si comporta correttamente";
    char *maxSottostringa;

    maxSottostringa = max(stringa);

    printf("%s\n", maxSottostringa);

    return 0;
}