#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char carattere(char s[]) {
    int dim = strlen(s);
    int half = dim / 2;
    int i, j;
    int check;
    char c;

    for(i = 0; i < half; i++) {
        check = 1;
        c = s[i];

        for(j = half; j < dim; j++) {
            if(c == s[j]) check = 0;
        }

        if(check) return c;
    }

    for(i = half; i < dim; i++) {
        check = 1;
        c = s[i];

        for(j = 0; j < half; j++) {
            if(c == s[j]) check = 0;
        }

        if(check) return c;
    }

    return '\0';
}

int main(int argc, char *argv[]) {
    char c;
    int i;

    if(argc < 2) return 1;

    for(i = 1; i < argc; i++) {
        c = carattere(argv[i]);
        printf("%c\n", c);
    }

    return 0;
}
