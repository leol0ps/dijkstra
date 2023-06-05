#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <stdlib.h>
#include <stdio.h>
typedef struct edge{
	double vel;
	double dist;
}Edge;

Edge* create_edge(double vel,double dis);
void print_edge(Edge* a, int o, int d);
#endif
