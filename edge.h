#ifndef _EDGE_H
#define _EDGE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct edge Edge;

Edge* createEdge(int src, int dest, int cost);
void print(Edge* e);


#endif
