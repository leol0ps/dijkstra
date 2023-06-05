#include "file.h"

double** read_entry(char* entry_name){
	FILE* entry = NULL;
	int origem;
	int destino;
	char* line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	char* aux = NULL;
	int n_vertices;
	int n_edges;
	int edge_s,edge_d;
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
	double** vet_edges = malloc(sizeof(double*));
	for(int i = 0 ; i < n_edges; i++){
		vet_edges = malloc(n_edges*sizeof(double));
	}
	for(int i = 0; i < n_edges; i++){
		for(int j = 0; j < n_edges; j++)
			vet_edges[i][j] = 0;
	}
	for(int i = 0; i < n_edges ; i++){
		read = getline(&line,&len,entry);
		aux = strtok(line,";");
		edge_s = atoi(aux);
		int j = 0;
		while(aux != NULL){
			if(j==0){
				edge_d = atoi(aux);
			}
			else{
				vet_edges[edge_s][edge_d] = atof(aux);
			}
			j++;
			aux = strtok(NULL,";");
		}
	}
	return vet_edges;
}


