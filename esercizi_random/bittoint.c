#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int N, i, bit, decimale = 0, bit_finale = 0;
    printf("Enter an integer: ");
    
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("Enter first bit: ");
    
        scanf("%d", &bit);

        bit_finale += bit * pow(10, i);
        decimale += pow(2, i) * bit;

        printf("Numero valore bit: %d\n", decimale);
    }


    printf("Numero finale decimale: %d Numero finale bit: %d\n", decimale, bit_finale);

    return 0;
}
