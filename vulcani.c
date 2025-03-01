#include "vulcani.h"
#include <stdio.h>

void erutta_vulcano(int vulc[][NC], int nr, int erut_i, int erut_j) {
    if (erut_i < 0 || erut_i >= nr || erut_j < 0 || erut_j >= NC) {
        return; // Coordinate fuori dai limiti
    }
    
    int altezza_pre_eruzione = vulc[erut_i][erut_j];
    vulc[erut_i][erut_j] += 2;

    printf("%d", NC);
    
    int dx[] = {-1, 1, 0, 0}; // Movimenti nelle 4 direzioni
    int dy[] = {0, 0, -1, 1};
    
    int d;
    for (d = 0; d < 4; d++) {  // C89 non supporta dichiarazioni nel for
        int ni = erut_i + dx[d];
        int nj = erut_j + dy[d];
        
        if (ni >= 0 && ni < nr && nj >= 0 && nj < NC) { // Controllo limiti
            if (vulc[ni][nj] < altezza_pre_eruzione) {
                vulc[ni][nj] += 1;
            }
        }
    }
}
