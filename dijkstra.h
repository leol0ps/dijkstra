#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "PQ.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct edge{
	double vel;
	double dist;
}Edge;
int *dijkstra(Edge*** arestas, int v, int origem, int destino, double** time);
Edge* create_edge(double vel,double dis);
void print_edge(Edge* a, int o, int d);
void free_edge(Edge* a);
double edge_distance(Edge* a);
int* rota(Edge*** arestas, int v, int origem, int destino, List* att, double* path_time, int* path_size, double* distance);
#endif
