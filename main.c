#include "file.h"
#include <stdio.h>
#include "dijkstra.h"
#include <stdlib.h>
int main(int argc, char** argv){
	int origem;
	int destino;
	int v;
	int count = 0;
	Edge*** vet_edges = read_entry(argv[1],&origem,&destino,&v);
	for(int i = 0; i < v; i++){
		for(int k = 0; k < v; k++){
			print_edge(vet_edges[i][k],i,k);
			count++;
		}
	}
	printf("count %d \n",count);
	return 0;
}
