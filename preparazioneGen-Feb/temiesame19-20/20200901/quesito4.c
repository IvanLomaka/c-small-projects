#include <stdio.h>
#include <string.h>

char alfabeto(char a) {
    if(a >= 'A' && a <= 'Z') {
        return a - 'A' + 'a';
    }

    return a;
}

int checkPangramma(char string[]) {
    int len = strlen(string);
    int check[26] = {0};
    int i = 0;

    if(len < 26) return 0;

    for(i = 0; i < len; i++) {
        if(string[i] != ' ') {
            string[i] = alfabeto(string[i]);

            check[(string[i] - 'a')] += 1;
        }
    }

    for(i = 0; i < 26; i++) {
        if(check[i] == 0) return 0;
    }

    return 1;
}

int main() {
    char test1[] = "A quick brown fox jumps over the lazy dog";
    char test2[] = "There is no easy way out of a problem";

    printf("Test 1: %d\n", checkPangramma(test1)); // Output: 1
    printf("Test 2: %d\n", checkPangramma(test2)); // Output: 0

    return 0;
}
