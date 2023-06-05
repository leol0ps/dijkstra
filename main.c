#include "file.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv){
	int origem;
	int destino;
	int v;
	int count = 0;
	double** vet_edges = read_entry(argv[1],&origem,&destino,&v);
	for(int i = 0; i < v; i++){
		for(int k = 0; k < v; k++){
			printf(" arestas %d %d tem peso %lf\n",i,k,vet_edges[i][k]);
		if(vet_edges[i][k]> 0)
				count++;
		}
	}
	printf("count %d \n",count);
	return 0;
}
