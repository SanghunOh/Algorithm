#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>
#define INF 99999;

int edge[101][101] = {0};

struct comp{
	bool operator()(std::pair<int, int> a, std::pair<int, int> b){
		return edge[a.first][a.second] > edge[b.first][b.second];
//오름차순
	}
};

int prim(int N, int s){
	int* key;
	bool* sel;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp> pq;
	int sum =0;

	key = new int[N];
	sel = new bool[N];
	std::vector<std::pair<int, int>> path;

	for(int i=0 ; i<N ; i++){
		key[i] = INF;
		sel[i] = false;
	}

	pq.push(std::make_pair(s, s));
	key[s] = 0;

	while(!pq.empty()){
		std::pair<int, int> t = pq.top();
		pq.pop();

		int u = t.first;
		int v = t.second;

		if(sel[u])
			continue;

		sel[u] = true;
		key[u] = edge[u][v];
		path.push_back(std::make_pair(u, v));

		for(int i=0 ; i<N ; i++)
			if(edge[u][i] != 0 && sel[i] == false)
				pq.push(std::make_pair(i, u));
	}

	for(int i=0 ; i<N ; i++){
		sum += key[i];
		std::cout << path[i].first << " -> " << path[i].second << std::endl;
	}

	return sum;
}

int main(){
	int N, M;
	int s;
	

	std::cin >> N >> M;
	std::cin >> s;

	for(int i=0 ; i<M ; i++){
		int u, v, w;
		std::cin >> u >> v >> w;

		edge[u][v] = w;
		edge[v][u] = w;
	}

	std::cout << prim(N, s) << std::endl;

	return 0;
}
