#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 81

// Funzione per pulire la console
void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Blocco 1: Caricamento dei dati
// Caricamento della soluzione iniziale e parziale
// Caricamento dati
void carica_soluzione_iniziale(int matValoriIniziali[9][9], int matValoriInseritiDopo[9][9]) {
    char s[MAX + 1];
    int i, j, index = 0;

    // Reset delle matrici
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            matValoriIniziali[i][j] = 0;
            matValoriInseritiDopo[i][j] = 0;
        }
    }

    printf("Inserisci 81 valori come stringa unica (usa '_' per celle vuote):\n");
    scanf("%s", s);

    if (strlen(s) != MAX) {
        printf("Errore: devi inserire esattamente 81 caratteri.\n");
        return;
    }

    // Popolamento della matrice
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (s[index] == '_') {
                matValoriIniziali[i][j] = 0;
                matValoriInseritiDopo[i][j] = 0;
            } else {
                matValoriIniziali[i][j] = s[index] - '0'; // Conversione da carattere a numero
                matValoriInseritiDopo[i][j] = s[index] - '0'; 
            }
            index++;
        }
    }
}

void carica_soluzione_parziale(int matValoriIniziali[9][9], int matValoriInseritiDopo[9][9]) {
    char s[MAX + 1];
    int i, j, index = 0;

    printf("Inserisci 81 valori come stringa unica (usa '_' per celle vuote):\n");
    scanf("%s", s);

    // Controllo della lunghezza della stringa
    if (strlen(s) != MAX) {
        printf("Errore: devi inserire esattamente 81 caratteri.\n");
        return;
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (s[index] == '_') {
                if (matValoriIniziali[i][j] != 0) {
                    printf("%d, %d\n", i, j);
                    printf("Errore: hai cercato di modificare il sudoku iniziale\n");
                    return;
                }

                matValoriInseritiDopo[i][j] = 0;
            } else {
                if (matValoriIniziali[i][j] == 0) {
                    matValoriInseritiDopo[i][j] = s[index] - '0'; 
                } else if (matValoriIniziali[i][j] != s[index] - '0') {
                    printf("%d, %d\n", i, j);
                    printf("Errore: hai cercato di modificare il sudoku iniziale\n");
                    return;
                }
            }

            index++;
        }
    }
}

// Blocco 2: Manipolazione matrici
// Inserimento di un valore
// Cancellazione di un valore
// Ripristino della matrice
void inserisciValore(int matValoriInseritiDopo[][9]) {
    int riga, colonna, valore;

    printf("Inserisci la riga (1-9): ");
    scanf("%d", &riga);
    riga--;

    printf("\nInserisci la colonna (1-9): ");
    scanf("%d", &colonna);
    colonna--;

    printf("\n");

    if(riga < 0 || riga > 8 || colonna < 0 || colonna > 8) {
        printf("La riga e la colonna devono essere comprese tra 1 e 9\n");
        return;
    }
    
    if (matValoriInseritiDopo[riga][colonna] == 0) {
        printf("Inserisci il valore della casella: ");
        scanf("%d", &valore);
        
        if (valore < 1 || valore > 9) {
            printf("\nIl valore deve essere compreso tra 1 e 9");
            return;
        }

        matValoriInseritiDopo[riga][colonna] = valore;
        printf("\n");
    }
    else{
        printf("Il posto è già occupato\n");
    }
}

void cancellaValore(int valoriInseritiDopo[][9], int valoriIniziali[][9]){
    int riga, colonna;

    printf("Inserisci la riga (1-9): ");
    scanf("%d", &riga);
    riga--;

    printf("\nInserisci la colonna (1-9): ");
    scanf("%d", &colonna);
    colonna--;

    printf("\n");

    if(riga < 0 || riga > 8 || colonna < 0 || colonna > 8) {
        printf("La riga e la colonna devono essere comprese tra 1 e 9\n");
        return;
    }
    
    if (valoriIniziali[riga][colonna] != 0){
        printf("Non puoi eliminare questo valore!\n");
        return;
    } 

    valoriInseritiDopo[riga][colonna] = 0;
}

void ripristinamatrice(int matValoriIniziali[9][9], int matValoriInseritiDopo[9][9]) {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            matValoriInseritiDopo[i][j] = matValoriIniziali[i][j];
        }
    }
}

// Blocco 3: Controlli e verifica
// Contro delle righe
// Controllo delle colonne
// Controllo dei quadrati
int controllaRighe(int matValoriInseritiDopo[][9], int vittoria) {
    int arrayNumeri[9];

    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            arrayNumeri[k] = 0;
        }

        for (int j = 0; j < 9; j++) {
            int valore = matValoriInseritiDopo[i][j];

            if (valore == 0) {
                continue;
            }

            if (arrayNumeri[valore - 1] != 0) {
                if(vittoria == 0) {
                    printf("Errore nella riga %d\n", i + 1);
                    return 0;
                }
            }

            arrayNumeri[valore - 1] = 1;
        }

        if (vittoria == 1) {
            for (int k = 0; k < 9; k++) {
                if (arrayNumeri[k] == 0) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int contirollaColonne(int matValoriInseritiDopo[][9], int vittoria) {
    int arrayNumeri[9];

    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            arrayNumeri[k] = 0;
        }

        for (int j = 0; j < 9; j++) {
            int valore = matValoriInseritiDopo[j][i];

            if (valore == 0) {
                continue;
            }

            if (arrayNumeri[valore - 1] != 0) {
                if (vittoria == 0) {
                    printf("Errore nella colonna %d\n", i + 1);
                    return 0;
                }
            }

            arrayNumeri[valore - 1] = 1;
        }

        if (vittoria == 1) {
            for (int k = 0; k < 9; k++) {
                if (arrayNumeri[k] == 0) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int controllaQuadrati(int matValoriInseritiDopo[][9], int vittoria) {
    int arrayNumeri[9];

    for (int x = 0; x < 9; x++)
    {
        for (int k = 0; k < 9; k++) {
            arrayNumeri[k] = 0;
        }

        int startRow = (x / 3) * 3;
        int startCol = (x % 3) * 3;

        for (int i = 0 ; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int valore = matValoriInseritiDopo[startRow + i][startCol + j];

                if (valore == 0) {
                    continue;
                }

                if (arrayNumeri[valore - 1] != 0) {
                    if(vittoria == 0) {
                        printf("Errore nelle 3x3 numero %d", (x + 1));
                        return 0;
                    }
                } 

                arrayNumeri[valore - 1] = 1;
            }
        }

        if (vittoria == 1) {
            for (int k = 0; k < 9; k++) {
                if (arrayNumeri[k] == 0) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

// Se vittoria = 0 allora controlla solo la correttezza
// Se il programma deve controllare solo la correttezza allora controlla che non ci siano valori ripetuti
// Se vittoria = 1 allora controlla la completezza del sudoku
// Se il programma deve controllare se il sudoku è completo e fatto correttamente allora controlla che tutti i valori siano corretti
int controllaCorrettezza(int matValoriInseritiDopo[][9], int vittoria) {
    if (controllaRighe(matValoriInseritiDopo, vittoria) == 0) {
        return 1;
    }
    if (contirollaColonne(matValoriInseritiDopo, vittoria) == 0) {
        return 1;
    }
    if (controllaQuadrati(matValoriInseritiDopo, vittoria) == 0) {
        return 1;
    }

    return 0;
}

// Blocco 4: Stampa
void stampa(int matValoriIniziali[][9], int matValoriInseritiDopo[][9]) {
    int i, j;
    
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (matValoriIniziali[i][j] != 0)
            {
                printf("  %d* ", matValoriIniziali[i][j]); 
                
            }
            else {
                printf("  %d  ", matValoriInseritiDopo[i][j]);
            }
            
            if ((j + 1) % 3 == 0 && j != 8) {
                printf("|"); 
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i != 8) {
            printf("-----------------------------------------------\n"); 
        }
    }
}

// Main
int main() {
    int numero;
    int matValoriIniziali[9][9];
    int matValoriInseritiDopo[9][9];
    int partitaAttiva = 1;

    printf("Benvenuto in Sudoku!\n");
    
    carica_soluzione_iniziale(matValoriInseritiDopo, matValoriIniziali);

    while(partitaAttiva) {
        clearConsole();
        stampa(matValoriIniziali, matValoriInseritiDopo);

        printf("1 - Avvia una nuova partita\n");
        printf("2 - Inserisci valore\n");
        printf("3 - Cancella valore\n");
        printf("4 - Verifica la soluzione attuale\n");
        printf("5 - Carica la soluzione e verificala\n");
        printf("6 - Resetta partita attuale\n");
        printf("0 - Esci\n");

        scanf("%d", &numero);

        switch (numero) {
            case 0:
                printf("Hai terminato la partita!\n");
                partitaAttiva = 0;
                break;
            case 1:
                carica_soluzione_iniziale(matValoriInseritiDopo, matValoriIniziali);
                break;
            case 2:
                // Inserisci il valore nella matrice
                inserisciValore(matValoriInseritiDopo);

                // Controlla la fine della partita
                if(controllaCorrettezza(matValoriInseritiDopo, 1) == 0) {
                    stampa(matValoriIniziali, matValoriInseritiDopo);
                    printf("Hai vinto!\n");
                    printf("Vuoi iniziare una nuova partita? (1 = si, 0 = no)\n");

                    scanf("%d", &numero);

                    if (numero == 1) {
                        carica_soluzione_iniziale(matValoriInseritiDopo, matValoriIniziali);
                    } else {
                        printf("Hai terminato la partita!\n");
                        partitaAttiva = 0;
                    }
                };

                break;
            case 3:
                cancellaValore(matValoriInseritiDopo, matValoriIniziali);
                break;
            case 4:
                if(controllaCorrettezza(matValoriInseritiDopo, 0) == 0) {
                    printf("Tutti i numeri sono nella posizione corretta\n");
                    printf("Premi invio per continuare...\n");
                    char f;
                    scanf("%c", &f);
                    scanf("%c", &f);
                }
                break;
            case 5:
                printf("5 - Carica la soluzione e verificala\n");
                carica_soluzione_parziale(matValoriIniziali, matValoriInseritiDopo);

                // Controlla la fine della partita
                if(controllaCorrettezza(matValoriInseritiDopo, 1) == 0) {
                    stampa(matValoriIniziali, matValoriInseritiDopo);

                    printf("Hai vinto!\n");
                    printf("Vuoi iniziare una nuova partita? (1 = si, 0 = no)\n");

                    scanf("%d", &numero);

                    if (numero == 1) {
                        carica_soluzione_iniziale(matValoriInseritiDopo, matValoriIniziali);
                    } else {
                        printf("Hai terminato la partita!\n");
                        partitaAttiva = 0;
                    }
                };
                break;
            case 6:
                ripristinamatrice(matValoriIniziali, matValoriInseritiDopo);
                break;
            default:
                printf("Inserisci un numero da 1 a 6!\n");
                break;
        }
    }    
}