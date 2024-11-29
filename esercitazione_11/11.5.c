#include <stdio.h>

int max(int *arr, int dim, int maxValue, int n) {
    if (dim == n) return maxValue;
    
    if (maxValue < arr[n]) {
        maxValue = arr[n];
    }

    return max((int *) arr, dim, maxValue, n + 1);;
}

int main() {
    int arr[6] = {
        1, 2, 23525115, 4, 5, 6
    };
    int maxValue = arr[0];
    int dimension = 6;
    int n = 0;

    printf("%d", max((int *) arr, dimension, maxValue, n));

    return 0;
}