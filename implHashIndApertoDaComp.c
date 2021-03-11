#include <stdlib.h>
#include <stdio.h>
#include "dizionario.h"
#define HASHSIZE 8
#define HASHAUX -1

struct elem{
  int key;
  int info;
  ...
};


/* DEL e' un elemento fittizio che rappresenta un elemento cancellato */
struct dizionario{  
  Elem * content;
  int numchiavi;
  Elem DEL;
};

int funHash(int val, int i){
  return ((val % HASHSIZE) + (i * (1+2*(val % (HASHSIZE-3))))) % HASHSIZE;
}

/*post: restituisce un dizionario vuoto */
Dizionario crea(){
  Dizionario new;
  int i;

  new = (Dizionario) malloc(sizeof(struct dizionario));
  new->content = (Elem) malloc(sizeof(strct elem) * HASHSIZE);
  new->numchiavi = 0;
  new->DEL = NULL;

  for (i = 0; i < HASHSIZE; i++) 
    new->content[i] = NULL;

  return new;
}

/*pre: k non e' presente in d e c'e' spazio in d*/
/*post: associa il valore val alla chiave k nel dizionario d*/
void inserisci(Dizionario d, int k, int val){
  int i = 0;
  int j;
  int trovato = false;
  int newElem;
  do{
    j = funHash(k, i);
    if (v->content[j] == NULL || v->content[j] == HASHAUX)
      trovato = true;
    else 
      i++;
  } while(!trovato && i < HASHSIZE);

  newElem = (Elem) malloc(sizeof(struct elem));
  newElem->key;

}

/*pre: l'elemento x e' contenuto nel dizionario d*/
/*post: rimuove l'elemento x dal dizionario d */
void cancella(Dizionario d, Elem x){
  ...
}

/*post: restituisce un elemento con chiave val se esiste, NULL altrimenti */
Elem cerca(Dizionario d, int k){
  ...
}

int numChiavi(Dizionario d){
  ...
}

/*pre: l'elemento x e' contenuto nel dizionario d */
/*post: restituisce la chiave di x*/
int leggiChiave(Dizionario d, Elem x){
  ...
}

/*pre: l'elemento x e' contenuto nel dizionario d */
/*post: restituisce il valore di x*/
int leggiInfo(Dizionario d, Elem x){
  ...
}

/*post: stampa il contenuto del dizionario */
void stampa(Dizionario d){
  ...
}


