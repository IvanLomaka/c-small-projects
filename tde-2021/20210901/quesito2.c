#include <stdio.h>
#include <stdlib.h>

#define LEN_BIN 8
#define MAX_LEN_STRING 20

char *char2ascii(char c) {
    int i;
    char *output = NULL;

    output = malloc(sizeof(char) * (LEN_BIN + 1));
    if(output == NULL) return NULL;

    for(i = LEN_BIN - 1; i >= 0; i--) {
        output[i] = (c % 2) + '0';
        c /= 2;
    }

    output[LEN_BIN] = '\0';

    return output;
}

void convertString(char string[]) {
    int i;
    char *output;

    for(i = 0; string[i] != '\0'; i ++) {
        output = char2ascii(string[i]);
        if(output != NULL) {
            printf("%s", output);
        }

        free(output);
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    char string[MAX_LEN_STRING + 1];

    scanf("%s", string);

    convertString(string);

    return 0;
}
