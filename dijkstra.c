#include "dijkstra.h"


Edge* create_edge(double vel, double dis){

	Edge a = malloc(sizeof(Edge));
	a->dis = dis;
	a->vel = vel;
	return a;
}
