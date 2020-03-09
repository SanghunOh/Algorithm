#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<stack>

void dfs(std::vector<int> graph[], bool visit[], int N, int M, int start){
	std::stack<int> s;

	s.push(start);
	visit[start] = true;

	while(!s.empty()){
		int tmp = s.top();
		s.pop();

		for(int i=0 ; i<graph[tmp].size() ; i++){
			if(!visit[graph[tmp][i]]){
				std::cout << graph[tmp][i] << " ";
				visit[graph[tmp][i]] = true;
				s.push(tmp);
				s.push(graph[tmp][i]);
				break;
			}
		}
	}
	std::cout << '\n';

}

int main(){
	int N, M;
	
	std::cin >> N >> M;

	std::vector<int> graph[N+1];
	bool visit[N+1];

	std::fill(visit, visit+N, false);

	for(int i=0 ; i<M ; i++){
		int u, v;

		std::cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(graph, visit, N, M, 1);

	return 0;
}
