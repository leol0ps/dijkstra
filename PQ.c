#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"


static void swap(int* map,Item* pq,int i, int j) {
    exch(pq[i],pq[j]);
    map[id(pq[i])] = i;
    map[id(pq[j])] = j;
}

void fix_up(int* map,Item *a, int k) {
    while (k > 1 && more(a[k/2], a[k])) {
        swap(map,a,k, k/2);
        k = k/2;
    }
}

void fix_down(int* map,Item *a, int sz, int k){
  while (2*k <= sz) {
    int j = 2*k;
    if (j < sz && more(a[j], a[j+1])){
      j++;
    }
    if (!more(a[k], a[j])) {
      break;
    }
    swap(map,a,k, j);
    k = j;
  }
}

Pqf* PQ_init(int maxN) {
    Pqf* fila = malloc(sizeof(Pqf));
	fila->pq =  malloc((maxN+1) * sizeof (Item));
    fila->map = malloc((maxN+1) * sizeof (int));
    fila->n = 0;
	return fila;
}

void PQ_insert(Pqf* fila, int v, double weight) {
    fila->n++;
    fila->pq[fila->n].id =  v;
	fila->pq[fila->n].value = weight;
    fila->map[v] = fila->n;
    fix_up(fila->map,fila->pq, fila->n);
}

Item PQ_delmin(Pqf* fila) {
    Item min = fila->pq[1];
    swap(fila->map,fila->pq,1,fila-> n);
    fila->n--;
    fix_down(fila->map,fila->pq,fila->n, 1);
    return min;
}

Item PQ_min(Pqf* fila) {
    return fila->pq[1];
}

void PQ_decrease_key(int id,double value,Pqf* fila) {
    int i = fila->map[id];
    value(fila->pq[i]) = value;
    fix_up(fila->map,fila->pq, i);
}

bool PQ_empty(Pqf* fila) {
    return fila->n == 0;
}

int  PQ_size(Pqf* fila) {
    return fila->n;
}

void PQ_finish(Pqf* fila) {
    free(fila->pq);
    free(fila->map);
	free(fila);
}
