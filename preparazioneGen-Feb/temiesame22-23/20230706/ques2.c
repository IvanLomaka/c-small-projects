#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int checkSpazio(char a) {
    if(a == ' ') return 1;
    return 0;
}

int checkDown(char a) {
   if(a >= 'a' && a <= 'z') return 1;
    return 0; 
}

int checkUp(char a) {
    if(a >= 'A' && a <= 'Z') return 1;
    return 0;
}

char down(char a) {
   if(a >= 'a' && a <= 'z') return a;
    return a + ('a' - 'A');
}

char up(char a) {
    if(a >= 'A' && a <= 'Z') return a;
    return a - ('a' - 'A');
}

char *capitalizzaVocaboli(char input[]) {
    int len = strlen(input);
    int i = 0;
    int upNext = 1;

    char *output;

    output = malloc(sizeof(char)*(len+1));

    if(output == NULL) return NULL;

    for (i = 0; i < len; i++) {
        if(upNext) {
            if(checkDown(input[i]) || checkUp(input[i])) {
                output[i] = up(input[i]);
                upNext = 0;
            } else {
                output[i] = input[i];
            }
        } else {
            if(checkDown(input[i]) || checkUp(input[i])) {
                output[i] = down(input[i]);
            } else if (checkSpazio(input[i])) {
                output[i] = input[i];
                upNext = 1;
            } else {
                output[i] = input[i];
            }
        }
    }

    output[i] = '\0';
    return output;
}


int main(void) {
    char str[] = "Questo e' un esperimento per l'esercizio IN questione e VErificare se Funziona ";
    
    char *output = capitalizzaVocaboli(str);

    printf("%s\n", output);

    free(output);

    return 0;
}
