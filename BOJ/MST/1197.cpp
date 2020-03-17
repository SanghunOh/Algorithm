#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>

typedef struct _struct{
	int u;
	int v;
	int w;
}edge;

bool Comp(edge& a, edge& b){
	return a.w < b.w;
}	

int getParent(int*& parent, int x){
	if(x == parent[x]){
		return x;
	}
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int*& parent, int*& size, int x, int y){
	int u = getParent(parent, x);
	int v = getParent(parent, y);

	parent[u] = v;	
}

int kruskal(std::vector<edge> graph, int N, int M){
	int* parent;
	int* size;
	long long sum = 0;

	size = new int[N];
	parent = new int[N];

	for(int i=0 ; i<N ; i++){
		parent[i] = i;
		size[i] = 1;
	}

	std::sort(graph.begin(), graph.end(), Comp);
	
	for(int i=0 ; i<graph.size() ; i++){
		if(getParent(parent, graph[i].u) != getParent(parent, graph[i].v)){
			sum += graph[i].w;
			unionParent(parent, size, graph[i].u, graph[i].v);
		}
	}

	return sum;
}

int main(){
	int N, M;
	std::vector<edge> graph;
	
	std::cin >> N >> M;


	for(int i=0 ; i<M ; i++){
		int u, v, w;
		std::cin >> u >> v >> w;

		graph.push_back(edge{u, v, w});
	}

	std::cout << kruskal(graph, N, M) << std::endl;

	return 0;
}
