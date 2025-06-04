#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

int valido(char username[], int min, int max, char special[]) {
    int len = strlen(username);
    int lenSpecial = strlen(special);
    int speciale = 0;
    int i, j;

    if(len > max || len < min) return 0;

    for(i = 0; i < len && !speciale; i++) {
        for(j = 0; j < lenSpecial && !speciale; j++) {
            if(username[i] == special[j]) speciale = 1;
        }
    }

    if(speciale) return 1;

    return 0;
}

int main(void) {
    int max = 15;
    int min = 8;
    /*int app;*/
    char special[] = "$#%&";
    char buffer[MAX_LEN + 1];

    do {
        scanf("%20s", buffer);
    } while(!valido(buffer, min, max, special));

    /* app = startApp(buffer)*/
    
    return 0;
}
