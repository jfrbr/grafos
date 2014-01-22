#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 150
#define INF 2000000000

int n;
int g[MAX][MAX];
int parent[MAX];
int queue[MAX],ind;

// queue implementation

void push(int elem){
	printf("Index = %d\n",ind);
	queue[ind++] = elem;
}

int front(){
	return ind > 0 ? queue[0] : -999 ;
}

void pop(){
	int i;
	for (i=1; i <= ind; ++i){
		queue[i-1] = queue[i];
	}
	ind--;
}

int empty(){
	return ind == 0 ? 1 : 0;
}

// max flow algorithm

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

	int flow=0,i,dist[MAX];
	memset(dist,0,sizeof(dist));

	while (1){

		f = 0;

		push(s);
		dist[s] = 0;

		while ( !empty() ){

			int u = front();
			pop();
			if (u == t) break;

			for (i=1;i<=n;++i){
				if ( g[u][i] > 0 && !dist[i] ){
					dist[i] = dist[u] + 1 ;
					push(i);
					parent[i] = u;
				}
			}	
		
		}

		augment_path(t,INF);

		if (f == 0) break;
		flow += f;
	}

	return flow;
}

int main(){

	int i,c,a,b,w,tests=1;

	while ( scanf("%d\n",&n) == 1 && n ){

		memset(g,0,sizeof(g));
		memset(parent,-1,sizeof(parent));
		memset(queue,0,sizeof(queue));

		f = s = t = 0;

		scanf("%d %d %d\n",&s,&t,&c);


		for (i=0;i<c;++i){
			scanf("%d %d %d\n",&a,&b,&w);
			g[a][b] = w;
			g[b][a] = w;
//			printf("%d %d %d\n",a,b,w);
		}

		int res = max_flow(s,t);

		printf("Rede %d\nA largura de banda é %d.\n",tests++,res);
	
	}
	return 0;
}
