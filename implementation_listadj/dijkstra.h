#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "adjlist.h"
#include "PQ.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
int *dijkstra(Adj** arestas, int v, int origem, double** time,double** distance);
int* rota(Adj** arestas, int v, int origem, int destino, List* att, double* path_time, int* path_size, double* distance);
#endif
