#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *insertElement(Node *list, int n) {
    Node *temp;
    Node *scor;

    temp = malloc(sizeof(Node));
    if(temp == NULL) {
        fprintf(stderr, "Errore: malloc fallita in insertElement\n");
        exit(EXIT_FAILURE);
    }

    temp->next = NULL;
    temp->data = n;

    if (list == NULL) return temp;

    scor = list;

    while (scor -> next != NULL) {
        scor = scor->next;
    }

    scor->next = temp;

    return list;
}

int kcon(Node *list, int k) {
    Node *temp = list;
    int times = 0;
    int next = 0;
    int checked = 0;

    while(temp != NULL) {
        if(temp->data == k && next) {
            checked = 1;
        } else if(temp->data == k) {
            next = 1;
        } else {
            if(next && checked) {
                times ++;
                if(times == 2) return 1;
            }

            next = 0;
            checked = 0;
        }

        temp = temp->next;
    }

    return 0;
}

int knocon(Node *list, int k) {
    Node *temp = list;
    int times = 0;
    int next = 0;
    int checked = 0;

    while(temp != NULL) {
        if(temp->data == k && next) {
            checked = 1;
        } else if(temp->data == k) {
            next = 1;
        } else {
            if(next && !checked) {
                times ++;
                if(times == 2) return 1;
            }

            next = 0;
            checked = 0;
        }

        temp = temp->next;
    }

    return 0;
}

/* Funzione di utilità per creare un nuovo nodo */
Node *creaNodo(int valore) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) {
        fprintf(stderr, "Errore allocazione memoria\n");
        exit(EXIT_FAILURE);
    }
    n->data = valore;
    n->next = NULL;
    return n;
}

/* Esempio di utilizzo e test delle due funzioni */
int main(void) {
    int k = 5;
    /* Costruiamo una lista di esempio: 3 → 5 → 5 → 7 → 5 → 2 */
    Node *head = creaNodo(3);
    head->next = creaNodo(5);
    head->next->next = creaNodo(21);
    head->next->next->next = creaNodo(7);
    head->next->next->next->next = creaNodo(5);
    head->next->next->next->next->next = creaNodo(2);
    head->next->next->next->next->next->next = creaNodo(2);


    /* Test kcon: ci sono due 5 consecutivi? (nel nostro esempio sì: 5 → 5) */
    if (kcon(head, k)) {
        printf("kcon: la lista contiene almeno due occorrenze consecutive di %d\n", k);
    } else {
        printf("kcon: la lista non contiene due occorrenze consecutive di %d\n", k);
    }

    /* Test knocon: ci sono due 5 non consecutivi? 
       (nel nostro esempio sì: primo 5 in posizione 2, secondo 5 in posizione 5) */
    if (knocon(head, k)) {
        printf("knocon: la lista contiene almeno due occorrenze non consecutive di %d\n", k);
    } else {
        printf("knocon: la lista non contiene due occorrenze non consecutive di %d\n", k);
    }

    /* Libera memoria (per brevità, si libera solo head; in un caso reale
       andrebbero liberati tutti i nodi uno a uno) */
    free(head->next->next->next->next->next);
    free(head->next->next->next->next);
    free(head->next->next->next);
    free(head->next->next);
    free(head->next);
    free(head);

    return 0;
}
