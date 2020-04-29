#include	<iostream>
#include	<vector>
using namespace std;

/*
 *
 * jumpgame 
 * N*N격자에 숫자가 입력된다. 각 칸에 있는 숫자는 오른쪽 또는 아래방항으로
 * 갈 수 있는 칸의 개수이다.
 * 이때 (0, 0)에서 시작하여 (N-1, N-1)에 도달할 수 있는지 여부를 확인한다.
 *
 * 이 문제를 BruteForce문제에서 DP로 전환할 때 어떤 상황에서
 * 중복계산을 하는 부분이 생기는지 파악하는게 가장 우선인 것 같다.
 *
 * 중복계산이 생기는 상황을 파악한 후 메모이제이션을 활용할 배열을 어떠헥 사용할지 생각한다.
 * cache 배열에 우선 기본값을 지정하면 재귀호출과정에서 배열에 기본값이 아닌 다른 값이 들어가 있다는 것은
 * 이미 이전에 계산한 값이고 한 번 더 계산할 필요가 없다는 것을 의미한다.
 *
 * 배열에 기본값이 들어가있으면 처음하는 계산이므로 계산을 진행한다.
 *
*/
int cache[100][100];

int jumpgame(vector<vector<int>> jump, int N, int y, int x){
	if(y > N-1 || x > N-1)
		return 0;
	if(y == N-1 && x == N-1)
		return 1;

	int& ret = cache[y][x];

	if(ret != -1)
		return ret;

	return ret = (jumpgame(jump, N, y+jump[y][x], x) || jumpgame(jump, N, y, x+jump[y][x]));
}

int main(){
	int T;

	cin >> T;
	
	while(T--){
		int N;
		vector<vector<int>> jump;

		cin >> N;

		jump.resize(N);
		for(int i=0 ; i<N ; i++){
			jump[i].resize(N);
			for(int j=0 ; j<N ; j++){
				cin >> jump[i][j];
				cache[i][j] = -1;
			}
		}

		if(jumpgame(jump, N, 0, 0) == -1)
			cout << "NO" << endl;
		else 
			cout << "YES" << endl;
	}
}
