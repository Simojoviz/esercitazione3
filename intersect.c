#include <stdio.h>
#include <stdlib.h>
#include "codaMinPriorita.h"

struct minHeap{
  int *elements;
  int heapsize;
  int dim;
};

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
