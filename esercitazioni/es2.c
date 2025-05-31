#include <stdio.h>
#include <stdlib.h>

int** mallocMatrice(int dim) {
    int **m = (int *)malloc(dim * sizeof(int));
    int i, j;

    if(m) {
        for(i = 0; i < dim; i++) {
            m[i] = (int *)malloc(dim * sizeof(int));

            if(!m[i]) {
                for (j = i - 1; j > -1; j++) {
                    free(m[j]);
                }
                free(m);
                return NULL;
            }
        }
    }
}

int main() {
    int i, j, n, n, n2, somma, found;
    int **m1, **m2;

    printf("inserisci il numero di elementi n:\n");
    scanf("%d", &n);

    m1 = mallocMatrice(n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Inserisci il numero (%d, %d): ",(i + 1), (j + 1));
            scanf("%d", *(*(m1 + i) + j));
        }
    }

    // Da finire

    freeMatrice(n, m1);
}
