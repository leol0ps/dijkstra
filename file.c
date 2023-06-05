#define  _POSIX_C_SOURCE 200810L
#include "file.h"

double** read_entry(char* entry_name, int* o,int* d,int* v){
	FILE* entry = NULL;
	int origem;
	int destino;
	char* line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	char* aux = NULL;
	int n_vertices;
	int n_edges;
	int edge_s,edge_d = 0;
	double v_start;
	double value;
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
	double** vet_edges = malloc(n_vertices*sizeof(double*));
	for(int i = 0 ; i < n_vertices; i++){
		vet_edges[i] = malloc(n_vertices*sizeof(double));
	}
	for(int i = 0; i < n_vertices; i++){
		for(int j = 0; j < n_vertices; j++)
			vet_edges[i][j] = 0;
	}
	printf("%d %d %lf %d\n", origem,destino,v_start,n_edges);
	for(int i = 0; i < n_edges ; i++){
		read = getline(&line,&len,entry);
		aux = strtok(line,";");
		edge_s = atoi(aux);
		int j = 0;
		while(aux != NULL){
			if(j==1){
				edge_d = atoi(aux);
			}
			else if(j==2){
				value = atof(aux);
			}
			j++;
			aux = strtok(NULL,";");
		
		}
		
		printf("creating edge with %d %d position\n",edge_s,edge_d);
		vet_edges[edge_s-1][edge_d-1] = value;
	}
	*o = origem;
    *v = n_vertices;	
	*d = destino;
	return vet_edges;
}


