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
/*T(n) = O(1) sono tute operazioni in tempo costante */
MinHeap newMinHeap(int size){
	MinHeap new;

	if (size <= 0)
		size = 1;

	new = (MinHeap) malloc(sizeof(struct minHeap));
	new->dim = size;
	new->heapsize = 0;
	new->elements = (int*) malloc(sizeof(int) * (new->dim));

	return new;
}


/*post: restituisce >0 se la coda di min-priorita' e' vuota, 0 atrimenti */
/*T(n) = O(1) sono tutte operazioni in tempo costante*/
int heapEmpty(MinHeap v){

	if (v != NULL && v->heapsize > 0)
		return 0;

	return 1;   
}

/*pre: la coda e' non vuota */
/*post: restituisce la chiave piu' piccola nella coda */
/*T(n) = O(1) sono tutte operazioni in tempo costante */
int heapMinimum(MinHeap v){
	return v->elements[0];
}

/*Come visto a lezione la complessità è O(h) con h altezza del nodo i, visto 
che un min_heap ha altezza log(n) allora T(n) = log(n)*/
void min_heapfy(MinHeap v, int i) {
	int l = 2*i + 1;
	int r = 2*i + 2;
	int min;
	int temp;

	if (l < heapsize(v) && v->elements[l] < v->elements[i]) 
		min = l;
	else 
		min = i;

	if (r < heapsize(v) && v->elements[r] < v->elements[min]) 
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
/*L'unica operazione non in tempo costante è la min_heapfy che ha complessità O(log(n)),
quindi T(n) = O(log(n))*/
int heapExtractMin(MinHeap v){
	int min = v->elements[0];
	
	v->elements[0] = v->elements[heapsize(v) - 1];
	(v->heapsize)--;
	min_heapfy(v, 0);

	if (heapsize(v) <= (v->dim)/4) {
		v->dim = v->dim / 2;
		v->elements = (int *) realloc(v->elements, sizeof(int) * v->dim);
	}
	
	return min;
}

/*pre: i e' un nodo dell'heap */
/*post: decrementa il valore della chiave dell'elemento in posizione i al valore k (k <= valore corrente dell'elemento in posizione i) */
/*Decrementa il valore della chiave in posizione i e risale l'heap fino al massimo
alla radice quindi T(n) = O(log(n)) */
void heapDecreaseKey(MinHeap v, int i, int k){
	int temp;
	if (k > v->elements[i]) {
		fprintf(stderr, "Key larger than the current one\n");
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
/*Inserisce l'elemento alla fine dell'heap e in seguito chiama la heapDecreaseKey
che ha complessità O(log(n)).
Quindi T(n) = O(log(n))*/
void heapInsert(MinHeap v, int k){
	if (v->heapsize == v->dim) {
		v->dim *= 2;
		v->elements = (int *) realloc(v->elements, sizeof(int) * v->dim);
	}

	(v->heapsize)++;
	v->elements[heapsize(v) - 1] = INT_MAX;
	heapDecreaseKey(v, heapsize(v) - 1, k);
}


/*pre: i e' un nodo dell'heap */
/*post: cancella l’elemento nel nodo i dalla coda */
/*Tutte operazioni in tempo costante tranne le min_heapfy, quindi T(n) = O(log(n))*/
void heapDelete(MinHeap v, int i){
	v->elements[i] = v->elements[heapsize(v) - 1];
	(v->heapsize)--;
	min_heapfy(v, i);

	if (v->heapsize <= (v->dim)/4) {
		v->dim = v->dim / 2;
		v->elements = (int *) realloc(v->elements, sizeof(int) * v->dim);
	}
}



/*post: restituisce un nodo che contiene la chiave k se k e' presente nella coda di min-priorita', -1 altrimenti */
/*Scorre al massimo tutto l'heap solo una volta quindi T(n) = O(n)*/
int heapSearch(MinHeap v, int k){
	int i = 0;
	while (i < heapsize(v)) {
		if (v->elements[i] == k)
			return i;

		i++;
	}	

	return -1;
}

/* post: restituisce la heapsize della coda di min-priorita' */
/*T(n) = O(1) tutte operazioni in tempo costante*/
int heapsize(MinHeap v){
	if (v != NULL) 
		return v->heapsize;

	return 0;
}
