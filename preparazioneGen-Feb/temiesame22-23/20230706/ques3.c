#include <stdio.h>

int maxContigSum(int v[], int n, int k) {
    int i = 0;
    int j = 0;

    int sum = 0;
    int sommaMax = 0;

    if(k >= n) {
        for (i = 0; i < n; i++) {
            sommaMax += v[i];
        }

        return sommaMax;
    }

    for (i = 0; i <= n - k; i++) {
        for(j = 0; j < k; j++) {
            sum += v[i + j];
        }

        if((i == 0) || sum > sommaMax) {
            sommaMax = sum;
        }

        sum = 0;
    }

    return sommaMax;
}

int main(void) {
    int v[] = {1, 2, -4, 1, 3, -5, 2, 10, -1, 0};
    int n = sizeof(v) / sizeof(v[0]);
    int k = 7;

    int result = maxContigSum(v, n, k);

    printf("Somma massima di %d elementi contigui: %d\n", k, result);

    return 0;
}
