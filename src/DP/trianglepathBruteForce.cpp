#include	<iostream>
using namespace std;

/*
 *
 * 직각 삼각형 모양의 배열이 주어졌을 때 (0, 0)에서 마지막 행까지 아래 또는 오른쪽 아래방항으로
 * 내려갈 때 각 칸에 있는 숫자의 합의 최대값을 구하는 문제이다.
 *
 *
*/

int tri[101][101] = {0};

int path(int N, int y, int x){
	if(y == N-1)
		return tri[y][x];

	return tri[y][x] + max(path(N, y+1, x), path(N, y+1, x+1));
}

int main(){
	int T;
	
	cin >> T;

	while(T--){
		int N;

		cin >> N;

		for(int i=0 ; i<N ; i++)
			for(int j=0 ; j<=i ; j++)
				cin >> tri[i][j];

		cout << path(N, 0, 0) << endl;
	}
}
