#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 30

int compareChar(char uno, char due) {
    uno = (uno >= 'A' && uno <= 'Z') ? uno - 'A' + 'a' : uno;
    due = (due >= 'A' && due <= 'Z') ? due - 'A' + 'a' : due;

    return (uno == due);
}

int compare(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = 0;

    if(len1 != len2) return 1;

    for(i = 0; i < len1; i++) {
        if(compareChar(str1[i], str2[i]) != 1) return 1;
    }

    return 0;
}

int ometti(char *src, char *dest, char voc[]) {
    FILE *sourceFile;
    FILE *destinationFile;
    int counter = 0;
    int dim = MAX_LEN + 1;
    int countDim = 0;
    char *buffer;
    char c;

    buffer = malloc(sizeof(char) * dim);

    sourceFile = fopen(src, "r");
    if(sourceFile == NULL) return -1;

    destinationFile = fopen(dest, "w");
    if(destinationFile == NULL) return -1;

    while((c = fgetc(sourceFile)) != EOF) {
        if(countDim + 2 >= dim) {
            char *tmp = realloc(buffer, sizeof(char) * (dim + 10));
            if (tmp == NULL) {
                free(buffer);
                return -1;
            }
            buffer = tmp;
            dim += 10;
        }

        if (c == ' ' || c == '\n') {
            if (countDim > 0) {
                buffer[countDim] = '\0';
                if (compare(buffer, voc) != 0) {
                    fputs(buffer, destinationFile);
                    fputc(c, destinationFile);
                } else {
                    counter++;
                }
                countDim = 0;
            } else {
                fputc(c, destinationFile);
            }
        } else {
            buffer[countDim++] = c;
        }
    }

    if (countDim > 0) {
        buffer[countDim] = '\0';
        if (strcmp(buffer, voc) != 0) {
            fputs(buffer, destinationFile);
        } else {
            counter++;
        }
    }


    fclose(sourceFile);
    fclose(destinationFile);
    free(buffer);

    return counter;
}

int main(int argc, char *argv[]) {
    int caratteriOmessi;

    if(argc != 4) return 1;

    caratteriOmessi = ometti(argv[argc - 3], argv[argc - 2], argv[argc - 1]);

    printf("Caratteri omessi: %d\n", caratteriOmessi);

    return 0;
}
