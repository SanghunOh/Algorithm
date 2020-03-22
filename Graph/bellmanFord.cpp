#include	<iostream>
#include	<algorithm>
#include	<vector>
#define INF	99999

typedef struct {
	int u;
	int v;
	int w;
}edge;


void BellmanFord(std::vector<edge> graph, int N, int M, int s){
	std::vector<int> d(N, INF);
	std::vector<int> path(N, -1);
	int sum = 0;

	d[s] = 0;

	for(int i=0 ; i<N-1 ; i++){
		for(int j=0 ; j<M ; j++){
			int u = graph[j].u;
			int v = graph[j].v;
			int w = graph[j].w;

			if(d[v] > d[u] + w && d[u] != INF)
				d[v] = d[u] + w;
		}
	}

	for(int i=0 ; i<N ; i++){
		std::cout << "To I : " << d[i] << std::endl;
	}
}

int main(){
	int N, M;
	int s;
	std::vector<edge> graph; 

	std::cin >> N >> M;
	std::cin >> s;

	for(int i=0 ; i<M ; i++){
		int u, v, w;
		std::cin >> u >> v >> w;

		graph.push_back(edge{u, v, w});
	}

	BellmanFord(graph, N, M, s);

	return 0;
}
