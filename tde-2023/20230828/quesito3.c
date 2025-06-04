#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *sottosequenza(char s[], char ch, int dir) {
    char *output;
    int dim = strlen(s);
    int found;
    int index;
    int i;

    output = malloc(sizeof(char) * (dim + 1));
    if(output == NULL) return NULL;

    found = 0;
    if(dir % 2 == 0) {
        for(i = 0; i < dim && !found; i++) {
            if(s[i] != ch) output[i] = s[i];
            else {
                output[i] = '\0';
                found = 1;
            }
        }

        if(!found) output[0] = '\0';
    } else {
        index = 0;
        for(i = dim - 1; i >= 0; i--) {
            if(s[i] == ch) {
                found = 1;
                break;
            }
        }
        if(found && i < dim - 1) {
            for(i = i + 1; i < dim; i++) {
                output[index++] = s[i];
            }
        }
        output[index] = '\0';
    }
    
    return output;
}

int main(void) {
    char seq1[] = "abracadabra";
    char *res;

    res = sottosequenza(seq1, 'b', 5);
    printf("Test 1: %s\n", res);
    free(res);

    res = sottosequenza(seq1, 'b', 4);
    printf("Test 2: %s\n", res);
    free(res);

    res = sottosequenza(seq1, 'a', 15);
    printf("Test 3: %s\n", res);
    free(res);

    return 0;
}
