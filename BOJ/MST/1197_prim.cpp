#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>
#define	INF 99999

typedef std::pair<int, int> intPair;

bool comp(intPair& a, intPair& b){
	return a.first > b.first;
}

int prim(std::vector<intPair>* graph, int N, int M){
	int sum = 0;
	int s = 1;
	std::priority_queue<intPair, std::vector<intPair>, std::greater<intPair>> pq;
	std::vector<int> key(N+1, INF);
	std::vector<bool> visit(N+1, false);

	pq.push(std::make_pair(0, s));
	key[s] = 0;

	while(!pq.empty()){
		int u = pq.top().second;

		pq.pop();

		visit[u] = true;

		std::vector<intPair>::iterator i;
		for(int i=0 ; i < graph[u].size() ; i++){
			int v = graph[u][i].second;
			int w = graph[u][i].first;

			if(!visit[v] && key[v] > w){
				key[v] = w;
				pq.push(std::make_pair(key[v], v));
			}
		}
	}
	for(int i=1 ; i<N+1 ; i++)
		sum += key[i];

	return sum;
}

int main(){
	int N, M;
	std::vector<intPair>* graph;

	std::cin >> N >> M;

	graph = new std::vector<intPair> [N+1];

	for(int i=0 ; i<M ; i++){
		int u, v, w;

		std::cin >> u >> v >> w;
		graph[u].push_back(std::make_pair(w, v));
		graph[v].push_back(std::make_pair(w, u));
	}

	std::cout << prim(graph, N, M) << std::endl;
}
