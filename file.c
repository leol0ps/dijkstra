#include "file.h"

Pqf* read_entry(char* entry_name){
	FILE* entry = NULL;
	int origem;
	int destino;
	char* line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	char* aux = NULL;
	int n_vertices;
	int n_edges;
	int edge_arg[3];
	double v_start;
	entry = fopen(entry_name,"r");
	if(entry == NULL){
		printf("sem arquivo \n");
		return NULL;
	}
	read = getline(&line,&len,entry);
	aux = strtok(line,";");
	n_vertices = atoi(aux);
	while(aux != NULL){
		n_edges = atoi(aux);
		aux = strtok(NULL,";");
	}
	read = getline(&line,&len,entry);
	aux = strtok(line,";");
	origem = atoi(aux);
	while(aux!=NULL){
		destino = atoi(aux);
		aux = strtok(NULL,";");
	}
	
	read = getline(&line,&len,entry);
	v_start = atof(line);
	Edge** vet_edges = malloc(sizeof(Edge*));
	for(int i = 0; i < n_edges ; i++){
		read = getline(&line,&len,entry);
		aux = strtok(line,";");
		edge_arg[0] = atoi(aux);
		int j = 0;
		while(aux != NULL){
			if(j!=0 && j < 3){
				edge_arg[j] = atoi(aux);
			}
			j++;
			aux = strtok(NULL,";");
		}
		vet_edges[i] = create_edge(edge_arg[0],edge_arg[1],edge_arg[2]);
	}

}


