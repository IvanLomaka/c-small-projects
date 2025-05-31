#include <stdio.h>
#include <stdlib.h>
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
                printf("%c, %c\n", s1[j], s2[len2 - i + j]);
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

char *concatena(char s1[], char s2[], int index) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    char *stringaFinale = (char *)malloc(sizeof(char) * ((len1 + len2) - (index) - (len2 - index) + 1));

    int i = 0;
    int counter = 0;

    for(i = (len2 - index); i < len1; i++) {
        stringaFinale[counter] = s1[i];
        counter++;
    }

    for(i = 0; i < index; i++) {
        stringaFinale[counter] = s2[i];
        counter++;
    }

    stringaFinale[counter] = '\0';

    return stringaFinale;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        return 1;
    }

    char *stringaFinale;

    // Chiamata alla funzione cercacerniera
    int index = cercacerniera(argv[argc - 2], argv[argc - 1]);
    stringaFinale = concatena(argv[argc - 2], argv[argc - 1], index);

    // Output del risultato
    if (index != -1) {
        printf("%s\n", stringaFinale);
    } else {
        printf("Nessuna cerniera trovata.\n");
    }

    return 0;
}
