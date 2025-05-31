#include <stdio.h>
#include <string.h>

void minmaxchar(const char* vocabolo, char* minChar, char* maxChar) {
    int lenVocabolo = strlen(vocabolo);
    int i;

    *minChar = (vocabolo[0] >= 'A' && vocabolo[0] <= 'Z') ? (vocabolo[0] - 'A' + 'a') : vocabolo[0];
    *maxChar = *minChar;

    for (i = 1; i < lenVocabolo; i++) {
        char currentChar = vocabolo[i];
        char lowerChar = (currentChar >= 'A' && currentChar <= 'Z') ? (currentChar - 'A' + 'a') : currentChar;

        if (lowerChar < *minChar) {
            *minChar = lowerChar;
        }
        if (lowerChar > *maxChar) {
            *maxChar = lowerChar;
        }
    }
}

int main(int argc, char* argv[]) {
    char vocabolo[100];
    char minChar, maxChar;

    if(argc < 2) {
        printf("suchka\n");
        return 1;
    }

    strncpy(vocabolo, argv[1], sizeof(vocabolo) - 1);
    vocabolo[sizeof(vocabolo) - 1] = '\0';

    minmaxchar(vocabolo, &minChar, &maxChar);

    printf("Carattere più piccolo: %c\n", minChar);
    printf("Carattere più grande: %c\n", maxChar);

    return 0;
}
