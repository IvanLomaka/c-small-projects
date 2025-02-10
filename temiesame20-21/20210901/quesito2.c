#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* char2ascii(char c) {
    int byteNumber = (int)c;
    char *biteight = (char *)malloc(sizeof(char) * 9);

    for(int i = 7; i >= 0; i--) {
        biteight[i] = (byteNumber % 2) + '0';
        byteNumber /= 2;
    }

    biteight[8] = '\0';

    return biteight;
}

int main() {
    char stringa[21];
    char *bit;
    int len = 0;
    int i;
    scanf("%s", stringa);
    
    stringa[strcspn(stringa, "\n")] = '\0';

    len = strlen(stringa);

    for(i = 0; i < len; i++) {
        bit = char2ascii(stringa[i]);
        printf("%s", bit);
        free(bit);
    }

    printf("\n");

    return 0;
}
