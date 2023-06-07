#include "dijkstra.h"
#include <float.h>
#define P (wt[j] + edge_time_spent(arestas[j][i]))
Edge* create_edge(double vel, double dis){

	Edge* a = malloc(sizeof(Edge));
	a->dist = dis;
	a->vel = vel;
	return a;
}
void change_edge_vel(Edge* a, double n){
	a->vel = n; 
}
double edge_distance(Edge* a){
	return a->dist;
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

int* dijkstra(Edge*** arestas, int v,int origem, int destino, double** time){
	printf("%d %d origem e destino dijkstra\n", origem, destino);
	int j,w;
	int* st = malloc(v*sizeof(int));
	double* wt = malloc(v*sizeof(double));
	double total_time = 0;
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
		if(wt[j = id(a)]!= DBL_MAX){
			for(int i = 0; i < v ; i++){
				 if(P < wt[w = i]){
				 	wt[w] = P;
					PQ_decrease_key(w,P,heap);
					st[w] = j;
				 }
			}
		}
	}
	*time = wt; 
	PQ_finish(heap);
 	return st;
}
void check_att(List** a, Edge*** edges, double time){
	if(*a == NULL)
			return;
	if(time_first(*a)> time)
			return;
	else{
		printf("chegou aqui\n");
	    int i = att_origem(*a)-1;
   	   	int j = att_destino(*a)-1;   
 	    change_edge_vel(edges[i][j],get_att_vel(*a));
		*a = remove_first(*a);
		check_att(a,edges,time);
		printf("passou aqui\n");
	}
}
int* rota(Edge*** arestas, int v, int origem, int destino, List* att, double* path_time, int* path_size){
//	int* st = malloc(v*sizeof(int));
//	double* wt = malloc(v*sizeof(double));
	int* st = NULL;
	double* wt;
	double total_time = 0;
	int* path = malloc(v*sizeof(int));
	int i = origem;
	int x = destino, last=origem;
	path[0] = origem;
	int j = 0;
	while(i!=destino){
		j++;
		st = dijkstra(arestas,v,i,destino, &wt);
		while(st[x]!= -1){ // condicao quebra na raiz da spt
			last = x;
			x = st[x];
		}
		x = destino;
		total_time += wt[last];
	    printf("total time %lf\n",total_time);
		i = last;
		check_att(&att,arestas,total_time);
		path[j] = last;
		free(st);
		free(wt);
		wt = NULL;
		st =  NULL;	
	}
	path[j] = destino;
	*path_size = j+1;
	printf("valor de j %d \n",j);
	*path_time = total_time;	
	return path;	
}



