#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include "dijkstra.h"
typedef struct list{
    Edge* edge;
	double time;
    struct list* next;
}List;
List* remove_first(List* list);
List* create_list(Edge* a);
void insert(List* list,Edge* a);
void free_list(List* a);
void print_list(List* a, int dimension);
#endif
