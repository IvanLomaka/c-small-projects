#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"

#define MAX_STR_LEN 50
#define MAX_WRD_LEN 30

// Funzione per pulire la console
void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Funzione per copiare una lista
parola_t* copiaLista(parola_t *lista) {
    parola_t *current = lista;
    parola_t *copia = NULL;

    while(current != NULL) {
        copia = inserisciInCoda(copia, current->parola);
        current = current->next;
    }

    return copia;
}

// Funzione per rimuovere i duplicati da una lista
parola_t* rimuoviDuplicati(parola_t *lista) {
    parola_t *current = lista;
    parola_t *copia = NULL;

    while(current != NULL) {
        if (!esisteElemento(copia, current->parola)) {
            copia = inserisciInCoda(copia, current->parola);
        }

        current = current->next;
    }

    return copia;
}

// Funzione per chiedere il nome di un file e leggerlo e metterlo in una lista e creare una lista senza duplicati
void askFile(parola_t **lista, parola_t **listaNoDuplicati) {
    int goodFile = 1, size, addingWords = 1;
    size_t fileLen, parolaLen;
    char fileName[MAX_STR_LEN + 2];
    char parola[MAX_WRD_LEN + 1];

    // 0 finishes the loop
    while(goodFile) {

        printf("Enter a filename (max %d characters): ", MAX_STR_LEN);

        if (fgets(fileName, sizeof(fileName), stdin)) {
            // Remove the newline character if present
            fileLen = strlen(fileName);
            if (fileName[fileLen - 1] == '\n') {
                fileName[fileLen - 1] = '\0';
                fileLen--;
            }

            // Check if the input length exceeds the limit
            if (fileLen > MAX_STR_LEN) {
                printf("Error: Input exceeds %d characters.\n", MAX_STR_LEN);
            } else {
                printf("You entered: %s\n", fileName);

                FILE *file = fopen(fileName, "r"); // Open the file for reading
                if (file == NULL) {
                    printf("Errore nell'apertura del file: %s\n", fileName);
                } else {
                    // Attempt to read a word from the file
                    while (fscanf(file, "%30s", parola) == 1) {
                        // printf("Read word: %s\n", parola);
                        for (int i = 0; i < strlen(parola); i++) {
                            parola[i] = tolower(parola[i]);
                        }

                        *lista = inserisciInCoda(*lista, parola);
                    }

                    if (feof(file)) {
                        printf("End of file reached.\n");
                        if(listaNoDuplicati != NULL) {
                            *listaNoDuplicati = copiaLista(*lista);
                            *listaNoDuplicati = rimuoviDuplicati(*listaNoDuplicati);
                        }
                        goodFile = 0;
                    } else if (ferror(file)) {
                        printf("Error reading file.\n");
                    }
                }
            }
        }
    }
}

// Funzione per controllare se due parole sono simili
int check_simily(char word1[], char word2[]) {
    int word1Len = strlen(word1);
    int word2Len = strlen(word2);
    char stringa[MAX_STR_LEN+1];
    strcpy(stringa, word2);
    int zeroCount = 0;
    int addOne = 0;

    int i, j;

    // anagramma
    if (word1Len == word2Len) {
        for (i = 0; i < word1Len; i++) {
            for (j = 0; j < word2Len; j++) {
                if(tolower(word1[i]) == tolower(stringa[j])) {
                    stringa[j] = '0';
                    zeroCount++;
                    break;
                }
            }
        }
        if (zeroCount == word2Len) {
            return 1;
        }
    }

    // per change char dovrebbe essere uguale a 1
    zeroCount = 0;

    // change char
    if (word1Len == word2Len) {
        for(i = 0; i < word1Len; i++) {
            if(tolower(word1[i]) != tolower(word2[i])) {
                zeroCount++;
                if (zeroCount > 1) return 0;
            }
        }
        if (zeroCount == 1) {
            return 1;
        }
    }

    // per minus char dovrebbe essere uguale a 0
    int skipCount = 0;

    if (abs(word1Len - word2Len) == 1) {
        const char *shorter = word1Len < word2Len ? word1 : word2;
        const char *longer = word1Len < word2Len ? word2 : word1;
        skipCount = 0;
        for (i = 0; i < strlen(shorter); i++) {
            if (tolower(shorter[i]) != tolower(longer[i + skipCount])) {
                if (skipCount == 1) return 0;
                skipCount = 1;
            }
        }
        return 1;
    }

    return 0;
}

// Funzione per controllare se la lista ordinata è corretta
int check_win(parola_t *listaDisordinata, parola_t *listaOrdinata) {
    if (listaOrdinata == NULL || listaDisordinata == NULL) {
        printf("Error: One of the input lists is NULL\n");
        return 0;
    }

    parola_t *current = listaOrdinata;
    parola_t *currentNext = listaOrdinata->next;

    parola_t *copiaListaDisordinata = copiaLista(listaDisordinata);

    char parolaCorrente[MAX_STR_LEN + 1];
    char parolaNext[MAX_STR_LEN + 1];

    while(current != NULL) {
        strcpy(parolaCorrente, current->parola);
        strcpy(parolaNext, currentNext->parola);

        if (!esisteElemento(copiaListaDisordinata, parolaCorrente)) return 0;
        copiaListaDisordinata = rimuovi(copiaListaDisordinata, parolaCorrente);

        if (!check_simily(parolaCorrente, parolaNext)) return 0;

        current = currentNext;
        if (currentNext->next == NULL) {
            break;
        }

        currentNext = currentNext->next;
    }

    return 1;
}

// Funzione per ottenere l'ultimo elemento di una lista
parola_t* getlast(parola_t *lista) {
    parola_t *current = lista;

    while(current->next != NULL) {
        current = current->next;
    }

    return current;
}

// Funzione per ottenere la soluzione da una lista disordinata senza duplicati
parola_t* getSolution(parola_t *listaDisordinata, parola_t *solution) {    
    if(solution == NULL) {
        solution = inserisciInCoda(solution, listaDisordinata->parola);
    }

    int iteration = 0;
    
    parola_t *current = getlast(solution);
    parola_t *currentNext = listaDisordinata->next;

    if (lunghezza(solution) == lunghezza(listaDisordinata)) {
        // printf("Solution found\n\n\n\n\n\n\n\n\n\n\n\n\n");
        visualizza(solution);
        return solution;
    } 

    parola_t *result = NULL;

    parola_t *localIgnore = NULL;

    while (currentNext != NULL) {
        // printf("\nCurrent: %s CurrentNext: %s\n", current->parola, currentNext->parola);

        // parola_t *tempIgnore = localIgnore;
        // printf("LocalIgnore: ");
        // while (tempIgnore != NULL) {
        //     printf(" %s ", tempIgnore->parola);
        //     tempIgnore = tempIgnore->next;
        // }
        // printf("\n");

        if (check_simily(current->parola, currentNext->parola) && !esisteElemento(solution, currentNext->parola) && !esisteElemento(localIgnore, currentNext->parola)) {
            solution = inserisciInCoda(solution, currentNext->parola);

            // Recurse to try to complete the solution with the new word
            result = getSolution(listaDisordinata, solution);
            
            if(result != NULL) {
                return solution;
            }

            // printf("Adding %s to localIgnore\n", currentNext->parola);
            solution = rimuovi(solution, currentNext->parola);
            localIgnore = inserisciInCoda(localIgnore, currentNext->parola);
        }
        
        currentNext = currentNext->next;
    }

    localIgnore = distruggi(localIgnore);

    printf("Backtracking\n");

    return NULL;    
}

int main() {
    parola_t *listaParoleDisordine = NULL;
    parola_t *listaParoleDisordineNoDuplicati = NULL;
    parola_t *listaParoleOrdinate = NULL;
    parola_t *solution = NULL;

    int partitaAttiva = 1, numero, vittoria;

    printf("Benvenuto nel labirinto!\n");

    askFile(&listaParoleDisordine, &listaParoleDisordineNoDuplicati);

    while(partitaAttiva) {
        printf("1 - Visualizza parole\n");
        printf("2 - Verifica\n");
        printf("3 - Nuova sequenza\n");
        printf("4 - Esci\n");
        printf("5 - Solver\n");

        scanf("%d", &numero);

        fflush(stdin);

        switch (numero) {
            case 1:
                visualizza(listaParoleDisordine);
                break;
            case 2:
                askFile(&listaParoleOrdinate, NULL);
                if(check_win(listaParoleDisordine, listaParoleOrdinate)) {
                    printf("Vittoria\n");
                } else {
                    printf("Sconfitta\n");
                }

                visualizza(listaParoleOrdinate);

                listaParoleDisordine = distruggi(listaParoleOrdinate);
                break;
            case 3:
                clearConsole();
                printf("Cambio sequenza in corso...\n");

                listaParoleDisordine = distruggi(listaParoleDisordine);
                listaParoleDisordineNoDuplicati = distruggi(listaParoleDisordineNoDuplicati);

                askFile(&listaParoleDisordine, &listaParoleDisordineNoDuplicati);
                break;
            case 4:
                // Esci
                partitaAttiva = 0;
                break;
            case 5:
                // Solver
                solution = getSolution(listaParoleDisordineNoDuplicati, solution);

                visualizza(solution);
                solution = distruggi(solution);

                break;
            default:
                printf("Inserisci un numero da 1 a 5!\n");
                break;
        }
    }

    return 0;
}