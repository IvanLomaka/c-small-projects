#include <stdio.h>
#include <stdlib.h>

float** mallocMatrice(int dim) {
    float **m = (float **)malloc(dim * sizeof(float));  // Allocate memory for the rows
    if (m == NULL) {
        return NULL;  // Return NULL if memory allocation fails for rows
    }

    for (int i = 0; i < dim; i++) {
        m[i] = (float *)malloc(dim * sizeof(float));  // Allocate memory for the columns
        if (m[i] == NULL) {
            // Free previously allocated rows and the row pointer array
            for (int j = 0; j < i; j++) {
                free(m[j]);
            }
            
            free(m);
            return NULL;  // Return NULL if memory allocation fails for any row
        }
    }

    return m;  // Return the pointer to the matrix
}


void freeMatrice(int dim, float **m) {
    int i;
    for(i = 0; i < dim; i++) {
        free(m[i]);
    }

    free(m);
}

int main() {
    int size, i, j;
    float **m1;
    float *arr;
    float floatN;

    FILE *file = fopen("serie.txt", "r"); // Open the file for reading
    if (file == NULL) {
        printf("Errore nell'apertura del file: %s\n", "serie.txt");
        return 1;
    }

    // Read the first value as the dimension of the array
    if (fscanf(file, "%d", &size) != 1 || size <= 0) {
        printf("Dimensione non valida nel file!\n");
        fclose(file);
        return 1;
    }

    arr = (float *)malloc((size) * sizeof(float));

    for(i = 0; i < size; i++) {
        fscanf(file, "%f", &arr[i]);
    }

    fclose(file);

    m1 = mallocMatrice(size);

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            m1[i][j] = arr[i] * arr[j];
            printf("%f ", m1[i][j]);
        }

        printf("\n");
    }

    free(arr);
    freeMatrice(size, m1);

    return 0;
}