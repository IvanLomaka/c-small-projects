#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ISBNDIM 10

int checkISBN10(char ISBN[]) {
    int len = strlen(ISBN);
    int i;
    int j = 0;
    char clean[ISBNDIM + 1];
    int wholeSum = 0;
    int previusSum = 0;

    for(i = 1; i < len; i++) {
        if(ISBN[i] != '-') {
            clean[j] = ISBN[i];
            j++;
        }
    }

    clean[j] = '\0';

    for(i = 0; i < ISBNDIM; i++) {
        previusSum = wholeSum;
        wholeSum += previusSum + clean[i] - '0';
    }

    if(wholeSum % 11 == 0) return 1;

    return 0; 
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        return 1;
    }

    printf("ISBN valido: %d\n", checkISBN10(argv[1]));

    return 0;
}
