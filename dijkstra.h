#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <stdlib.h>
typedef struct edge{
	double vel;
	double dist;
}Edge;

Edge* create_edge(double vel,double dis);
#endif
