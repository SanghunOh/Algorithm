#include	<iostream>
#include	<queue>
#include	<vector>
#include	<algorithm>


void print_path(int pred[], std::vector<int> graph[], int from, int to){
	if(from == to)
		std::cout << from << " ";
	else if(pred[to] == -1)
		std::cout << "no path" << std::endl;
	else
		print_path(pred, graph,from, pred[to]);
}

int bfs(std::vector<int> graph[], bool visit[], int from, int to, int N){
	std::queue<int> q;
	int dis[N];
	int pred[N];

	std::fill(pred, pred+N, -1);

	dis[from] = 0;
	pred[from] = 0;

	q.push(from);
	visit [from] = true;

	while(!q.empty()){
		int t = q.front();
		q.pop();

//		if(t == to)
//			break;

		for(int i=0 ; i<graph[t].size() ; i++){
			if(visit[graph[t][i]])
				continue;

			dis[graph[t][i]] = dis[t] + 1;
			pred[graph[t][i]] = t;
			visit[graph[t][i]] = true;
			q.push(graph[t][i]);
		}
	}

	print_path(pred, graph, from, to);
	std::cout << std::endl;

	return dis[to];
}


int main(){
	int N, M;
	int from, to;
	
	std::cin >> N >> M;
	std::cin >> from >> to;
	std::vector<int> graph[N];
	bool visit[N];

	std::fill(visit, visit+N, false);

	for(int i=0 ; i<M ; i++){
		int u, v;
		std::cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int a = bfs(graph, visit, from, to, N);

	std::cout << "Shortest Paht from " << from << " to " << to << " : " << a << std::endl;

	return 0;
}
