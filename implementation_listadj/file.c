#define  _POSIX_C_SOURCE 200810L
#include "file.h"

Adj** read_entry(char* entry_name, int* o,int* d,int* v,List** att){
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
	double value = 0;
	int att_o = 0,att_d = 0;
	double att_t = 0;
	double att_vel = 0;
	int criada = 0;
	List* list = NULL;
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
	Adj** vet_edges = malloc(n_vertices*sizeof(Adj*));
	for(int i = 0 ; i < n_vertices; i++){
		vet_edges[i] = NULL;
	}
	//printf("%d %d %lf %d\n", origem,destino,v_start,n_edges);
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
		if(vet_edges[edge_s-1] == NULL){
			vet_edges[edge_s-1] = create_adj_list(edge_d-1,v_start,value);
		}
		else{
			insert_adj(vet_edges[edge_s-1], edge_d-1,v_start,value);
		}	
		//printf("creating edge with %d %d position\n",edge_s,edge_d);
		//vet_edges[edge_s-1][edge_d-1] = create_edge(v_start,value);
	}
	*o = origem;
    *v = n_vertices;	
	*d = destino;
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

void free_vet_edge(Adj** a, int n){
	for(int i =0 ; i < n; i++){

		free_adj(a[i]);
	}

	free(a);
}
void print_to_file(char* out_name, int* path, int path_size, double distance, double time){
	FILE* out = NULL;
    out = fopen(out_name,"w");
	int horas = (int)time/3600;
	int horas_remove = (int)time % 3600;
	int minutos = (int)horas_remove/60;
	int	minutos_remove = (int)horas_remove % 60;
	int segundos = (int)minutos_remove;
   	double ms = time-(int)time;
	char ms_str[100];
	sprintf(ms_str,"%lf",ms);
	char* after_comma = &ms_str[2];
	if(out == NULL){
		fprintf(stderr,"error opening %s\n", out_name);
		return;
	}	
	for(int i = 0; i < path_size-1 ; i++){
		fprintf(out,"%d;", path[i] +1);
	}
	fprintf(out,"%d\n", path[path_size - 1] + 1);
	fprintf(out,"%lf\n", distance/1000); // distance in kilometers
	fprintf(out,"%02d:%02d:%02d.%s\n",horas,minutos,segundos,after_comma);
	fclose(out);
}
