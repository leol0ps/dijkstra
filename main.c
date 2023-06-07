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
	for(int i = 1; i < path_size; i++){
		distance+= edge_distance(vet_edges[result[i-1]][result[i]]);
		
		printf("%d %d edge\n", result[i-1],result[i]);
	}
	int k = path_size;
	printf("vale k %d\n",k);
	int x = k-1;
	/*while(x > 0){ 
		distance += edge_distance(vet_edges[result[x]][result[k]]);
		k = x;
		x = k-1;
		printf("%d %d edge\n", result[x],result[k]);
	}*/
	free_mat_edge(vet_edges,v);
	free(result);
	printf("path time : %lf  e %lf \n", time,distance);
	return 0;
}
