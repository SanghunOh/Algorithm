#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>
using namespace std;

typedef struct _graph{
	int v1;
	int v2;
	int w;
}graph;

bool Comp(graph& a, graph& b){
	return a.w < b.w;
}

int findParent(vector<int> parent, int x){
	while(x != parent[x])
		x = parent[x];
	return x;
}

void unionSet(vector<int>& parent, vector<int>& size, graph& edge){
	int x = findParent(parent, edge.v1);
	int y = findParent(parent, edge.v2);

	if(size[x] > size[y]){
		parent[y] = x;
		size[x] += size[y];
	}
	else{
		parent[x] = y;
		size[y] += size[x];
	}
}

int kruskal(vector<graph> g, int N){
	vector<int> parent(N+1);
	vector<int> size(N+1, 1);
	int ret = 0;

	for(int i=1 ; i<=N ; i++){
		parent[i] = i;
	}

	sort(g.begin(), g.end(), Comp);
	
	for(int i=0 ; i<g.size() ; i++){
		if(findParent(parent, g[i].v1) != findParent(parent, g[i].v2)){
			ret += g[i].w;
			unionSet(parent, size, g[i]);
		}	
	}

	return ret;
}

int main(){
	int N, M;
	vector<graph> g;
	
	cin >> N;
	cin >> M;

	for(int i=0 ; i<M ; i++){
		int u, v, w;

		cin >> u >> v >> w;
		g.push_back(graph{u, v, w});
	}

	cout << kruskal(g, N);
	
	return 0;
}
