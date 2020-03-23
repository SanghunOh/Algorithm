#include	<iostream>
#include	<vector>
#include	<queue>
#define INF	987654321

typedef std::pair<int, int> iPair;

void dijkstra(std::vector<iPair> graph[], int N){
	std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair>> pq;
	std::vector<int> pre(N+1, -1);
	std::vector<int> key(N+1, INF);

	pq.push(std::make_pair(0, 1));

	while(!pq.empty()){
		int u = pq.top().second;
		int dist = pq.top().first;

		pq.pop();

		for(int i=0 ; i<graph[u].size() ; i++){
			int v = graph[u][i].first;
			int w = graph[u][i].second;

			if(key[v] > w + dist){
				key[v] = w + dist;
				pre[v] = u;
				pq.push(std::make_pair(key[v], v));
			}
		}
	}
	for(int i=2 ; i<=N ; i++){
		std::cout << i << " " << pre[i] << std::endl;
	}
}

int main(){
	int N, M;
	std::vector<iPair> graph[1001];

	std::cin >> N >> M;

	for(int i=0 ; i<M ; i++){
		int u, v, w;

		std::cin >> u >> v >> w;

		graph[u].push_back(std::make_pair(v, w));
		graph[v].push_back(std::make_pair(u, w));
	}

	std::cout << N-1 << std::endl;
	dijkstra(graph, N);

	return 0;
}
