#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *aggiungi(Node *head, int value) {
    Node *current = NULL;
    Node *agg = NULL;

    agg = malloc(sizeof(Node));

    if(agg == NULL) return NULL;

    agg->value = value;
    agg->next = NULL;

    if(head == NULL) {
        return agg;
    }

    current = head;

    while(current->next != NULL) current = current->next;

    current->next = agg;

    return head;
}

Node *converti(char str[], char sep) {
    Node *head = NULL;

    int val;
    int i;

    i = 0;
    while(str[i] != '\0') {
        val = 0;

        while (str[i] != sep && str[i] != '\0') {
            val = val * 10 + (str[i] - '0');
            i++;
        }
        
        head = aggiungi(head, val);

        if(str[i] == sep) i++;
    }

    return head;
}

void stampaLista(Node *head) {
    while (head != NULL) {
        printf("%d", head->value);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    char *input = "132,34,9121,1,29";
    char sep = ',';

    Node *lista = converti(input, sep);
    Node *tmp;

    printf("Lista risultante:\n");
    stampaLista(lista);

    while (lista != NULL) {
        tmp = lista;
        lista = lista->next;
        free(tmp);
    }

    return 0;
}
