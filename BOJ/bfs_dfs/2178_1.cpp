#include	<iostream>
#include	<algorithm>
#include	<vector>
#include	<queue>

class pos{
public:
	int y;
	int x;

	pos(int y, int x) : y(y), x(x){}
};

int bfsShortestPath(int N, int M, std::vector<pos> **maze, int s_x, int s_y){
	pos tmp(s_x, s_y);
	bool visit[N][M];
	int dist[N][M] = {0};

	for(int i=0 ; i<N ; i++){
		std::fill_n(visit[i], M, false);
	}
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<M ; j++)
			dist[i][j] = 0;

	dist[0][0] = 1;
	visit[s_y][s_x] = true;
	std::queue<pos> q;
	q.push(tmp);

	while(!q.empty()){
		tmp = q.front();
		q.pop();

		for(std::vector<pos>::size_type i=0 ; i<maze[tmp.y][tmp.x].size() ; i++){
			int _y = maze[tmp.y][tmp.x][i].y;
			int _x = maze[tmp.y][tmp.x][i].x;

			if(!visit[_y][_x]){
				visit[_y][_x] = true;
				dist[_y][_x] = dist[tmp.y][tmp.x] + 1;
				q.push(maze[tmp.y][tmp.x][i]);
			}
		}
	}

	return dist[N-1][M-1];
}


int main(){
	int N, M;
	std::cin >> N >> M;

	std::vector<pos>** maze;

	maze = new std::vector<pos>*[N];
	for(int i=0 ; i<N ; i++)
		maze[i] = new std::vector<pos>[M];
	std::string _maze[N];

	for(int i=0 ; i<N ; i++){
		std::cin >> _maze[i];
	}

	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<M ; j++){
			if(j != M-1){
				if(_maze[i][j] == '1' && _maze[i][j+1] == '1'){
					maze[i][j].push_back(pos(i, j+1));
					maze[i][j+1].push_back(pos(i, j));
				}
			}
			if(i != N-1){
				if(_maze[i][j] == '1' && _maze[i+1][j] == '1'){
					maze[i][j].push_back(pos(i+1, j));
					maze[i+1][j].push_back(pos(i, j));
				}
			}
		}
	}


	std::cout << bfsShortestPath(N, M, maze, 0, 0) << std::endl;;

	return 0;
}
