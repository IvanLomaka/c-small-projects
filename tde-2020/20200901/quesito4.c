#include <stdio.h>
#include <string.h>

int ispangramma(char str[]) {
    int check['Z' - 'A' + 1] = { 0 };
    int i;
    int len = strlen(str);

    for (i = 0; i < len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            check[str[i] - 'A'] = 1;
        }

        if(str[i] >= 'a' && str[i] <= 'z') {
            check[str[i] - 'a'] = 1;
        }
    }

    for (i = 0; i < 'Z' - 'A' + 1; i++) {
        if(check[i] != 1) return 0;
    }

    return 1;
}

int main(void) {
    char *test1 = "A quick brown fox jumps over the lazy dog";
    char *test2 = "There is no easy way out of a problem";
    char *test3 = "The five boxing wizards jump quickly";
    char *test4 = "Missing letters here";
    char *test5 = "Pack my box with five dozen liquor jugs";

    printf("Test 1 atteso: 1: %d\n", ispangramma(test1));
    printf("Test 2 atteso: 0: %d\n", ispangramma(test2));
    printf("Test 3 atteso: 1: %d\n", ispangramma(test3));
    printf("Test 4 atteso: 0: %d\n", ispangramma(test4));
    printf("Test 5 atteso: 1: %d\n", ispangramma(test5));

    return 0;
}
