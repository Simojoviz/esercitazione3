#include <stdlib.h>
#include <stdio.h>
#include "dizionario.h"
#define HASHSIZE 8
#define HASHAUX (HASHSIZE-3)

struct elem{
  int key;
  int info;
  int pos;
};


/* DEL e' un elemento fittizio che rappresenta un elemento cancellato */
struct dizionario{  
  Elem * content;
  int numchiavi;
  Elem DEL;
};

int funHash(int val, int i){
  int h1 = val % HASHSIZE;
  int h2 = i * (1+2*(val % HASHAUX));

  return (h1+h2) % HASHSIZE;
}

/*post: restituisce un dizionario vuoto */
Dizionario crea(){
  Dizionario new;
  int i;

  new = (Dizionario) malloc(sizeof(struct dizionario));
  new->content = (Elem *) malloc(sizeof(Elem) * HASHSIZE);
  new->numchiavi = 0;
  new->DEL = (Elem) malloc(sizeof(struct elem));

  for (i = 0; i < HASHSIZE; i++) 
    new->content[i] = NULL;

  return new;
}

/*pre: k non e' presente in d e c'e' spazio in d*/
/*post: associa il valore val alla chiave k nel dizionario d*/
void inserisci(Dizionario d, int k, int val){
  int i = 0;
  int j;
  int trovato = 0;
  Elem newElem;
  do{
      Elem e;
      j = funHash(k, i);
      e = d->content[j];
    if (e == NULL || e == d->DEL)
      trovato = 1;
    else 
      i++;
  } while(!trovato);

  newElem = (Elem) malloc(sizeof(struct elem));
  newElem->key = k;
  newElem->info = val;
  newElem->pos = j;

  d->content[j] = newElem;
  (d->numchiavi)++;
}

/*pre: l'elemento x e' contenuto nel dizionario d*/
/*post: rimuove l'elemento x dal dizionario d */
void cancella(Dizionario d, Elem x){
  d->content[e->pos] = d->DEL;

  free(x);
}

/*post: restituisce un elemento con chiave val se esiste, NULL altrimenti */
Elem cerca(Dizionario d, int k){
  int i = 0;
  int j;
  int trovato = 0;
  do{
    j = funHash(k, i);
    if (d->content[j] != NULL) {
      if (d->content[j] != d->DEL && d->content[j]->key == k)
        trovato = 1;
      else
        i++;
    }
  } while(!trovato && d->content[j] != NULL);

  if (trovato)
    return d->content[j];

  return NULL;
}

int numChiavi(Dizionario d){
  return d->numchiavi;
}

/*pre: l'elemento x e' contenuto nel dizionario d */
/*post: restituisce la chiave di x*/
int leggiChiave(Dizionario d, Elem x){
  return x->key;
}

/*pre: l'elemento x e' contenuto nel dizionario d */
/*post: restituisce il valore di x*/
int leggiInfo(Dizionario d, Elem x){
  return x->info;
}

/*post: stampa il contenuto del dizionario */
void stampa(Dizionario d){
  int i;
  for (i = 0; i < HASHSIZE; i++) {
    Elem e = d->content[i];
    if (e != NULL && e != d->DEL)
      printf("(key: %d, info: %d) ",e->key , e->info);
  }
  printf("\n");
}

int main() {


  Dizionario d;

  d = crea();

  inserisci(d, 34, 34);
  inserisci(d, 12, 12);
  inserisci(d, 18, 18);
  inserisci(d, 9,  9);

  stampa(d);

  cancella(d,cerca(d,18));

  stampa(d);
  
  return 0;
}