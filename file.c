#define  _POSIX_C_SOURCE 200810L
#include "file.h"

Edge*** read_entry(char* entry_name, int* o,int* d,int* v,List** att){
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
	v_start = atof(line)/3.6; // division to convert from km/h to m/s
	Edge*** vet_edges = malloc(n_vertices*sizeof(Edge**));
	for(int i = 0 ; i < n_vertices; i++){
		vet_edges[i] = malloc(n_vertices*sizeof(Edge*));
	}
	for(int i = 0; i < n_vertices; i++){
		for(int j = 0; j < n_vertices; j++)
			vet_edges[i][j] = NULL;
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
		vet_edges[edge_s-1][edge_d-1] = create_edge(v_start,value);
	}
	*o = origem;
    *v = n_vertices;	
	*d = destino;
	int att_o,att_d;
	double att_t;
	double att_vel;
	int criada = 0;
	List* list;
	while ((read = getline(&line, &len, entry)) != -1){
		aux = strtok(line,";");
		int j = 0;
		while(aux!=NULL){
			switch(j){
				case 0:
					att_t = atof(aux);
					break;
				case 1:
					att_o = atoi(aux);
					break;
				case 2:
					att_d = atoi(aux);
					break;
				case 3:
					att_vel = atof(aux)/3.6;
					break;	
			  	}
			j++;
				
			aux = strtok(NULL,";");
		}
		if(!criada){
			list = create_list(att_o,att_d,att_t,att_vel);	
			criada++;
		}
		else{
			insert(list,att_o,att_d,att_t,att_vel);
		}

	}
	*att = list;
	free(line);
	fclose(entry);
	return vet_edges;
}

void free_mat_edge(Edge*** a, int n){
	for(int i =0 ; i < n; i++){
		for(int j = 0; j < n; j++){
			free_edge(a[i][j]);	
		}
		free(a[i]);
	}

	free(a);
}
void print_to_file(char* out_name, int* path, int path_size, double distance, double time){
	FILE* out = NULL;
    out = fopen(out_name,"w");
	if(out == NULL){
		fprintf(stderr,"error opening %s\n", out_name);
		return;
	}	
	for(int i = 0; i < path_size-1 ; i++){
		fprintf(out,"%d;", path[i] +1);
	}
	fprintf(out,"%d\n", path[path_size - 1] + 1);
	fprintf(out,"%lf\n", distance/1000); // distance in kilometers
	fprintf(out,"%lf\n",time);
	fclose(out);
}
