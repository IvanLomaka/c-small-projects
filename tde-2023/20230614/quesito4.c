#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int i;
    int nR, nC;
    int counterR;
    int counterC;
    int numero;
    int ripetizioni;

    if(argc != 4) return 1;

    nR = atoi(argv[2]);
    nC = atoi(argv[3]);

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    counterC = 0;
    counterR = 0;
    while (fscanf(fp, "%d", &numero) == 1 && nR > counterR) {
        fscanf(fp, "%d", &ripetizioni);

        for(i = 0; i < ripetizioni; i++) {
            if(counterC == nC) {
                printf("\n");
                counterR ++;
                counterC = 0;
            }
            
            if(counterR == nR) break;

            printf("%.3d ", numero);
            counterC ++;
        }
    }

    fclose(fp);
    return 0;
}
