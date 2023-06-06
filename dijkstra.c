#include "dijkstra.h"
#include <float.h>
#define P (wt[j] + (arestas[j][i]->dist/arestas[j][i]->vel))
Edge* create_edge(double vel, double dis){

	Edge* a = malloc(sizeof(Edge));
	a->dist = dis;
	a->vel = vel;
	return a;
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
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			if(arestas[i][j]->dist = 0){
				arestas[i][j]->dist = DBL_MAX;
			}
		}
	}
	int* st = malloc(v*sizeof(int));
	int* wt = malloc(v*sizeof(int));
	int j,w;
	Edge** t;
	Pqf* heap = PQ_init(v);	
	for(int i = 0; i < v; i++){
		st[i] = -1;
		wt[i] = DBL_MAX;				
		PQ_insert(heap,i,(arestas[origem][i]->dist/arestas[origem][i]->vel));
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
