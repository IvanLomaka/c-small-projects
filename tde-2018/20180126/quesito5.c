#include <stdlib.h>
#include <stdio.h>

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

Node *deleteElements(Node *list, int delete) {
    Node *temp;
    Node *current;
    Node *prev = NULL;

    current = list;

    while(current != NULL) {
        if(current->data == delete) {
            if(prev == NULL) {
                list = list->next;
            } else {
                prev->next = current->next;
            }
            temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }

    return list;
}

void printList(Node *list) {
    Node *curr = list;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int count(Node *list, int n) {
    Node *temp;
    int count = 0;

    temp = list;

    while(temp != NULL) {
        if(temp->data == n) count++;
        temp = temp->next;
    }

    return count;
}

Node *deleteWithLimit(Node *head, int val, int limit) {
    if(count(head, val) < limit) return deleteElements(head, val);

    return head;
}

int main(void) {
    Node *mylist = NULL;

    /* Costruiamo una lista di prova: 1 -> 3 -> 2 -> 3 -> 3 -> 4 */
    mylist = insertElement(mylist, 1);
    mylist = insertElement(mylist, 3);
    mylist = insertElement(mylist, 2);
    mylist = insertElement(mylist, 3);
    mylist = insertElement(mylist, 3);
    mylist = insertElement(mylist, 4);

    printList(mylist);

    /* Supponiamo di chiamare deleteWithLimit con val = 3 e limit = 4.
     * In questo esempio, il valore 3 compare 3 volte (che è < 4), 
     * quindi verranno eliminate tutte le occorrenze di 3. */
    mylist = deleteWithLimit(mylist, 3, 4);

    printList(mylist);

    /* Pulizia finale della lista */
    mylist = deleteElements(mylist, 1);
    mylist = deleteElements(mylist, 2);
    mylist = deleteElements(mylist, 4);

    printList(mylist);

    return 0;
}
