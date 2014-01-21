#include "graph.h"


struct graph {
	int n_vertex;
	Edge* edges;
};


Graph* createGraph (int _n_vertex){

	Graph* g = (Graph*) malloc (sizeof(Graph));
	g->n_vertex = _n_vertex;
	edges = NULL;
}

// pensar em guardar em uma lista!
