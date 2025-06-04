#include <stdio.h>

double mediaNoDupe(int arr[], int len) {
    double counter;
    int sum;
    int checkAdd;
    int i;
    int j;

    sum = 0;
    counter = 0.0;

    for (i = 0; i < len; i++) {
        checkAdd = 1;

        for(j = 0; j < i && checkAdd; j++) {
            if(arr[i] == arr[j]) checkAdd = 0;
        }

        if(checkAdd) {
            sum += arr[i];
            counter += 1;
        }
    }

    return sum / counter;
}

int main(void) {
    int arr[] = {2, 4, 4, 3};
    int len = sizeof(arr) / sizeof(arr[0]);

    double media = mediaNoDupe(arr, len);
    printf("Media senza duplicati: %.2f\n", media);

    return 0;
}
