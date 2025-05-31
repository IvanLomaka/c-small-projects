#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*inserisce una nuova parola in coda alla lista*/
parola_t *inserisciInCoda(parola_t *lista, char *parola) {
  parola_t *prec;
  parola_t *tmp;
  tmp = malloc(sizeof(parola_t));
  if (tmp != NULL) {
    tmp->next = NULL;
    strcpy(tmp->parola, parola);
    if (lista == NULL)
      lista = tmp;
    else {
      for (prec = lista; prec->next != NULL; prec = prec->next)
        ;
      prec->next = tmp;
    }
  } else
    printf("Memoria esaurita!\n");
  return lista;
}

/*inserisce una nuova parola in testa alla lista*/
parola_t *inserisciInTesta(parola_t *lista, char *parola) {
  parola_t *tmp;
  tmp = malloc(sizeof(parola_t));
  if (tmp != NULL) {
    strcpy(tmp->parola, parola);
    tmp->next = lista;
    lista = tmp;
  } else
    printf("Memoria esaurita!\n");
  return lista;
}

/*rimuove dalla lista la prima occorrenza di una parola specificata come parametro, se presente*/
parola_t* rimuovi(parola_t* lista, char *parola){
  parola_t *curr, *prec;
  curr = lista;
  prec = NULL; 
  while(curr && strcmp(curr->parola, parola) != 0){
    prec = curr;
    curr = curr->next;    
  }
  if(curr){
    if(prec!=NULL)
      prec->next = curr->next;
    else
      lista = curr->next;
    free(curr);    
  }
  return lista;
}

/*rimuove dalla lista tutte le occorrenze di un numero specificato come parametro, se presente*/
parola_t* rimuoviTutti(parola_t* lista, char *parola){
  parola_t *curr, *prec, *canc;

  curr = lista;
  prec = NULL;      
  while(curr){
    if(!strcmp(curr->parola, parola)){
      canc = curr;
      curr = curr->next;     
      if(prec!=NULL)
        prec->next = curr;
      else
        lista = curr;
      free(canc);
    }
    else{
      prec=curr;
      curr = curr->next;     
    }
  }
  return lista;
}

/*libera la memoria allocata per una lista*/
parola_t *distruggi(parola_t *lista) {
  parola_t *tmp;
  while (lista != NULL) {
    tmp = lista;
    lista = lista->next;
    free(tmp);
  }
  return NULL;
}

/*visualizza i numeri contenuti nella lista*/
void visualizza(parola_t *lista) {
  printf("Elementi nella lista: ");
  while (lista != NULL) {
    printf("%s ", lista->parola);
    lista = lista->next;
  }
  printf("\n");
}

/*restituisce 1 se una data parola è presente nella lista, altrimenti 0*/
int esisteElemento(parola_t* lista, char *parola){
  for(;lista && strcmp(lista->parola, parola) != 0; lista=lista->next);
  return (lista != NULL);
}

/*restituisce il puntatore al primo nodo contenente il 
  numero specificato come parametro, altrimenti NULL*/
parola_t* cercaElemento(parola_t* lista, char *parola){
  for(; lista && strcmp(lista->parola, parola) != 0; lista=lista->next);
  return lista;
}

/*calcola e restituisce la lunghezza della lista*/
int lunghezza(parola_t *lista) {
  int i;
  for (i = 0; lista; i++, lista = lista->next)
    ;

  return i;
}