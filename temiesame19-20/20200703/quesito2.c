int elimina(char stringa[]) {
    int eliminati = 0;
    int i = 0;
    int lunghezza = strlen(stringa);
    int sostituzione = 0;

    for (i=0; i < lunghezza; i++) {
        if(
            (stringa[i] >= 'a' && stringa[i] <= 'z') ||
            (stringa[i] >= 'A' && stringa[i] <= 'Z') ||
            (stringa[i] >= '0' && stringa[i] <= '9')
        ) {
            stringa[sostituzione] = stringa[i];
            sostituzione++;
        }
    }

    if(sostituzione < lunghezza) {
        stringa[sostituzione + 1] = '\0';
    }

    return eliminati;
}