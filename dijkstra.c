#include "dijkstra.h"
#include <float.h>
#define P (wt[j] + edge_time_spent(arestas[j][i]))
Edge* create_edge(double vel, double dis){

	Edge* a = malloc(sizeof(Edge));
	a->dist = dis;
	a->vel = vel;
	return a;
}

double edge_time_spent(Edge* a){
	if(a == NULL)
			return DBL_MAX;
	return a->dist/a->vel;
}
void print_edge(Edge* a, int o, int d){
	if(a ==NULL)
			return;
	printf("origem %d destino %d vel %lf\n",o,d,a->dist );
}

void free_edge(Edge* a){
	free(a);
}

int* dijkstra(Edge*** arestas, int v,List* att,int origem, int destino){
	printf("%d %d origem e destino dijkstra\n", origem, destino);
	int j,w;
	int* st = malloc(v*sizeof(int));
	double* wt = malloc(v*sizeof(double));
	Edge** t;
	Pqf* heap = PQ_init(v);	
	for(int i = 0; i < v; i++){
		st[i] = -1;
		wt[i] = DBL_MAX;				
		PQ_insert(heap,i,DBL_MAX);
	}
	wt[origem] = 0;
	PQ_decrease_key(origem,0,heap);
	while(!PQ_empty(heap)){
		Item a = PQ_delmin(heap);
		if(wt[j = a.id]!= DBL_MAX){
			for(int i = 0; i < v ; i++){
				 if(P < wt[w = i]){
				 	wt[w] = P;
					PQ_decrease_key(w,P,heap);
					st[w] = j;
				 }
			}
		}
	}
 	return st;
}
