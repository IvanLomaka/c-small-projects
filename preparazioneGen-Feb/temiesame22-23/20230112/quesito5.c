#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definizione della struttura per un nodo della lista
typedef struct listnode {
    int value;
    struct listnode *next;
} listtype;

// Prototipi delle funzioni fornite
listtype * push(listtype *, int);
listtype * append(listtype *, int);
listtype * increasing(listtype *, int);
listtype * decreasing(listtype *, int);
listtype * pop(listtype *);
listtype * delete(listtype *, int);
listtype * find(listtype *, int);
int length(listtype *);
listtype * emptylist(listtype *);

// Sottoprogramma richiesto
listtype * creaListaDaStringa(const char *str, char sep) {
    listtype *head = NULL;  // Inizializza la testa della lista a NULL
    char temp[256];         // Buffer temporaneo per le sequenze di cifre
    int index = 0;
    int len = strlen(str);

    for (int i = 0; i <= len; i++) {
        if (str[i] == sep || str[i] == '\0') {
            // Fine di una sequenza di cifre o fine della stringa
            temp[index] = '\0';  // Termina la stringa temporanea
            int number = atoi(temp);  // Converte la stringa in un intero
            // si ferma al '\0'
            head = append(head, number);  // Aggiunge il numero alla lista
            index = 0;  // Resetta l'indice per la prossima sequenza
        } else {
            temp[index++] = str[i];  // Aggiunge il carattere al buffer temporaneo
        }
    }

    return head;  // Restituisce la lista costruita
}

// Funzione per stampare la lista (solo per debug)
void printList(listtype *head) {
    listtype *current = head;
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// Funzione principale per testare il sottoprogramma
int main() {
    const char *str = "132,34,9121,1,29";
    char sep = ',';

    listtype *list = creaListaDaStringa(str, sep);
    printList(list);  // Stampa la lista per verificare il risultato

    return 0;
}