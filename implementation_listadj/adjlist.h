#ifndef ADJLIST_H
#define ADJLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct adj{
	int d;
	double vel;
	double dist;
	struct adj* next;
}Adj;

Adj* create_adj_list(int destino, double vel, double distance);
void insert_adj(Adj* a , int d, double vel, double dist);
void free_adj(Adj* a);
void edit_adj(Adj* a, double vel,int d);
void print_adj(Adj* a);
#endif



