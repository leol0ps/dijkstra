#ifndef PQ_H
#define PQ_H

#include <stdbool.h>
#include "item.h"
typedef struct pq {
	int* map;
	Item* pq;
	int n;
}Pqf;
Pqf* PQ_init(int maxN); // cria uma min PQ com capacidade maxN
void PQ_insert(Pqf* fila, int v, double  weight);   // Insere Item na PQ. A maior prioridade é a do Item com menor campo 'value'
Item PQ_delmin(Pqf* fila);       // Remove Item com menor campo 'value' da PQ
void PQ_decrease_key(int id, double value, Pqf* fila); // Muda a prioridade do nó com identificador 'id' para 'value'
Item PQ_min(Pqf* fila);          // Retorna Item com menor campo 'value' da PQ
bool PQ_empty(Pqf* fila);        // Retorna True se a PQ não tem elementos
int  PQ_size(Pqf* fila);         // Número de elementos na PQ
void PQ_finish(Pqf* fila);       // Libera memória

#endif
