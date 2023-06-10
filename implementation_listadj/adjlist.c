#include "adjlist.h"

Adj* create_adj_list(int destino, double vel, double distance){
	Adj* a = malloc(sizeof(Adj));
	a->next = NULL; 
	a->d = destino;
	a->vel = vel;
	a->dist = distance;
	return a;
}
void insert_adj(Adj* a,int d , double vel, double distance){
	if(a->next!=NULL){
		insert_adj(a->next,d,vel,distance);
	}
	else{
		a->next = malloc(sizeof(Adj));
		a->next->next = NULL;
		a->next->d = d;
		a->next->vel = vel;
		a->next->dist = distance;	
	}
}

void free_adj(Adj* a){
	if(a == NULL)
			return;
	free_adj(a->next);
	free(a);
}

void edit_adj(Adj* a, double vel,int d){
	if(a == NULL)
			return;
	Adj* aux = a;
	while(aux->d != d){
			aux = aux->next;
		}
	aux->vel = vel;
}

void print_adj(Adj* a){
	printf(" %d vel:%lf dist:%lf\n", a->d,a->vel,a->dist);

}
