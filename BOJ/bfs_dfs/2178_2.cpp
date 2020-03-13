#include	<iostream>
#include	<queue>

struct maze{
	int x, y;
};

int n, m;
int a[101][101];
int dist[101][101];

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void bfs(){
	queue<maze> q;
	q.push({1, 1});
	dist[1][1] = 1;

	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		if(x == n && y == m){
			std::cout << dist[n][m];
			return;
		}
		for(int i=0 ; i<4 ; i++){
			int nx = x+dx[i], ny = y+dy[i];
			if(nx < 1 || nx > n || ny < 1 || ny > m)
				continue;
			if(dist[nx][ny] || !a[nx][ny])
				continue;
			dist[nx][ny] = dist[x][y]+1;
			q.push({nx, ny});
		}
	}
}

int main(){
	
}
