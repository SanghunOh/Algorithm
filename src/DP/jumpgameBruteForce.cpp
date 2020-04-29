#include	<iostream>
#include	<vector>
using namespace std;

bool jumpgame(const vector<vector<int>>& jump, int N, int y, int x){
	if(y <0 || y>N-1 || x<0 || x>N-1)
		return false;
	if(y == N-1 && x == N-1)
		return true;

	if(jumpgame(jump, N, y, x+jump[y][x]) || jumpgame(jump, N, y+jump[y][x], x))
		return true;
	return false;
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
			for(int j=0 ; j<N ; j++)
				cin >> jump[i][j];
		}

		if(jumpgame(jump, N, 0, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
