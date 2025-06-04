#include <stdlib.h>
#include <stdio.h>

int toLower(char c) {
    if(c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    return c;
}

int attacco(char str[]) {
    int check;
    int init;
    char inizio;
    int i;

    int noFail = 1;

    check = 1;
    init = 0;
    for (i = 0; str[i] != '\0' && noFail; i++) {
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            if(check) {
                if(init) {
                    if(toLower(str[i]) != toLower(inizio)) noFail = 0;
                    check = 0;
                } else {
                    init = 1;
                    inizio = str[i];
                    check = 0;
                }
            }
        }

        if(str[i] == ' ') check = 1;
    }

    return noFail;
}

int main(int argc, char *argv[]) {
    int a;

    if(argc != 2) return 1;

    a = attacco(argv[1]);

    printf("%d\n", a);

    return 0;
}
