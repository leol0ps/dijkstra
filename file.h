#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "PQ.h"
#include <string.h>
#include "dijkstra.h"
#include "list.h"
Edge*** read_entry(char* entry_name, int* o,int* d,int* v,List** att);
void free_mat_edge(Edge*** a, int n);

#endif
