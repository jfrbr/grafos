#include "edge.h"


struct edge{
	int src,dest, cost;
};


Edge* createEdge (int _src, int _dest, int _cost){

	Edge* e = (Edge*) malloc (sizeof (Edge) );

	e->src = _src;
	e->dest = _dest;
	e->cost = _cost;

	return e;
}

void print(Edge* e){
	printf("Source = %d | Destiny = %d | Cost = %d\n",e->src, e->dest, e->cost);
}



