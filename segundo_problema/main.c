#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000
#define INF 2000000000

int n;
int g[MAX][MAX];
int parent[MAX];
int queue[MAX],ind;

void push(int elem){
	queue[ind++] = elem;
}

int front(){
	return queue[0];
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
void print(){
	printf("Queue:");
	int i;
	for(i=0; i < ind; ++i){
		printf("%d ",queue[i]);
	}
	printf("\n");
}


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
	memset(parent,-1,sizeof(parent));

	while (1){

		f = 0;
	
		memset(parent,-1,sizeof(parent));
		memset(queue,0,sizeof(queue));
		ind = 0;
		for (i=0;i <= n; ++i) dist[i] = INT_MAX;

		push(src);
		dist[src] = 0;

		while ( !empty() ){

			int u = front();
			pop();
			if (u == dest) break;

			for (i=1;i<=n;++i){
				if ( g[u][i] > 0 && dist[i] == INT_MAX ){
					dist[i] = dist[u] + 1 ;
					push(i);
					parent[i] = u;
				}
			}	
		
		}
		
		augment_path(dest,INT_MAX);

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

		s = t = 0;

		scanf("%d %d %d\n",&s,&t,&c);


		for (i=0;i<c;++i){
			scanf("%d %d %d\n",&a,&b,&w);
			g[a][b] += w;
			g[b][a] += w;
		}

		int res1 = max_flow(s,t);
		
		printf("Network %d\nThe bandwidth is %d.\n\n",tests++, res1);
	
	}
	return 0;
}
