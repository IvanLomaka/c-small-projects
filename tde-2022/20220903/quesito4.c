#include <stdio.h>

int baseMinima(char stringa[]) {
    int i;
    char c = stringa[0];

    for(i = 0; stringa[i] != '\0'; i++) {
        if(stringa[i] > c) {
            c = stringa[i];
        }
    }

    if(c >= 'A' && c <= 'Z') {
        return c - 'A' + 11;
    }

    if(c >= '0' && c <= '9') {
        return c - '0' + 1;
    }

    return -1;
}

int main(void) {
    char stringa[] = "AB8";
    int base = baseMinima(stringa);
    printf("Base minima: %d\n", base);
    return 0;
}
