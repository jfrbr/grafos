#include <stdio.h>
#include <string.h>
#include "graph.h"

int main(){

	int i,n,m,num_tests = 0;
	
	while ( scanf("%d %d\n",&n,&m) == 2 ){

		if (!n && !m) break;

		Graph* g = createGraph(n);

		for (i=0; i < m; ++i){

			int x,y,cost;
			scanf("%d %d %d\n",&x,&y,&cost);

			Edge *e = createEdge(x,y,cost);
			addEdge(g,e);
		}

		// kruskal

		printf("Teste %d\n",tests++);
		// imprimir solucao	
	}

	return 0;
}
