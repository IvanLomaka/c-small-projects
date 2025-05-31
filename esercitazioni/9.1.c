// 9.1 Scrivi un programma in C che dimostri l’uso basilare dei puntatori. Il
// programma deve dichiarare una variabile intera e assegnarle un valore, dichiarare
// una variabile puntatore che punti alla variabile intera e utilizzare il puntatore per
// accedere e visualizzare il valore della variabile intera, modificare il valore della
// variabile intera e visualizzare il valore della variabile intera dopo la modifica.

#include <stdio.h>

int main() {
    int num = 10;  // Dichiarazione di una variabile intera e assegnazione di un valore
    int* ptr;      // Dichiarazione di un puntatore a un intero

    ptr = &num;    // Il puntatore punta all'indirizzo della variabile intera

    // Visualizza il valore della variabile intera usando il puntatore
    printf("Valore iniziale della variabile intera (usando il puntatore): %d\n", *ptr);

    // Modifica il valore della variabile intera usando il puntatore
    *&num = 20;

    // Visualizza il valore della variabile intera dopo la modifica
    printf("Valore della variabile intera dopo la modifica (usando il puntatore): %d\n", *ptr);

    // Visualizza l'indirizzo della variabile e quello del puntatore
    printf("Indirizzo della variabile intera: %p\n", (void*)&num);
    printf("Indirizzo memorizzato nel puntatore: %p\n", (void*)ptr);

    return 0;
}