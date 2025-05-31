int meanvarstd(int valori[], int len, int *media, int *varianza, int *deviazione) {
    int i = 0;
    int lunghezza = 0;
    int incubatore = 0;

    for(i = 0; i < len; i++) {
        if(valori[i] > 0) {
            incubatore += valori[i];
            lunghezza += 1;
        }
    }

    *media = incubatore / lunghezza;
    incubatore = 0;

    for(i = 0; i < len; i++) {
        if(valori[i] > 0) {
            incubatore += (valori[i] - *media)*(valori[i] - *media);
        }
    }

    *varianza = incubatore / lunghezza;
    *deviazione = sqrt(*varianza);
}