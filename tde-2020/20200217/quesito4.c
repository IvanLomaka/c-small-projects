#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_FILENAME 300
#define MAX_LEN_ROW 200

void getStats(char bufferRiga[], int *maxC, int *minC, int *phrases) {
    int lenRiga = strlen(bufferRiga);
    int i;
    int lunghezza = 0;
    
    for(i = 0; i < lenRiga; i++) {
        if(bufferRiga[i] != ' ') lunghezza++;
        if(bufferRiga[i] == '.') (*phrases)++;
    }

    if(lunghezza > *maxC) *maxC = lunghezza;
    if(lunghezza < *minC) *minC = lunghezza;
}

int main(int argc, char *argv[]) {
    FILE *filename;
    char bufferInput[MAX_LEN_FILENAME + 1];
    char bufferRiga[MAX_LEN_ROW + 1];

    int maxC = 0;
    int minC = MAX_LEN_ROW;
    int rows = 0;
    int phrases = 0;

    scanf("%s", bufferInput);

    filename = fopen(bufferInput, "r");
    if(filename == NULL) return 1;

    while(fgets(bufferRiga, MAX_LEN_ROW + 1, filename) != NULL) {
        bufferRiga[strcspn(bufferRiga, "\n")] = '\0';

        getStats(bufferRiga, &maxC, &minC, &phrases);
        rows++;
    }

    printf("max %d, min %d, righe %d, frasi %d\n", maxC, minC, rows, phrases);

    return 0;
}
