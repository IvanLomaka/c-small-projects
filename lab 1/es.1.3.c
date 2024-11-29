#include <stdio.h>

int is_prime(int n) {
    if (n <= 3) {
        return n > 1;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }

    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
        i += 6;
    }

    return 1;
}

int main()
{
    int num1 = -1, is_prime_num = 0;

    while(num1 < 0) {
        printf("Enter a positive number to be displayed: ");
    
        scanf("%d", &num1);
    }

    do {
        is_prime_num = is_prime(num1);

        num1 = num1 / 10;        
    } while(num1 > 0 && is_prime_num);

    printf("%d, is the  final result\n", is_prime_num);

    return 0;
}
