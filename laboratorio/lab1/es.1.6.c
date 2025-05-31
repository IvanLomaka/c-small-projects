#include <stdio.h>

#define SIZE 20

int main(int argc, char const *argv[])
{
    int quotazioni[SIZE] = {
        4, -6, 3, 1, 3, -2, 3, -4, 1, -9, 6, 2, 1, -5, 3, 1, 2, 0, -1, -1
    };

    int lowest[3] = {0, 0, 0};
    int i, j, current_price = 18, future_price = 18, profit;
    
    int initial_capital = 100;

    for (i = 0; i < SIZE; i++ ){
        current_price += quotazioni[i];
        future_price = current_price;

        for (j = i + 1; j < SIZE; j++) {
            future_price += quotazioni[j];
            profit = (initial_capital / future_price) * (future_price - current_price);
            
            if(lowest[0] == 0 && (i + 1) == j) {
                lowest[0] = i;
                lowest[1] = j;
                lowest[2] = profit;
            } else if (lowest[2] < profit) {
                lowest[0] = i;
                lowest[1] = j;
                lowest[2] = profit;
            }
        }
    }

     printf("Buy at day %d and sell at day %d for a maximum profit of %d.\n", 
           (lowest[0] + 1), (lowest[1] + 1), lowest[2]);

    return 0;
}
