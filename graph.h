#ifndef _GRAPH_
#define _GRAPH_

typedef struct graph Graph;


Graph* createGraph(int n_vertex);
void addEdge(Graph* g, Edge* e);
void print(Graph* g);



#endif
