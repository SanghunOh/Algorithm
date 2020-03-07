#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>

void bfs(std::vector<int> graph[], bool check[], int first, int N, int M){
	std::queue<int> q;

	q.push(first);
	check[first] = true;

	while(!q.empty()){
		int trav = q.front();
		q.pop();

		std::cout << trav << " ";
		for(int i=0 ; i<graph[trav].size() ; i++){
			if(!check[graph[trav][i]]){
				check[graph[trav][i]] = true;
				q.push(graph[trav][i]);
			}
		}
	}
}

int main(){
	int N;
	int M;
	std::cin >> N >> M;

	std::vector<int> graph[N];
	bool check[N];

	std::fill(check, check+N, false);

	for(int i=0 ; i<M ; i++){
		int u, v;

		std::cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

		bfs(graph, check, 2, N, M);
		std::cout << std::endl;
	
	return 0;
}
