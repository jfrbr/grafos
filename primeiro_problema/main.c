#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VERTEX 100
#define MAX_EDGES 5000


//UNION FIND

int UF[MAX_VERTEX];

int FIND(int x){

		if ( UF[x] == x ) return x;
		else return UF[x] = FIND(UF[x]);

//		return UF[x] == x ? x : UF[x] = FIND(UF[x]);
}

void UNION(int x, int y){
		UF[FIND(x)] = FIND(y);
}

struct E {
	int src, dest, weight;
};

typedef struct E Edge;

Edge Edges[MAX_EDGES];

int compare (const void *x, const void *y){

	int w1 = ((Edge*) x)->weight;
	int w2 = ((Edge*) y)->weight;

	return w1 > w2 ? 1 : 0;
}

int main(){

	int i,n,m,ntests=1;

	while ( scanf ("%d %d\n",&n,&m) == 2 && (n || m) ){
	
		memset(UF,0,sizeof(UF));
		memset(Edges,0,sizeof(Edges));

		for (i=0; i <= n; ++i){
			UF[i] = i;
		}
		

		for (i = 0; i < m; ++i){
			scanf("%d %d %d\n",&Edges[i].src,&Edges[i].dest,&Edges[i].weight);
		}

		qsort(Edges, m, sizeof(Edge), compare);

		/*
		for (i=0; i < m ; ++i){
			printf("%d %d %d\n",Edges[i].src, Edges[i].dest, Edges[i].weight);
		}*/

		printf("Teste %d\n",ntests++);

		for (i = 0; i < m; ++i){
			if ( FIND ( Edges[i].src ) != FIND(Edges[i].dest) ){
				if (Edges[i].src < Edges[i].dest) printf("%d %d\n",Edges[i].src, Edges[i].dest);
				else printf("%d %d\n",Edges[i].dest, Edges[i].src);
				UNION(Edges[i].src, Edges[i].dest);
			}
		}
		printf("\n");
	}
}
