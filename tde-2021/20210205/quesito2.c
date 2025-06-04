#include <stdlib.h>
#include <stdio.h>

int baricentro(int arr[], int len) {
    int i;
    int j;
    int sumS;
    int sumD = 0;

    for(i = 0; i < len - 1; i++) {
        sumD += arr[i];
        sumS = 0;

        for(j = i + 1; j < len; j++) {
            sumS += arr[j];
        }

        if(sumD == sumS) return i;
    }

    return -1;
}

int main(void) {
    int arr[] = {2, 4, 1, 3, 3, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    int result = baricentro(arr, len);

    if (result != -1) {
        printf("Il baricentro si trova all'indice: %d\n", result);
    } else {
        printf("Nessun baricentro trovato.\n");
    }

    return 0;
}
