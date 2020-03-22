#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<queue>
#define	INF	99999

typedef struct{
	int u, v, w;
}edge;

struct comp{
	bool operator()(edge& a, edge& b){
		return a.w > b.w;
	}
};

void Dijkstra(std::vector<edge>*& graph, const int N, const int M, const int s){
	std::vector<int> d(N, INF);
	std::vector<int> pre(N, -1);
	std::priority_queue<std::pair<int, int>> pq;
	pq.push(std::make_pair(s, 0));

	d[s] = 0;

	while(!pq.empty()){
		int u = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if(d[u] < distance) // 이미 최단경로가 정해진 노드 제외
			continue;
		for(int i=0 ; i<graph[u].size() ; i++){
			int v = graph[u][i].v;
			
			if(d[v] > distance + graph[u][i].w){
				d[v] = distance + graph[u][i].w;
				pre[v] = u;
				pq.push(std::make_pair(v, -d[v]));
			}
		}
	}


	for(int i=0 ; i<N ; i++){
		std::cout << "TO " << i << " : " << d[i] << std::endl;
	}

	return;
}

int main(){
	int N, M, s;
	std::vector<edge>* graph;

	std::cin >> N >> M >> s;

	graph = new std::vector<edge>[N];

	for(int i=0 ; i<M ; i++){
		int u, v, w;

		std::cin >> u >> v >> w;

		graph[u].push_back(edge{u, v, w});
	}

	Dijkstra(graph, N, M, s);

	return 0;
}
