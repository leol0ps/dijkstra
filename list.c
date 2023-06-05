#include "list.h"

List* create_list(Edge* a){
    List* b = malloc(sizeof(List));
    b->edge  = a;
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
void insert(List* list,Edge* a){
    if(list->next != NULL){
        insert(list->next,a);
    }
    else{
        list->next = malloc(sizeof(List));
        list->next->edge = a;
        list->next->next = NULL;
    }
}
void free_list(List* a){
    if(a == NULL)
        return;
    free_list(a->next);
   // delete_point(a->ponto);
    free(a);
}
void print_list(List* a,int dimension){
    if(a == NULL)
        return;
    print_list(a->next,dimension);

}
