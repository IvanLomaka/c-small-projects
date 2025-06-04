#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char toLower(char c) {
    if(c >= 'A' && c <= 'Z') return c - 'A' + 'a';

    return c;
}

char toUpper(char c) {
    if(c >= 'a' && c <= 'z') return c - 'a' + 'A';

    return c;
}

char *capitalize(char string[]) {
    char *output;
    int len = strlen(string);
    int capitalize = 1;
    int i;

    output = malloc(sizeof(char) * (len + 1));
    if (output == NULL) return NULL;

    for(i = 0; i < len; i++) {
        if (string[i] != ' ' && capitalize) {
            output[i] = toUpper(string[i]);
            capitalize = 0;
        } else if(string[i] == ' ') {
            capitalize = 1;
            output[i] = ' ';
        } else {
            output[i] = toLower(string[i]);
        }

    }

    output[i] = '\0';

    return output;
}

int main(void) {
    char input[] = "Questo e'    un esperimento per l'esercizio IN questione e VErificare se Funziona ";
    char *output = capitalize(input);

    printf("Output:\n%s\n", output);

    free(output);
    return 0;
}

