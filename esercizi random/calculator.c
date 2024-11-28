#include <stdio.h>

int main() {
    int num1, num2; char operation;

    printf("Enter the operation you want to execute ('+', '-', '*' or '/'): ");
    scanf(" %c", &operation);

    if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
        printf("Enter the first integer: ");
        scanf("%d", &num1); 

        printf("Enter the second integer: ");
        scanf("%d", &num2);
    }

    switch (operation)
    {
        case '+':
            printf("%d + %d = %d\n", num1, num2,  num1 + num2);
            break;

        case '-':
            printf("%d - %d = %d\n", num1, num2,  num1 - num2);
            break;

        case '*':
            printf("%d * %d = %d\n", num1, num2,  num1 * num2);
            break;

        case '/':
            printf("%d / %d = %d\n", num1, num2,  num1 / num2);
            break;
    
        default:
            printf("You didnt't enter a good operation code \n");
            break;
    }

    return 0;
}