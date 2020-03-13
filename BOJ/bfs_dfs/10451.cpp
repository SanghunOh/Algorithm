#include	<iostream>
#include	<algorithm>
#include	<vector>
#include	<queue>
#include	<stack>
/*
void bfs(std::vector<int>* graph, int start, bool*& visit){
	std::queue<int> q;

	q.push(start);
	visit[start] = true;

	while(!q.empty()){
		int tmp = q.front();
		q.pop();

		for(std::queue<int>::size_type i=0 ; i<graph[tmp].size() ; i++){
			if(!visit[graph[tmp][i]]){
				visit[graph[tmp][i]] = true;
				q.push(graph[tmp][i]);
			}
		}
	}
}

int bfs_all(std::vector<int>* graph, int N){
	bool*visit;
	int count=0;

	visit = new bool[N+1];
	std::fill(visit, visit+N+1, false);

	for(int i=1 ; i<=N ; i++){
		if(!visit[i]){
			bfs(graph, i, visit);
			count++;
		}
	}

	return count;
}
*/
void dfs(const std::vector<int>* graph, const int N, bool* visit){
	std::stack<int> s;

	s.push(N);
	visit[N] = true;

	while(!s.empty()){
		int tmp = s.top();
		s.pop();

		for(std::stack<int>::size_type i=0 ; i<graph[tmp].size() ; i++){
			if(!visit[graph[tmp][i]]){
				visit[graph[tmp][i]] = true;
				s.push(tmp);
				s.push(graph[tmp][i]);
			}
		}
	}
} 

int dfs_all(std::vector<int>* graph, int N){
	bool* visit;
	int count=0;

	visit = new bool[N+1];
	std::fill(visit, visit+N+1, false);

	for(int i=1 ; i<=N ; i++){
		if(!visit[i]){
			dfs(graph, i, visit);
			count++;
		}
	}
	return count;
}

int main(){
	int T;

	std::cin >> T;

	for(int i=0 ; i<T ; i++){
		int N;
		std::vector<int> *graph;

		std::cin >> N;

		graph = new std::vector<int> [N+1];

		for(int i=0 ; i<N ; i++){
			int tmp;
			std::cin >> tmp;
			
			graph[i+1].push_back(tmp);
		}

//		std::cout << bfs_all(graph, N) << std::endl;
		std::cout << dfs_all(graph, N) << std::endl;
	}
}
