#include	<iostream>
#include	<queue>
#include	<vector>
#define INF	987654321

typedef std::pair<int, int> iPair;
int N, M, start;
int d[20010];
std::vector<iPair> graph[20010];


void dijkstra(){
	std::priority_queue<iPair> pq;
	d[start] = 0;
	pq.push(std::make_pair(0, start));

	while(!pq.empty()){
		int u = pq.top().second;
		int dist = -pq.top().first;

		pq.pop();

		for(int i=0 ; i<graph[u].size() ; i++){
			int v = graph[u][i].first;
			int w = graph[u][i].second;

			if(d[v] > dist + w){
				d[v] = dist + w;
				pq.push(std::make_pair(-d[v], v));
			}
		}
	}

	for(int i=1 ; i<=N ; i++){
		if(d[i] == INF)
			std::cout << "INF\n";
		else
			std::cout << d[i] << "\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	std::cin >> start;

	for(int i=0 ; i<M ; i++){
		int u, v, w;
		std::cin >> u >> v >> w;

		graph[u].push_back(std::make_pair(v, w));
	}

	for(int i=1 ; i<=N ; i++)
		d[i] = INF;

	dijkstra();

	return 0;
}
