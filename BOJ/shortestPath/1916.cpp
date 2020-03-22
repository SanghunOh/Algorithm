#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>
#define INF	987654321

void dijkstra(std::vector<std::pair<int, int>> graph[], int N, int from, int to){
	std::vector<int> d(N+1, INF);
	std::priority_queue<std::pair<int, int>> pq;

	pq.push(std::make_pair(0, from));

	while(!pq.empty()){
		int u = pq.top().second;
		int w = -pq.top().first;

		pq.pop();

		for(int i=0 ; i<graph[u].size() ; i++){
			int v = graph[u][i].first;
			int _w = graph[u][i].second;

			if(d[v] > w + _w){
				d[v] = w + _w;
				pq.push(std::make_pair(-d[v], v));
			}
		}
	}
	std::cout << d[to] << std::endl;
}

int main(){
	int N, M;
	std::vector<std::pair<int, int>> graph[1001];

	std::cin >> N >> M;

	for(int i=0 ; i<M ; i++){
		int u, v, w;
		std::cin >> u >> v >> w;

		graph[u].push_back(std::make_pair(v, w));
	}
	int from, to;
	std::cin >> from >> to;

	dijkstra(graph, N, from, to);

	return 0;
}
