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
	//printf("Inserindo o %d na posicao %d\n",elem,ind);
	queue[ind++] = elem;
}

int front(){
	return ind > 0 ? queue[0] : -999 ;
}

void pop(){
	//printf("Removendo\n");
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
	memset(parent,-1,sizeof(parent));
	memset(queue,0,sizeof(queue));
	ind = f = 0;

	while (1){

		f = 0;

		memset(dist,-1,sizeof(dist));

		push(src);
		//print();
		dist[src] = 0;

		while ( !empty() ){

			int u = front();
			pop();
		//	print();
			if (u == dest) break;

			for (i=1;i<=n;++i){
				if ( g[u][i] > 0 && dist[i] == -1 ){
					dist[i] = dist[u] + 1 ;
					push(i);
	//				print();
					parent[i] = u;
				}
			}	
		
		}
		
		augment_path(dest,INF);

		if (f == 0) break;
		//printf("f = %d\n",f);
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
//		printf("Source = %d | Destiny = %d\n",s,t);


		for (i=0;i<c;++i){
			scanf("%d %d %d\n",&a,&b,&w);
			g[a][b] = w;
			g[b][a] = w;
//			printf("%d %d %d\n",a,b,w);
		}

		int res1 = max_flow(s,t);
		
	//	int res2 = max_flow(t,s);

		printf("Network %d\nThe bandwidth is %d.\n\n",tests++, res1);
	
	}
	return 0;
}
