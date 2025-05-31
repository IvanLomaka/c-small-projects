#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatNtimes(char string[], int n) {
    char *output;
    int i = 0;
    int j;
    int z = strlen(string);

    if(n == 0) {
        output = (char *)malloc(sizeof(char));
        if(output == NULL) return NULL;
        output[0] = '\0';
        return output;
    }

    output = (char *)malloc(sizeof(char) * z * n + 1);
    if(output == NULL) return NULL;

    for (i = 0; i < n; i++) {
        for (j = 0; j < z; j++) {
            output[i * z + j] = string[j];
        }
    }

    output[z * n] = '\0';

    return output;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *output;
    
    if(argc < 3) return 1;

    output = concatNtimes(argv[1], atoi(argv[2]));
    
    printf("%s\n", output);

    free(output);

    return 0;
}
