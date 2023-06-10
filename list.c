#include "list.h"
List* create_list(int o, int d, double time,double vel){
    List* b = malloc(sizeof(List));
	b->o = o;
	b->d = d;
	b->time = time;
	b->vel = vel;
    b->next = NULL;
    return b;
}
double time_first(List* a){
	return a->time;
}
double get_att_vel(List* a){
	return a->vel;
}
List* remove_first(List* list){
	if(list == NULL)
				return NULL;
	List* b = list;
	list = list->next;
	free(b);
	return list;
}
int att_origem(List* a){

	return a->o;
}
int att_destino(List* a){
	return a->d;
}

void insert(List* list, int o, int d , double time, double vel){
	if(list->next!=NULL){
		insert(list->next,o,d,time,vel);
	}
	else{
		list->next = malloc(sizeof(List));
		list->next->next = NULL;
		list->next->o = o;
	    list->next->d = d;
		list->next->time = time;
		list->next->vel = vel;	
	}

}
void free_list(List* a){
    if(a == NULL)
        return;
    free_list(a->next);
    free(a);
}
void print_list(List* a){
    if(a == NULL){
        return;
	}
	printf("%d %d %lf %lf\n",a->o,a->d,a->time,a->vel);
   	print_list(a->next);

}
