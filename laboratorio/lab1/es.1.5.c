#include <stdio.h>
#include <string.h>

#define MAX 50

void rotazione() {
    int a = 1;
}

int main(int argc, char const *argv[])
{
    int numero_rotazione = -1, lunghezza_stringa = -1, i, j;
    char stringa[MAX + 1];
    char stringa1[MAX + 1];

    while(lunghezza_stringa < 0 || lunghezza_stringa > 50) {
        printf("Stringa: ");
    
        scanf("%50s", stringa);

        lunghezza_stringa = strlen(stringa);
    }

    while((numero_rotazione < 0) || (numero_rotazione >= lunghezza_stringa)) {
        printf("Numero rotazione ");
    
        scanf("%d", &numero_rotazione);

        if(numero_rotazione >= lunghezza_stringa) {
            printf("Larger number \n");
        }
    }

    j = 0;

    for (i = (lunghezza_stringa - numero_rotazione); i < lunghezza_stringa; i++) {
        stringa1[j] = stringa[i];

        j++;
    }

    for(i = 0; i < (lunghezza_stringa - numero_rotazione); i++) {
        stringa1[j] = stringa[i];

        j++;
    }

    printf("%s\n", stringa1);

    return 0;
}
