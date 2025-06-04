#include <stdio.h>
#include <stdlib.h>

#define MAX 30

char lowest(char string[]) {
    int i;
    char lowest = string[0];

    for(i = 0; string[i] != '\0'; i++) {
        if(lowest > string[i]) lowest = string[i];
    }

    return lowest;
}

void analizza(char string[], char *c, int *n) {
    int i;

    *c = lowest(string);
    *n = 0;

    for(i = 0; string[i] != '\0'; i++) {
        if(*c == string[i]) (*n)++;
    }
}

int main(void) {
    FILE *fp = NULL;
    char filename[] = "./text.txt";
    char buffer[MAX + 1];
    int number;
    char cha;
    int max = 0;

    fp = fopen(filename, "r");
    if(fp == NULL) return 1;

    while(fscanf(fp, "%30s", buffer) == 1) {
        analizza(buffer, &cha, &number);
        printf("%d, %c\n", number, cha);
        if(number > max) max = number;
    }

    printf("%d\n", max);

    fclose(fp);

    return 0;
}
