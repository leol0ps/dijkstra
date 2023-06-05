#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include "dijkstra.h"
#include <stdio.h>
typedef struct list{
	int d;
 	int o;	
	double time;
	double vel;
    struct list* next;
}List;
List* remove_first(List* list);
List* create_list(int o, int d , double time,double vel);
void insert(List* list, int o, int d, double time,double vel);
void free_list(List* a);
void print_list(List* a);
#endif
