#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"

#define MAX_STR_LEN 50
#define MAX_WRD_LEN 30

void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

parola_t* copiaLista(parola_t *lista) {
    parola_t *current = lista;
    parola_t *copia = NULL;

    while(current != NULL) {
        copia = inserisciInCoda(copia, current->parola);
        current = current->next;
    }

    return copia;
}

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

void askFile(parola_t **lista, parola_t **listaNoDuplicati) {
    int goodFile = 1, size, addingWords = 1;
    size_t fileLen, parolaLen;
    char fileName[MAX_STR_LEN + 2];
    char parola[MAX_WRD_LEN + 1];

    while(goodFile) {
        printf("Enter a filename (max %d characters): ", MAX_STR_LEN);

        if (fgets(fileName, sizeof(fileName), stdin)) {
            fileLen = strlen(fileName);
            if (fileName[fileLen - 1] == '\n') {
                fileName[fileLen - 1] = '\0';
                fileLen--;
            }

            if (fileLen > MAX_STR_LEN) {
                printf("Error: Input exceeds %d characters.\n", MAX_STR_LEN);
            } else {
                printf("You entered: %s\n", fileName);

                FILE *file = fopen(fileName, "r");
                if (file == NULL) {
                    printf("Errore nell'apertura del file: %s\n", fileName);
                } else {
                    while (fscanf(file, "%30s", parola) == 1) {
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

int check_simily(char word1[], char word2[]) {
    int word1Len = strlen(word1);
    int word2Len = strlen(word2);
    char stringa[MAX_STR_LEN+1];
    strcpy(stringa, word2);
    int zeroCount = 0;
    int addOne = 0;

    int i, j;

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

    zeroCount = 0;

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

parola_t* getlast(parola_t *lista) {
    parola_t *current = lista;

    while(current->next != NULL) {
        current = current->next;
    }

    return current;
}

parola_t* getSolution(parola_t *listaDisordinata, parola_t *solution) {    
    if(solution == NULL) {
        solution = inserisciInCoda(solution, listaDisordinata->parola);
    }

    int iteration = 0;
    
    parola_t *current = getlast(solution);
    parola_t *currentNext = listaDisordinata->next;

    if (lunghezza(solution) == lunghezza(listaDisordinata)) {
        return solution;
    } 

    parola_t *result = NULL;

    parola_t *localIgnore = NULL;

    while (currentNext != NULL) {
        if (check_simily(current->parola, currentNext->parola) && !esisteElemento(solution, currentNext->parola) && !esisteElemento(localIgnore, currentNext->parola)) {
            solution = inserisciInCoda(solution, currentNext->parola);

            result = getSolution(listaDisordinata, solution);
            
            if(result != NULL) {
                return solution;
            }
            solution = rimuovi(solution, currentNext->parola);
            localIgnore = inserisciInCoda(localIgnore, currentNext->parola);
        }
        
        currentNext = currentNext->next;
    }

    localIgnore = distruggi(localIgnore);

    return NULL;    
}

int main() {
    parola_t *listaParoleDisordine = NULL;
    parola_t *listaParoleDisordineNoDuplicati = NULL;
    parola_t *listaParoleOrdinate = NULL;
    parola_t *solution = NULL;

    int partitaAttiva = 1, numero, vittoria;

    char f;

    clearConsole();

    printf("Welcome to the maze!\n");
    printf("The rules are simple!\n");
    printf("You will input a list of words, and you need to reorder them in the correct sequence.\n");
    printf("Between two consecutive words, one of the following rules must apply:\n");
    printf("1. The words are anagrams, meaning they contain the same characters in a different order (e.g., ANSA, SANA)\n");
    printf("2. The words are the same except for one letter (e.g., CARTA, CORTA)\n");
    printf("3. One word can be obtained by adding a letter to the other (e.g., CASA, CASTA)\n");
    printf("4. One word can be obtained by removing a letter from the other (e.g., PORTA, POTA)\n");

    askFile(&listaParoleDisordine, &listaParoleDisordineNoDuplicati);

    clearConsole();

    while(partitaAttiva) {
        printf("Choose an option:\n");
        printf("0 - Exit the game\n");
        printf("1 - Display the current list of words\n");
        printf("2 - Verify if the word sequence is correct\n");
        printf("3 - Load a new word sequence\n");
        printf("4 - Solve the word sequence puzzle\n");
        printf("5 - View the game rules\n");

        scanf("%d", &numero);

        fflush(stdin);

        switch (numero) {
            case 0:
                partitaAttiva = 0;
                break;
            case 1:
                clearConsole();
                visualizza(listaParoleDisordine);
                printf("Press enter to continue...\n");
                scanf("%c", &f);
                fflush(stdin);
                clearConsole();
                break;
            case 2:
                clearConsole();
                printf("You selected choice 2: Input the right sequence for the win!\n");
                askFile(&listaParoleOrdinate, NULL);
                if(check_win(listaParoleDisordine, listaParoleOrdinate)) {
                    printf("You won!\n");
                    printf("Do you want to play again? (1 - Yes, 0 - No)\n");
                    scanf("%d", &vittoria);

                    fflush(stdin);

                    if (vittoria) {
                        listaParoleDisordine = distruggi(listaParoleOrdinate);
                        listaParoleDisordineNoDuplicati = distruggi(listaParoleDisordineNoDuplicati);
                        askFile(&listaParoleDisordine, &listaParoleDisordineNoDuplicati);
                    } else {
                        partitaAttiva = 0;
                    }
                } else {
                    printf("The input is not valid! Try again\n");
                }

                visualizza(listaParoleOrdinate);

                listaParoleDisordine = distruggi(listaParoleOrdinate);
                break;
            case 3:
                clearConsole();
                printf("New sequence...\n");

                listaParoleDisordine = distruggi(listaParoleDisordine);
                listaParoleDisordineNoDuplicati = distruggi(listaParoleDisordineNoDuplicati);

                askFile(&listaParoleDisordine, &listaParoleDisordineNoDuplicati);
                break;
            case 4:
                solution = getSolution(listaParoleDisordineNoDuplicati, solution);

                visualizza(solution);
                solution = distruggi(solution);

                break;
            case 5:
                printf("Between two consecutive words, one of the following rules must apply:\n");
                printf("1. The words are anagrams, meaning they contain the same characters in a different order (e.g., ANSA, SANA)\n");
                printf("2. The words are the same except for one letter (e.g., CARTA, CORTA)\n");
                printf("3. One word can be obtained by adding a letter to the other (e.g., CASA, CASTA)\n");
                printf("4. One word can be obtained by removing a letter from the other (e.g., PORTA, POTA)\n");
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }

    return 0;
}