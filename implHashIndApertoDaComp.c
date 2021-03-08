#include <stdlib.h>
#include <stdio.h>
#include "dizionario.h"
#define HASHSIZE ...
#define HASHAUX ...

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
  ...
}

/*post: restituisce un dizionario vuoto */
Dizionario crea(){
  ...
}

/*pre: k non e' presente in d e c'e' spazio in d*/
/*post: associa il valore val alla chiave k nel dizionario d*/
void inserisci(Dizionario d, int k, int val){
  ...
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


