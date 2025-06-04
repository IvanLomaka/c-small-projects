#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char toLower(char c) {
    if(c >= 'A' &&  c <= 'Z') return c - 'A' + 'a';
    return c;
}

void minimax(char s[], char *min, char *max) {
    int i;

    *min = toLower(s[0]);
    *max = toLower(s[0]);

    for(i = 0; s[i] != '\0'; i++) {
        if(toLower(s[i]) > toLower(*max)) *max = s[i];
        if(toLower(s[i]) < toLower(*min)) *min = s[i];
    }
}

int main(int argc, char *argv[]) {
    char min, max;

    if(argc != 2) return 1;

    minimax(argv[1], &min, &max);

    printf("%c %c\n", min, max);
}
