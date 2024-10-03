#include <stdio.h>

int fibonacci(int number) {
    if (number == 0) return 0;
    if (number == 1 || number == 2) return 1;

    return fibonacci(number - 1) + fibonacci(number - 2);
}

int main() {
    int number, result;

    printf("Enter an integerr: ");
    
    scanf("%d", &number);

    result = fibonacci(number);

    printf("The fibonacci return is: %d\n", result);

    return 0;
}