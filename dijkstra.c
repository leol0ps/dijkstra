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
List* check_att(List* a, Edge*** edges, double time){
	List* aux = a ;
	while(aux != NULL){
		if(time_first(aux) > time){
			return aux;
		}
		else{			
	        List* temp = aux->next;
			int i = att_origem(aux) - 1;
			int j = att_destino(aux) - 1; 	
			change_edge_vel(edges[i][j],get_att_vel(aux));
			aux = remove_first(aux);
			aux = temp;
		}
	}
	return aux;
	/*List* aux = a->next;
	if(a == NULL)
			return a;
	if(time_first(a) >= time)
			return a;
	else{
		printf("chegou aqui\n");
	    int i = att_origem(a)-1;
   	   	int j = att_destino(a)-1;   
 	    change_edge_vel(edges[i][j],get_att_vel(a));
		printf("%lf %d",time_first(a), (aux ==NULL));
		a = remove_first(a);
		aux = check_att(aux,edges,time);
		printf("passou aqui\n");
		return aux;
	}*/
}
int* rota(Edge*** arestas, int v, int origem, int destino, List* att, double* path_time, int* path_size, double* distance){
//	int* st = malloc(v*sizeof(int));
//	double* wt = malloc(v*sizeof(double));
	int* st = NULL;
	double* wt;
	double total_time = 0;
	double total_distance = 0;
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
		if(att!=NULL){
			att = check_att(att,arestas,total_time);
		}
		path[j] = last;
		free(st);
		free(wt);
		wt = NULL;
		st =  NULL;	
	}
	path[j] = destino;
	j++;
	*path_size = j;
	printf("valor de j %d \n",j);
	*path_time = total_time;
	for(int i = 1; i < j; i++){
		total_distance += edge_distance(arestas[path[i-1]][path[i]]); 
	}
	*distance = total_distance;	
	free_list(att);
	return path;	
}



