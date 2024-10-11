#include <stdio.h>
#include <math.h>

int reduce(long int *num) {
    long int sum = 0;

    while (*num > 0) {
        sum += (*num % 10);
        (*num) /= 10;
    }

    return sum;
}

int main(int argc, char const *argv[])
{
    long int num = 123456;
    long int sum = 0;

    if(num < 10) 
        printf("%ld\n", num);
    else {
        while (num > 0 && sum < 10) {
            if (num > 0) sum = reduce(&num);
            if (sum >= 10) {
                num = sum;
                sum = 0;
            }
        }

        printf("%ld\n", sum);
    }

    return 0;
}
