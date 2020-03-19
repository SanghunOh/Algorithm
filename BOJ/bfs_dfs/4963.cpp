#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void bfs(int graph[][1001], bool visit[][1001], int N, int M, int y, int x){
	std::queue<std::pair<int, int>> q;

	q.push(std::make_pair(y, x));
	visit[y][x] = true;

	while(!q.empty()){
		int _y = q.front().first;
		int _x = q.front().second;
		q.pop();

		for(int i=0 ; i<8 ; i++){
			int tmp_y = _y + dy[i];
			int tmp_x = _x + dx[i];

			if(tmp_y < 0 || tmp_y >= N || tmp_x < 0 || tmp_x >= M)
				continue;

			if(!visit[tmp_y][tmp_x] && graph[tmp_y][tmp_x]){
				q.push(std::make_pair(tmp_y, tmp_x));
				visit[tmp_y][tmp_x] = true;
			}
		}
	}
}

int bfs_all(int graph[][1001], const int N, const int M){
	bool visit[1001][1001];
	int count = 0;
	
	for(int i=0 ; i<101 ; i++)
		for(int j=0 ; j<101 ; j++)
			visit[i][j] = false;


	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<M ; j++){ 
			if(!visit[i][j] && graph[i][j]){
				count++;
				bfs(graph, visit, N, M, i, j);
			}
		}
	}
	return count;
}

int main(){
	while(1){
		int N, M;
		int graph[1001][1001];
 
		std::cin >> M >> N;
		
		if(!N && !M)
			break;

		for(int i=0 ; i<N ; i++)
			for(int j=0 ; j<M ; j++)
				std::cin >> graph[i][j];

		std::cout << bfs_all(graph, N, M) << std::endl;
	}

	return 0;
}
