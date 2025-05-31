#include <stdio.h>

int maxComuneDivisore(int a, int b, int maxDivisore, int divisore) {
    if (divisore > a || divisore > b) return maxDivisore;

    if ((a % divisore == 0) && (b % divisore == 0)) {
        maxDivisore = divisore;
    }

    return maxComuneDivisore(a, b, maxDivisore, divisore + 1);
}

int main() {
    int a = 17;
    int b = 34;
    int maxDivisore, divisore = 1;

    printf("%d\n", maxComuneDivisore(a, b, maxDivisore, divisore));

    return 0;
}