#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
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
	return v->elements[0];
}

void min_heapfy(MinHeap v, int i) {
	int l = 2*i + 1;
	int r = 2*i + 2;
	int min;
	int temp;

	if (l < (v->heapsize - 1) && v->elements[l] < v->elements[i]) 
		min = l;
	else 
		min = i;

	if (r < (v->heapsize - 1)&& v->elements[r] < v->elements[min]) 
		min = r;
	
	if (i != min) {
		temp = v->elements[min];
		v->elements[min] = v->elements[i];
		v->elements[i] = temp;			

		min_heapfy(v, min);
	}

}

/*pre: la coda e' non vuota */
/*post: elimina e restituisce la chiave piu' piccola nella coda */

int heapExtractMin(MinHeap v){
	int min = v->elements[0];
	
	v->elements[0] = v->elements[v->heapsize - 1];
	(v->heapsize)--;
	min_heapfy(v, 0);

	if (v->heapsize <= (v->dim)/4) {
		v->dim = v->dim / 2;
		v->elements = (int *) realloc(v->elements, sizeof(int) * v->dim);
	}
	
	return min;
}

/*pre: i e' un nodo dell'heap */
/*post: decrementa il valore della chiave dell'elemento in posizione i al valore k (k <= valore corrente dell'elemento in posizione i) */

void heapDecreaseKey(MinHeap v, int i, int k){
	if (k > v->elements[i]) {
		fprintf(stderr, "key larger than the current one\n");
		return;
	}
	v->elements[i] = k;
	while(i>0 && v->elements[(i-1)/2] > v->elements[i]) {
		temp = v->elements[(i-1)/2];
		v->elements[(i-1)/2] = v->elements[i];
		v->elements[i] = temp;
		i = (i-1) / 2;	
	}
}

/*post: inserisce l'elemento con chiave k nella coda.  */

void heapInsert(MinHeap v, int k){
	if (v->heapsize == v->dim) {
		v->dim *= 2;
		v->elements = (int *) realloc(v->elements, sizeof(int) * v->dim);
	}

	(v->heapsize)++;
	v->elements[v->heapsize - 1] = INT_MIN;
	heapDecreaseKey(v, v->heapsize - 1, k);
}


/*pre: i e' un nodo dell'heap */
/*post: cancella l’elemento nel nodo i dalla coda */

void heapDelete(MinHeap v, int i){
	v->elements[i] = v->elements[v->heapsize - 1];
	(v->heapsize) --;
	min_heapfy(v, i);

	if (v->heapsize <= (v->dim)/4) {
		v->dim = v->dim / 2;
		v->elements = (int *) realloc(v->elements, sizeof(int) * v->dim);
	}
}



/*post: restituisce un nodo che contiene la chiave k se k e' presente nella coda di min-priorita', -1 altrimenti */
int heapSearch(MinHeap v, int k){
	int i = 0;
	while (i < v->heapsize) {
		if (v->elements[i] = k)
			return i;

		i++;
	}	

	return -1;
}

/* post: restituisce la heapsize della coda di min-priorita' */
int heapsize(MinHeap v){
	if (v != NULL) 
		return v->heapsize;

	return 0;
}
  
