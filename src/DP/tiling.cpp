#include	<iostream>
#include	<cstring>
using namespace std;

int N;
int cache[101];

int tiling(int N){
	if(N <= 1)
		return 1;

	int& ret = cache[N];
	if(ret)
		return ret;

	ret = (tiling(N-2) + tiling(N-1)) % 1000000007;
	return ret;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		cin >> N;
		
		memset(cache, 0, sizeof(cache));
		cout << tiling(N)%1000000007 << '\n';
	}

	return 0;

}
