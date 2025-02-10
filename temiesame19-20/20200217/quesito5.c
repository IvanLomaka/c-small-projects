#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura per la lista
typedef struct Node {
    int valore;
    struct Node *next;
} Node;

int lunghezzaLista(Node *head) {
    Node *current = head;
    int len = 0;
    
    while(current != NULL) {
        len++;
        current = current->next;
    }

    return len;
}

Node* trovaKesimoDaFine(Node* head, int k) {
    if(head == NULL) return NULL;

    Node *current = head;
    int i;
    int len = lunghezzaLista(head);

    if(len - k < 0) return NULL;
    
    for (i = 0; i < len - k; i++) {
        current = current->next;
    }

    return current;
}

// Funzione di supporto per creare un nuovo Node (opzionale per test)
Node* creaNode(int valore) {
    Node* nuovoNode = (Node*)malloc(sizeof(Node));
    if (!nuovoNode) {
        printf("Errore di allocazione memoria\n");
        exit(1);
    }
    nuovoNode->valore = valore;
    nuovoNode->next = NULL;
    return nuovoNode;
}

// Funzione di supporto per aggiungere un Node in testa alla lista (opzionale per test)
Node* aggiungiInTesta(Node* head, int valore) {
    Node* nuovoNode = creaNode(valore);
    nuovoNode->next = head;
    return nuovoNode;
}

// Funzione di supporto per stampare la lista (opzionale per test)
void stampaLista(Node* head) {
    while (head) {
        printf("%d -> ", head->valore);
        head = head->next;
    }
    printf("NULL\n");
}

int main(void) {
    Node* head = NULL;
    
    // Creazione della lista di esempio: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    head = aggiungiInTesta(head, 5);
    head = aggiungiInTesta(head, 4);
    head = aggiungiInTesta(head, 3);
    head = aggiungiInTesta(head, 2);
    head = aggiungiInTesta(head, 1);

    printf("Lista originale:\n");
    stampaLista(head);

    int k = 2; // Cercare il 2° elemento dalla fine (dovrebbe essere 4)
    Node* risultato = trovaKesimoDaFine(head, k);

    if (risultato) {
        printf("Il %d° elemento dalla fine è: %d\n", k, risultato->valore);
    } else {
        printf("L'elemento %d° dalla fine non esiste nella lista.\n", k);
    }

    return 0;
}
