#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 30

int istypo(char voc[], char dig[]) {
    int vocLen = strlen(voc);
    int digLen = strlen(dig);
    int i;
    int counter = 0;

    if(vocLen > digLen) return 0;

    for(i = 0; i < digLen; i++) {
        if(voc[counter] == dig[i]) {
            counter++;
        }
    }

    if(counter == vocLen) return 1;

    return 0;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[MAX_LEN + 2];
    int counter = 0;

    if(argc != 3) return 1;

    fp = fopen(argv[2], "r");

    while(fgets(buffer, MAX_LEN + 2, fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';

        if(istypo(buffer, argv[1])) {
            printf("%s\n", buffer);
            counter++;
        }
    }

    printf("%d\n", counter);

    fclose(fp);

    return 0;
}
