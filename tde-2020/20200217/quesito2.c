#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *conta(char info[], char cars[]) {
    int i = 0;
    int j = 0;
    int conteggio = 0;
    int *output;
    int lenCars = strlen(cars);
    int lenInfo = strlen(info);

    output = malloc(sizeof(int) * lenCars);
    if(output == NULL) return NULL;

    for(i = 0; i < lenCars; i++) {
        conteggio = 0;
        
        for(j = 0; j < lenInfo; j ++) {
            if(info[j] == cars[i]) conteggio ++;
        }

        output[i] = conteggio;
    }

    return output;
}

int main(int argc, char *argv[]) {
    int *output;
    int i = 0;
    
    if(argc < 3) return 1;

    output = conta(argv[1], argv[2]);

    while(argv[2][i] != '\0') {
        printf("%c, %d\n", argv[2][i], output[i]);
        i++;
    }

    free(output);

    return 0;
}
