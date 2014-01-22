#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 150

int g[MAX][MAX];
int parent[MAX];

int f,s,t;

int MIN (int a, int b){
	return a < b ? a : b;
}

void augment_path( int v, int min_edge ){

	if (v == s){
		f = min_edge;
		return;
	} else if ( parent[v] != -1 ){
		
		augment_path(parent[v], MIN(min_edge, g[parent[v]][v]));
		g[ parent[v] ][ v ] -= f;
		g[ v ][parent[v] ] += f;
	}
}

int max_flow(int src, int dest){





	
}

int main(){

	int i,n,c,a,b,w;

	while ( scanf("%d\n") == 1 && n ){

		memset(g,0,sizeof(g));
		memset(parent,-1,sizeof(parent));

		f = s = t = 0;

		scanf("%d %d %d\n",&s,&t,&c);


		for (i=0;i<c;++i){
			scanf("%d %d %d\n",&a,&b,&w);
			g[a][b] = 1;
			g[b][a] = 1;
		}

		int res = max_flow(s,t);

		// max flow
		// print solucao

	
	}


	return 0;
}
