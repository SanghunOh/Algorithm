#include	<iostream>
#include	<vector>
#include	<stack>
#include	<algorithm>

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

struct pos{
	int y, x;
};

int dfs(int**& map, int y, int x, bool**& visit, int N){
	std::stack<pos> s;
	int count = 1;

	s.push({y, x});
	visit[y][x] = true;

	while(!s.empty()){
		int ty = s.top().y;
		int tx = s.top().x;

		s.pop();

		for(int i=0 ; i<4 ; i++){
			int ny = ty + dy[i];
			int nx = tx + dx[i];

			if(nx < 0 || nx > N-1 || ny < 0 || ny > N-1)
				continue;
			if(visit[ny][nx] || !map[ny][nx])
				continue;

			s.push({ny, nx});
			visit[ny][nx] = true;
			count++;
		}
	}
	return count;
}

int dfs_all(int**& map, int N, std::vector<int>& danji){
	int count=0;
	bool** visit;

	visit = new bool*[N];
	for(int i=0 ; i<N ; i++){
		visit[i] = new bool[N];
		std::fill(visit[i], visit[i]+N, false);
	}

	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			if(!visit[i][j] && map[i][j]){
				danji.push_back(dfs(map, i, j, visit, N));
				count++;
			}
		}
	}

	return count;
}

int main(){
	int N;
	int** map;

	std::cin >> N;

	map = new int*[N];
	for(int i=0 ; i<N ; i++)
		map[i] = new int[N];

	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			scanf("%1d", &map[i][j]);

	std::vector<int> danji;

	int a = dfs_all(map, N, danji);
	std::cout << a << std::endl;

	sort(danji.begin(), danji.end());
	for(int i=0 ; i<danji.size() ; i++)
		std::cout << danji[i] << std::endl;
}
