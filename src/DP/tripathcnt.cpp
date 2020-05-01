#include	<iostream>
#include	<cstring>
using namespace std;

int N;
int tri[101][101];
int cntCache[101][101];

int pathcnt(int y, int x){
	int& ret = cntCache[y][x];
	if(y == N-1)
		return ret = 1;

	if(ret != -1)
		return ret;

	ret = 0;
	if(count(y+1, x) >= count(y+1, x+1))
		return ret += pathcnt(y+1, x);
	if(count(y+1, x) <= count(y+1, x+1))
		return ret += pathcnt(y+1, x+1);
	return ret;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		cin >> N;

		memset(tri, -1, sizeof(tri));
		memset(cntCache, -1, sizeof(cntCache));
		for(int i=0 ; i<N ; i++)
			for(int j=0 ; j<=i ; j++)
				cin >> tri[i][j];

		cout << pathcnt(0, 0) << endl;
	}

	return 0;
}
