#include <stdio.h>

// Main function
int main() {

    // 1. Print using %d (for integers) and \t (for tab spaces)
    int num1 = 10;
    int num2 = 20;
    
    printf("Example of using %%d and \\t in printf:\n");
    printf("num1 = %d\tnum2 = %d\n\n", num1, num2); // Using \t to add tab space

    // 2. Variables in C (integer, float, char)
    int age = 25;
    float height = 5.9;
    char initial = 'J';

    printf("Working with different variables:\n");
    printf("Age: %d, Height: %.1f, Initial: %c\n\n", age, height, initial);

    // 3. Arithmetic Operations with Variables
    int a = 15, b = 4;
    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    int quotient = a / b;
    int remainder = a % b;

    printf("Arithmetic operations on variables:\n");
    printf("a = %d, b = %d\n", a, b);
    printf("Sum: %d + %d = %d\n", a, b, sum);
    printf("Difference: %d - %d = %d\n", a, b, difference);
    printf("Product: %d * %d = %d\n", a, b, product);
    printf("Quotient: %d / %d = %d\n", a, b, quotient);
    printf("Remainder: %d %% %d = %d\n\n", a, b, remainder); // Using %% to print %

    // 4. Using Constants with const and #define
    const int MAX_SIZE = 100;  // Constant using const
    #define PI 3.14159         // Constant using #define

    printf("Constants in C:\n");
    printf("Max Size: %d, PI: %.5f\n\n", MAX_SIZE, PI);

    // 5. Escape Sequences in C
    printf("Escape sequences in C:\n");
    printf("New line: This text is on one line.\nThis text is on another line.\n");
    printf("Tab space: Here is a tab\tbetween this text.\n\n");

    // 6. Arrays in C
    printf("Arrays in C:\n");

    // Array Declaration and Initialization
    int numbers[5] = {1, 2, 3, 4, 5}; // Declare and initialize an array of 5 integers

    // Accessing elements in an array
    printf("First element: %d\n", numbers[0]); // Access first element (index 0)
    printf("Second element: %d\n", numbers[1]); // Access second element (index 1)

    // Modify an element in the array
    numbers[2] = 10; // Change the third element (index 2)
    printf("Modified third element: %d\n\n", numbers[2]); // Output updated value

    // Looping through arrays with a for loop
    printf("Looping through the array 'numbers':\n");
    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
    printf("\n");

    // 7. Multi-dimensional Arrays (2D Arrays)
    printf("2D Arrays (Multi-dimensional arrays):\n");

    // Declare and initialize a 2D array (3x3 matrix)
    int matrix[3][3] = {
        {1, 2, 3},   // First row
        {4, 5, 6},   // Second row
        {7, 8, 9}    // Third row
    };

    // Access and print elements in the 2D array
    printf("Element at [0][0]: %d\n", matrix[0][0]); // First row, first column
    printf("Element at [1][2]: %d\n", matrix[1][2]); // Second row, third column
    printf("Element at [2][1]: %d\n\n", matrix[2][1]); // Third row, second column

    // Nested loops to print a 2D array
    printf("Full 2D array (matrix):\n");
    for (int i = 0; i < 3; i++) { // Loop through rows
        for (int j = 0; j < 3; j++) { // Loop through columns
            printf("%d\t", matrix[i][j]); // Print element with tab space
        }
        printf("\n"); // New line after each row
    }
    printf("\n");

    // 8. Arrays and Functions
    printf("Passing arrays to functions:\n");

    // Function declaration and passing array to it
    void printArray(int arr[], int size); // Function prototype
    printArray(numbers, 5); // Pass the array 'numbers' to the function

    // 9. More on printf with multiple specifiers
    printf("Combining multiple variables in one printf:\n");
    int year = 2024;
    float price = 19.99;
    printf("Year: %d, Price: $%.2f\n\n", year, price); // %.2f to print float with 2 decimal places

    // 10. Assignment and Increment Operations
    int x = 5;
    printf("Original value of x: %d\n", x);
    x += 3; // Same as x = x + 3
    printf("After x += 3, x = %d\n", x);
    x++; // Increment x by 1
    printf("After x++, x = %d\n\n", x);

    // 11. Switch Statement Example (Bonus)
    char operation = '+';
    printf("Using switch with an operation: %c\n", operation);
    int num3 = 10, num4 = 5, result = 0;

    switch (operation) {
        case '+':
            result = num3 + num4;
            break;
        case '-':
            result = num3 - num4;
            break;
        case '*':
            result = num3 * num4;
            break;
        case '/':
            if (num4 != 0) {
                result = num3 / num4;
            } else {
                printf("Division by zero error!\n");
                return 1; // Exit with error
            }
            break;
        default:
            printf("Invalid operation.\n");
            return 1; // Exit with error
    }
    printf("Result of %c operation: %d\n", operation, result);

    return 0;
}

// Function to print the elements of an array
void printArray(int arr[], int size) {
    printf("Printing array from function:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    printf("\n");
}
