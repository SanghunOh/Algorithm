#include	<iostream>
#include	<vector>
#include	<queue>
#define INF	99999

typedef std::vector<int, int> iPair;

int findmin(std::vector<int>& d, std::vector<bool>& visit, int N){
	int min = INF;
	int index = 0;
	for(int i=0 ; i<N ; i++){
		if(d[i] < min && !visit[i]){
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int**& edge, int N, int s){
	std::vector<int> d(N, INF);
	std::vector<int> pre(N, -1);
	std::vector<bool> visit(N, false);

	visit[s] = true;

	for(int i=0 ; i<N ; i++)
		d[i] = edge[s][i];
	d[s] = 0;

	for(int i=0 ; i<N-1 ; i++){
		int u = findmin(d, visit, N);
		visit[u] = true;

		for(int j=0 ; j<N ; j++){
			if(!visit[j]){
				if(d[j] > d[u] + edge[u][j]){
					d[j] = d[u] + edge[u][j];
					pre[j] = u;
				}
			}
			
		}
	}

	for(int i=0 ; i<N ; i++){
		std::cout << "TO " << i << " : " << d[i] << std::endl;
	}

	return;
}

int main(){
	int N, M;
	int s;
	int** graph;

	std::cin >> N >> M >> s;

	graph = new int*[N];
	for(int i=0 ; i<N ; i++){
		graph[i] = new int[N];
		std::fill(graph[i], graph[i]+N, INF);
	}

	for(int i=0 ; i<M ; i++){
		int u, v, w;

		std::cin >> u >> v >> w;
		
		graph[u][v] = w;
	}

	dijkstra(graph, N, s);

	return 0;
}
