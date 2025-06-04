#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minmaxstr(char string[], char *max, char* min) {
    int len = strlen(string);
    int i;

    *max = string[0];
    *min = string[0];

    for (i = 0; i < len; i++) {
        if(string[i] > *max) *max = string[i];
        if(string[i] < *min) *min = string[i];
    }
}

char normalize(char a) {
    if(a >= 'A' && a <= 'Z') return (a - 'A' + 'a');
    return a;
}

void minmaxstrBig(char string[], char *max, char* min) {
    char current = normalize(string[0]);
    int len = strlen(string);
    int i;

    *max = current;
    *min = current;

    for (i = 0; i < len; i++) {
        current = normalize(string[i]);
        if(current > *max) *max = current;
        if(current < *min) *min = current;
    }
}

int main(int argc, char *argv[]) {
    char min;
    char max;

    if(argc < 2) return 1;

    minmaxstrBig(argv[1], &max, &min);

    printf("max: %c, min: %c\n", max, min);

    return 0;
}
