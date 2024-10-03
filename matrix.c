#include <stdio.h>
#define ROWS 10
#define COLS 10

int main(int argc, char const *argv[])
{
    int rows, cols;

    for (rows = 1; rows <= ROWS; rows++) {
        for (cols = 1; cols <= COLS; cols++) {
            printf("%d\t", rows * cols);
        }
        printf("\n");
    }

    return 0;
}
