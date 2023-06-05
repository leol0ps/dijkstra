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

List* remove_first(List* list){
	if(list == NULL)
				return NULL;
	List* b = list->next;
	free(list);
	return b;
}
void insert(List* list,int o, int d, double time,double vel){
    if(list->next != NULL){
        insert(list->next,o,d,time,vel);
    }
    else{
        list->next = malloc(sizeof(List));
        list->next->next = NULL;
		list->o = o;
		list->d = d;
		list->time = time;
		list->vel = vel;
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
