#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *delete(Node *head, int value) {
    Node *current = NULL;
    Node *prev = NULL;
    Node *temp = NULL;

    current = head;

    while(current != NULL) {
        if(current->value == value) {
            temp = current;
            if(prev == NULL) {
                head = head->next;
                current = head;
            } else {
                prev->next = current->next;
                current = current->next;
            }
            free(temp);

            return head;
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

Node *append(Node *head, int value) {
    Node *new = (Node *)malloc(sizeof(Node));
    Node *curr;
    new->value = value;
    new->next = NULL;

    if (head == NULL) return new;

    curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new;
    return head;
}

void stampa(Node *head) {
    while (head != NULL) {
        printf("%d", head->value);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf(" -|\n");
}

void libera(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void minmax(Node *head, int *max, int *min) {
    Node *current = NULL;

    current = head;

    *max = current->value;
    *min = current->value;

    while(current != NULL) {
        if(current->value > *max) *max = current->value;
        if(current->value < *min) *min = current->value;

        current = current->next;
    }
}

Node *trova_mancanti(Node *head) {
    Node *current = NULL;
    Node *new = NULL;
    int min, max, i;

    current = head;

    minmax(head, &max, &min);

    for(i = min; i < max; i++) {
        new = append(new, i);
    }
    
    while(current != NULL) {

        new = delete(new, current->value);

        current = current->next;
    }

    return new;
}

int main(void) {
    Node *codici1 = NULL;
    Node *codici2 = NULL;
    Node *mancanti = NULL;

    codici1 = append(codici1, 2);
    codici1 = append(codici1, 5);
    codici1 = append(codici1, -1);
    codici1 = append(codici1, -4);
    codici1 = append(codici1, 3);

    printf("Codici 1:\n");
    stampa(codici1);

    mancanti = trova_mancanti(codici1);
    printf("Mancanti 1:\n");
    stampa(mancanti);
    libera(codici1);
    libera(mancanti);

    codici2 = append(codici2, 0);
    codici2 = append(codici2, -5);
    codici2 = append(codici2, -1);
    codici2 = append(codici2, -4);
    codici2 = append(codici2, -3);
    codici2 = append(codici2, -2);

    printf("\nCodici 2:\n");
    stampa(codici2);

    mancanti = trova_mancanti(codici2);
    printf("Mancanti 2:\n");
    stampa(mancanti);
    libera(codici2);
    libera(mancanti);

    return 0;
}
