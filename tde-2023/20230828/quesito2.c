#include <stdio.h>

int reduce(int n) {
    int sum = 0;

    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }

    if(sum < 10) return sum;
    return reduce(sum);
}


int main(void) {
    int input = 12345;
    int result;

    result = reduce(input);
    printf("La cifra ridotta è: %d\n", result);

    return 0;
}
