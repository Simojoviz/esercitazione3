#include <stdio.h>
#include <stdlib.h>
#include "codaMinPriorita.h"

struct minHeap{
  int *elements;
  int heapsize;
  int dim;
};


/*La complessità della funzione sarà theta((n1)log(n1) + (n2)log(n2)) con n1 la 
dimensione del primo min_heap e n2 la dimensione del secondo min_heap.
Questo perchà vengono eseguite tante heapExtractMin, che hanno complessità O(log(n)) 
qunti sono gli elementi nei due min_heap e quindi n1 volte per il primo min_heap 
e n2 volte per il secondo*/
MinHeap intersect(MinHeap h1, MinHeap h2){
	int size;
	MinHeap intersect;
	size = (heapsize(h1) < heapsize(h2)) ? heapsize(h1) : heapsize(h2);
	intersect = newMinHeap(size);

	while(heapsize(h1) > 0 && heapsize(h2) > 0) {
		if (heapMinimum(h1) == heapMinimum(h2)) {
			heapInsert(intersect, heapExtractMin(h1));
			heapExtractMin(h2);
		}else if (heapMinimum(h1) < heapMinimum(h2))
			heapExtractMin(h1);
		else
			heapExtractMin(h2); 
	}

	return intersect;
}
