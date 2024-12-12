#include <stdio.h>
#include <stdlib.h>

// Function to allocate an array dynamically
int* allocateArray(int n) {
    int *arr = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for n integers
    if (arr == NULL) {
        printf("Memoria non disponibile!\n");
        return NULL;
    }

    // Populate the array with user input
    for (int i = 0; i < n; i++) {
        printf("Inserisci il numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    return arr; // Return the pointer to the allocated memory
}

// Function to find the maximum value in the array
int findMax(int *arr, int n) {
    if (n <= 0 || arr == NULL) {
        printf("Array non valido o dimensione non valida!\n");
        return -1; // Indicate an error
    }

    int max = arr[0]; // Initialize max with the first element
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// Function to free the dynamically allocated memory
void freeArray(int *arr) {
    free(arr);
}

int main() {
    int n, max;
    int *arr;

    // Ask the user for the size of the array
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &n);

    // Allocate the array dynamically
    arr = allocateArray(n);

    // Check if the memory allocation failed
    if (arr == NULL) {
        return 1; // Exit the program if memory is not available
    }

    // Find the maximum value in the array
    max = findMax(arr, n);

    // Print the maximum value
    printf("Il valore massimo nell'array e': %d\n", max);

    // Free the allocated memory
    freeArray(arr);

    return 0;
}
