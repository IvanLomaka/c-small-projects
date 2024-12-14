#ifndef LISTA_H
#define LISTA_H

#define MAXP 30

/*definizione della struttura per la lista concatenata*/
typedef struct parola_{
  char parola[MAXP+1];
  struct parola_ *next;
} parola_t;

/*prototipi delle funzioni*/
parola_t* inserisciInCoda(parola_t*, char*);
parola_t* inserisciInTesta(parola_t*, char*);
parola_t* rimuovi(parola_t*, char *);
parola_t* rimuoviTutti(parola_t*, char *);
parola_t* distruggi(parola_t*);
void visualizza(parola_t*);
int esisteElemento(parola_t*, char *);
parola_t* cercaElemento(parola_t*, char *);
int lunghezza(parola_t*);

#endif
