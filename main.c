#include "file.h"
#include <stdio.h>
#include "dijkstra.h"
#include "list.h"
#include <stdlib.h>
int main(int argc, char** argv){
	int origem;
	int destino;
	int v;
	int count = 0;
	List* att = NULL;
	Edge*** vet_edges = read_entry(argv[1],&origem,&destino,&v,&att);
	for(int i = 0; i < v; i++){
		for(int k = 0; k < v; k++){
			print_edge(vet_edges[i][k],i,k);
			count++;
		}
	}
	if(att==NULL){
		printf("ta errado otario\n");
	}
	int* result = dijkstra(vet_edges,v,att,origem,destino);
	for(int i = 0; i < v; i++){
		printf("%d  \n", result[i]);
	}
	print_list(att);
	free_list(att);
	free_mat_edge(vet_edges,v);
	printf("count %d \n",count);
	return 0;
}
