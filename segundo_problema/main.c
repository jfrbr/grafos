#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 150

int g[MAX][MAX];

int main(){

	int i,n,s,t,c,a,b,w;

	while ( scanf("%d\n") == 1 && n ){

		memset(g,0,sizeof(g));

		scanf("%d %d %d\n",&s,&t,&c);

		for (i=0;i<c;++i){
			scanf("%d %d %d\n",&a,&b,&w);
			g[a][b] = 1;
			g[b][a] = 1;
		}

		// max flow
		// print solucao




	
	}


	return 0;
}
