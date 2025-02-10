#include <stdio.h>
#include <stdlib.h>

// Declare the subprogram (you will implement this)
void calculate_quartiles(int arr[], int size, double *q1, double *q2, double *q3) {
    int temp;
    int i,j;

    for(i = 0; i < size; i++) {
        for(j = 0; j < size - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j] = arr[j +1];
                arr[j] = temp;
            }
        }
    }

    q1 = arr[(size / 2) / 2];
    q2 = arr[(size / 2)];
    q3 = arr[(size / 2) + (size / 2) / 2];
}

int main() {
    // Example input array
    int arr[] = {12, 15, 17, 20, 22, 25, 30, 35, 40, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Variables to store the results
    double q1, q2, q3;

    // Call the subprogram to calculate quartiles
    calculate_quartiles(arr, size, &q1, &q2, &q3);

    // Print the results
    printf("First Quartile (Q1): %.2f\n", q1);
    printf("Median (Q2): %.2f\n", q2);
    printf("Third Quartile (Q3): %.2f\n", q3);

    return 0;
}