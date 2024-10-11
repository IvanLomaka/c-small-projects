#include <stdio.h>
#include <math.h>

int main() {
    int num1 = 121;
    int num2 = 35365;
    int sum = 0;
    int digit = 0;
    int running = 1;

    while (running) {

        if (num1 > 0) {
            sum = sum + ((num1 % 10) * pow(10, digit));

            digit ++;
            num1 = num1 / 10;
        }

        if (num2 > 0) {
            sum = sum + ((num2 % 10) * pow(10, digit));

            digit ++;
            num2 = num2 / 10;
        }

        if ((num1 == 0) && (num2 == 0)) running = 0;
    }

    printf("Sum: %d\n", sum);
    return 0;
}