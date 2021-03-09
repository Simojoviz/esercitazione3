#include <stdlib.h>
#include <stdio.h>
#include "codaMinPriorita.h"

struct minHeap{
  int * elements;
  int heapsize;
  int dim;
};


/*post: restituisce una coda di min-priorita' vuota (heapsize = 0), con dimensione size */
MinHeap newMinHeap(int size){
	MinHeap new;

	if (size < 0)
		return NULL;
	if (size == 0)
		size = 1;

	new = (MinHeap) malloc(sizeof(struct minHeap));
	new->dim = size;
	new->heapsize = 0;
	new->elements = (int*) malloc(sizeof(int) * (new->dim));

	return new;
}


/*post: restituisce >0 se la coda di min-priorita' e' vuota, 0 atrimenti */
int heapEmpty(MinHeap v){

	if (v != NULL)
		return v->heapsize;

	return 0;   //solo se v punta a NULL
}

/*pre: la coda e' non vuota */
/*post: restituisce la chiave piu' piccola nella coda */

int heapMinimum(MinHeap v){
	return elements[0];
}

/*pre: la coda e' non vuota */
/*post: elimina e restituisce la chiave piu' piccola nella coda */

int heapExtractMin(MinHeap v){
	int min = elements[0];
	int aux = elements[v->heapsize];
	
	elements[0] = elements[v->heapsize];
	(v->heapsize)--;

}

/*pre: i e' un nodo dell'heap */
/*post: decrementa il valore della chiave dell'elemento in posizione i al valore k (k <= valore corrente dell'elemento in posizione i) */

void heapDecreaseKey(MinHeap v, int i, int k){
  
........................................
}

/*post: inserisce l'elemento con chiave k nella coda.  */

void heapInsert(MinHeap v, int k){
  
 ...................................................
}


/*pre: i e' un nodo dell'heap */
/*post: cancella l’elemento nel nodo i dalla coda */

void heapDelete(MinHeap v, int i){

 ...................................................
}



/*post: restituisce un nodo che contiene la chiave k se k e' presente nella coda di min-priorita', -1 altrimenti */
int heapSearch(MinHeap v, int k){

.......................................
}

/* post: restituisce la heapsize della coda di min-priorita' */
int heapsize(MinHeap v){
	if (v != NULL) 
		return v->heapsize;

	return -1;
}
  
