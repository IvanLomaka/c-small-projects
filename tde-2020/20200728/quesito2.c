#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica(char str[]) {
    int len = strlen(str);
    int i;
    int number = 0;
    int special = 0;

    if(len < 8) return 0;

    for(i = 0; i < len; i++) {
        if(i >= 2) {
            if(str[i] == str[i - 1] && str[i - 1] == str[i - 2]) return 0;
        }

        if(str[i] >= '0' && str[i] <= '9') {
            number = 1;
        } else if ((str[i] < 'A' && str[i] > 'Z') || (str[i] < 'a' && str[i] > 'z')) {
            special = 1;
        }
    }

    if(number && special) return 1;

    return 1;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        return 1;
    }

    printf("%d\n", verifica(argv[1]));

    return 0;
}
