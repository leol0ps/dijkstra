#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "adjlist.h"
#include "PQ.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct edge{ // tipo utilizado na implementacao com matriz
	double vel;
	double dist;
}Edge;
int *dijkstra(Adj** arestas, int v, int origem, int destino, double** time,double** distance);
Edge* create_edge(double vel,double dis);
void print_edge(Edge* a, int o, int d);
void free_edge(Edge* a);
double edge_distance(Edge* a);
int* rota(Adj** arestas, int v, int origem, int destino, List* att, double* path_time, int* path_size, double* distance);
#endif
