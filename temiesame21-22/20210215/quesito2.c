#include <stdio.h>
#include <string.h>

void check(char tentativo[], char soluzione[], char exit[]) {
    int stringlen = strlen(tentativo);
    char uguale = '=';
    char piu = '+';
    char X = 'X';
    int i, j;
    int trovato = 0;

    for(i = 0; i < stringlen; i++) {
        trovato = 0;

        for(j = 0; j < stringlen; j++) {
            if(!trovato && tentativo[i] == soluzione[j]) {
                if(i == j) exit[i] = '=';
                else exit[i] = '+';
                trovato = 1;
            }
        }

        if(trovato == 0) {
            exit[i] = 'X';
        }
    }
}

int main() {
    char soluzione[26];
    char buffer[26];
    char exit[26];

    scanf("%s", soluzione);

    FILE *fileName;

    fileName = fopen("tentativi.txt", "r");
    if(fileName == NULL) {
        return 1;
    }

    while(fgets(buffer, sizeof(buffer), fileName) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        
        check(soluzione, buffer, exit);
        
        printf("%s\n", buffer);
        printf("%s\n", exit);
    }
}