#include	<iostream>
using namespace std;

/*
 *
 * 직각 삼각형 모양의 배열이 주어졌을 때 (0, 0)에서 마지막 행까지 아래 또는 오른쪽 아래방항으로
 * 내려갈 때 각 칸에 있는 숫자의 합의 최대값을 구하는 문제이다.
 *
 * 여기서 하는 계산은 (y, x)에서까지의 최댓값을 구하는 조각이
 * (y-1, x-1) or (y-1, x)에서 계산되므로 중복된다.
 * 이를 위해 이미 계산된 조각인지 확인하기 위해 cache배열을 선언하고
 * 이 배열을 0으로 초기화한다.
 * 각 조각을 계산할 때 cache배열에 0이 들어가있으면 처음 계산하는 조각이므로
 * BruteForce과정에서 진행한 계산을 똑같이 수행해주고 그 값을 cache배열에 저장하면 된다.
 *
 * 만약 cache배열에 0이 들어가 있지 않으면 이미 계산된 조각이라는 뜻이므로 바로 return 한다.
 *
*/

int tri[101][101] = {0};
int cache[101][101] = {0};
int N;

int path(int y, int x){
	if(y == N-1)
		return tri[y][x];

	if(cache[y][x] != 0)
		return cache[y][x];

	return cache[y][x] = (tri[y][x] + max(path(y+1, x), path(y+1, x+1)));
}

int main(){
	int T;

	cin >> T;

	while(T--){
		cin >> N;

		for(int i=0 ; i<N ; i++)
			for(int j=0 ; j<=i ; j++)
				cin >> tri[i][j];

		cout << path(0, 0) << endl;

		for(int i=0 ; i<N ; i++)
			for(int j=0 ; j<=i ; j++){
				tri[i][j] = 0;
				cache[i][j] = 0;
			}
	}
}
