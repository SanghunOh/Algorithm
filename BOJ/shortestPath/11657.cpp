#include	<iostream>
#include	<vector>
#include	<queue>
#define INF 987654321

typedef struct {
	int u;
	int v;
	int w;
}edge;

void bellmanFord(std::vector<edge> e, int N, int M){
	std::vector<int> d(N+1, INF);
	std::vector<bool> visit(N+1, false);
	bool neg = false;

	d[1] = 0;

	for(int i=1 ; i<=N ; i++){
		for(int j=0 ; j<M  ; j++){
			int u = e[j].u;
			int v = e[j].v;
			int w = e[j].w;

			if(d[v] > d[u] + w && d[u] != INF){
				d[v] = d[u] + w;
				if(i==N)
					neg = true;
			}
		}
	}

	if(neg){
		std::cout << -1 << std::endl;
		return;
	}

	for(int i=2 ; i<=N ; i++){
		if(d[i] == INF)
			std::cout << -1 << std::endl;
		else
			std::cout << d[i] << std::endl;
	}
}

int main(){
	int N, M;
	std::vector<edge> e;

	std::cin >> N >> M;

	for(int i=0 ; i<M ; i++){
		int u, v, w;

		std::cin >> u >> v >> w;

		e.push_back(edge{u, v, w});
	}

	bellmanFord(e, N, M);

	return 0;
}
