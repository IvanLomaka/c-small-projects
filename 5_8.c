#include <stdio.h>

int power(int base, int exp) {
    int i, returning_power = base;

    if (exp == 0) return 1;
    if (exp == 1) return base;

    for (i = 2; i <= exp; i++) {
        returning_power *= base;
    }

    return returning_power;
}

int main(int argc, char const *argv[])
{
    int num = 2416714;
    int iter = 0, i, digit = 0;

    char o = 'x';

    while (num > power(10, digit)) {
        digit++;
    }

    digit--;
    
    while (num > 0) {
        iter = (num / power(10, digit));
        num -= power(10, digit) * iter;

        for (i = 0; i < iter; i++) {
            printf("%c ", o);
        }

        digit --;

        printf("\n");
    }

    return 0;
}
