#include "file.h"
#include <stdio.h>
#include "dijkstra.h"
#include "list.h"
#include <stdlib.h>
int main(int argc, char** argv){
	int origem;
	int destino;
	int v,path_size;
	int count = 0;
	List* att = NULL;
	double time;
	double path_time;
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
	printf("%d %d \n", origem ,  destino);
	int* result = rota(vet_edges,v,(origem-1),(destino-1),att,&time,&path_size);
	for(int i = 0; i < path_size; i++){
		printf("%d  \n", result[i]+1);
	}

	//print_list(att);
	//free_list(att);
	double distance = 0;
	int k = destino-1;
	int x;
	while((x = result[k])!=-1){ // quando a condicao e verdadeira significa que chegamos na raiz da spt
		distance += edge_distance(vet_edges[x][k]);
		k = x;
	}
	free_mat_edge(vet_edges,v);
	free(result);
	printf("path time : %lf  e %lf \n", time,distance);
	return 0;
}
