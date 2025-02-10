#include <stdio.h>
#include <stdlib.h>

typedef struct _slist{
    char * nomefile;
    struct _slist * next;
} slist_t;

int countLines(char nomefile[]) {
    int caratteri = 0;
    FILE *fileSorgente = NULL;
    char c;

    fileSorgente = fopen(nomefile, "r");

    if(fileSorgente == NULL) return -1;

    while((c = fgetc(fileSorgente)) != EOF) caratteri++;

    fclose(fileSorgente);

    return caratteri;
}

slist_t *checkFiles(slist_t *head) {
    if(head == NULL) return NULL;

    int numeroRigheMin = countLines(head->nomefile);
    int numeroRighe;

    slist_t *riferimentoMassimo = head;
    slist_t *current = head;

    while (current != NULL) {
        numeroRighe = countLines(current->nomefile);

        if(numeroRighe != -1 && numeroRighe < numeroRigheMin) {
            numeroRigheMin = numeroRighe;
            riferimentoMassimo = current;
        }

        current = current->next;
    }

    return riferimentoMassimo;
}