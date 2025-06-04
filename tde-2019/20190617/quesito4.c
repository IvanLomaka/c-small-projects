#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 30
#define MAX_INTEGER_LEN 10

int isPrime(int n) {
    int i;

    if(n < 2) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    
    for(i = 3; i * i <= n; i+=2) {
        if(n % i == 0) return 0;
    }

    return 1;
}

int countPrime(int n) {
    int i;
    int counter = 0;

    for (i = 0; i <= n; i++) {
        if(isPrime(i)) counter++;
    }

    return counter;
}

int main(void) {
    char buffer[MAX_LEN + 1];
    char numberBuffer[MAX_INTEGER_LEN + 1];
    char c;
    int index = 0;
    FILE *fp = NULL;

    scanf("%s", buffer);

    fp = fopen(buffer, "r");
    if(fp == NULL) return 1;

    while((c = fgetc(fp)) != EOF) {
        if(c == ' ') {
            if(index > 0) {
                numberBuffer[index] = '\0';
                printf("%s %d\n", numberBuffer, countPrime(atoi(numberBuffer)));
                index = 0;
            }
        } else {
            numberBuffer[index] = c;
            index++;
        }
    }

    if(index > 0) {
        numberBuffer[index] = '\0';
        printf("%s %d\n", numberBuffer, countPrime(atoi(numberBuffer)));
        index = 0;
    }

    fclose(fp);

    return 0;
}
