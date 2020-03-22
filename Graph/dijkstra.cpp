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
	edge t{s, s, 0};
	std::vector<int> d(N, INF);
	std::vector<int> pre(N, -1);
	std::vector<bool> checked(N, false);
	std::priority_queue<edge, std::vector<edge>, comp> pq;

	d[s] = 0;
	checked[s] = true;
	pq.push(t);
	printf("1\n");

	while(!pq.empty()){
		t = pq.top();
		int u = t.v;
		int dist = -t.w;

		checked[u] = true;
		if(d[u] < dist)
			continue;
		for(int i=0 ; i<graph[u].size() ; i++){
			int v = graph[u][i].v;
			
			if(dist + graph[u][i].w > d[v] && !checked[v]){
				d[v] = dist + graph[u][i].w;
				pre[v] = u;
				pq.push(edge{0, v, -d[v]});
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
