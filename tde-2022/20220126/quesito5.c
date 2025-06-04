#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char getValue(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 'V';
    }
    if(c >= 'a' && c <= 'z') {
        return 'C';
    }
    if(c >= '0' && c <= '9') {
        return 'D';
    }

    return 'S';
}

int check(char stin[], char formato[]) {
    int i;

    for (i = 0; stin[i] != '\0'; i++) {
        if(getValue(stin[i]) != formato[i]) return 0;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    if(argc != 3) return 1;

    if(check(argv[1],argv[2])) {
        printf("OK\n");
    } else {
        printf("KO\n");
    }
}
