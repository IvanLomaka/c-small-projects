#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = NULL;
    int inserire = 0;
    int dimensione = 0;
    int capacità = 2;
    int continua = 1;
    int i = 0;
    int contenuta = 0;

    array = (int *)malloc(capacità * sizeof(int));
    if(array == NULL) {
        printf("Errore locazione di memoria");
        return 1;
    }

    printf("Inserisci valori interi (inserisci 0 per terminare):\n");

    while(continua) {
        scanf("%d", &inserire);

        for(i = 0; i < dimensione; i++) {
            if(array[i] == inserire) contenuta = 1;
        }

        if(!contenuta) {
            array[dimensione] = inserire;
            dimensione++;
        }

        contenuta = 0;

        if(inserire == 0) {
            continua = 0;
        } else {
            if(dimensione == capacità) {
                capacità += 6;
                array = (int *)realloc(array, capacità * sizeof(int));

                if(array == NULL) {
                    printf("Errore locazione di memoria");
                    return 1;
                }
            }
        }
    }

    for(i = 0; i < dimensione; i++) {
        printf("%d - ", array[i]);
    }

    printf("\n");
    free(array);
}