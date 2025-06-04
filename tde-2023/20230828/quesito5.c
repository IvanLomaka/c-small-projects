#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Nodo {
    char c;
    struct Nodo *next;
} Nodo;

Nodo *aggiungi(Nodo *head, char c) {
    Nodo *current = head;
    Nodo *add = NULL;

    add = malloc(sizeof(Nodo));

    add->c = c;
    add->next = NULL;

    if(head == NULL) return add;

    while(current->next != NULL) current = current->next;

    current->next = add;

    return head;
}

Nodo *checkLista(Nodo *h1, Nodo *h2) {
    Nodo *c1 = h1;
    Nodo *c2 = h2;
    Nodo *h3 = NULL;
    char ch;

    while(c1 != NULL || c2 != NULL) {
        if(c1 != NULL && c2 != NULL) {
            ch = (c1->c < c2->c) ? c1->c : c2->c;
            h3 = aggiungi(h3, ch);
            c1 = c1->next;
            c2 = c2->next;
        } else if(c1 != NULL) {
            h3 = aggiungi(h3, c1->c);
            c1 = c1->next;
        } else {
            h3 = aggiungi(h3, c2->c);
            c2 = c2->next;
        }
    }

    return h3;
}

void stampaLista(Nodo *head) {
    while (head != NULL) {
        printf("'%c' -> ", head->c);
        head = head->next;
    }
    printf("|\n");
}

Nodo *creaListaDaStringa(char *str) {
    Nodo *head = NULL;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        head = aggiungi(head, str[i]);
    }
    return head;
}

void liberaLista(Nodo *head) {
    Nodo *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void) {
    Nodo *l1, *l2, *l3;

    l1 = creaListaDaStringa("STOPit");
    l2 = creaListaDaStringa("ENCode");
    l3 = checkLista(l1, l2);
    printf("Test 1 - L3:\n");
    stampaLista(l3);
    liberaLista(l1);
    liberaLista(l2);
    liberaLista(l3);

    l1 = creaListaDaStringa("STOPitNow!");
    l2 = creaListaDaStringa("Encode");
    l3 = checkLista(l1, l2);
    printf("Test 2 - L3:\n");
    stampaLista(l3);
    liberaLista(l1);
    liberaLista(l2);
    liberaLista(l3);

    return 0;
}
