#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<stack>
#include	<queue>

bool visit[101];

int dfs(std::vector<int> virus[], int start){
	if(virus[start].empty())
		return 0;

	std::stack<int> s;
	int count = 0;

	s.push(start);

	visit[start] = true;

	while(!s.empty()){
		int tmp = s.top();
		s.pop();

		for(std::vector<int>::size_type i=0 ; i<virus[tmp].size() ; i++){
			if(!visit[virus[tmp][i]]){
				visit[virus[tmp][i]] = true;

				count++;

				s.push(tmp);
				s.push(virus[tmp][i]);
				
				break;
			}
		}
	}

	return count;
}

int bfs(std::vector<int> virus[], int start){
	if(virus[start].empty())
		return 0;

	std::queue<int> q;
	int count = -1;

	q.push(start);
	visit[start] = true;

	while(!q.empty()){
		int tmp = q.front();
		q.pop();

		count++;
		for(int i=0 ; i<virus[tmp].size() ; i++){
			if(!visit[virus[tmp][i]]){
				visit[virus[tmp][i]] = true;
				q.push(virus[tmp][i]);
			}
		}
	}

	return count;
}

int main(){
	int N, M;

	std::cin >> N;
	std::cin >> M;

	std::vector<int> virus[N+1];

	std::fill(visit, visit+N+1, false);

	for(int i=0 ; i<M ; i++){
		int u, v;

		std::cin >> u >> v;

		virus[u].push_back(v);
		virus[v].push_back(u);
	}

//	if(!M)
//		std::cout << 0 << std::endl;
//	else{
//		std::cout << dfs(virus, 1) << std::endl;
//	}

	std::fill(visit, visit+N+1, false);

	if(!M)
		std::cout << 0 << std::endl;
	else
		std::cout << bfs(virus, 1) << std::endl;

	return 0;
}
