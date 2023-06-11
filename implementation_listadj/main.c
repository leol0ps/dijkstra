#include "file.h"
#include <stdio.h>
#include "dijkstra.h"
#include "list.h"
#include "adjlist.h"
#include <stdlib.h>
int main(int argc, char** argv){
	if(argc < 3){
		printf("falta argumentos\n");
		return 0;
	}
	int origem;
	int destino;
	int v,path_size;
	List* att = NULL;
	double distance = 0;
	double time;
	Adj** vet_edges = read_entry(argv[1],&origem,&destino,&v,&att);
	int* result = rota(vet_edges,v,(origem-1),(destino-1),att,&time,&path_size,&distance);
	print_to_file(argv[2],result,path_size,distance,time);
	free(result);
	free_vet_edge(vet_edges,v);
	return 0;
}
