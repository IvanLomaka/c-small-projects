#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define DIM_OUTPUT 2

void caratteri(char s[], int *first, int *last) {
    char output[DIM_OUTPUT + 1];
    char temp;

    int i;
    int found = 0;

    output[DIM_OUTPUT] = '\0';

    for(i = 0; s[i] != '\0' && !found; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            output[0] = s[i];
            found = 1;
        }
    }

    found = 0;

    for(i = strlen(s) - 1; i >= 0 && !found; i--) {
        if(s[i] >= '0' && s[i] <= '9') {
            output[1] = s[i];
            found = 1;
        }
    }

    *first = atoi(output);

    temp = output[0];
    output[0] = output[1];
    output[1] = temp;

    *last = atoi(output);
}

int main(int argc, char *argv[]) {
    int first, last;

    if(argc != 2) return 1;

    caratteri(argv[1], &first, &last);

    printf("%d, %d\n", first, last);

    return 0;
}
