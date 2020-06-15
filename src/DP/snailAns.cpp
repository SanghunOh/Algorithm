#include	<iostream>
using namespace std;


int n, m;
int cache[1001][1001];

int climb(int days, int climbed){
	if(days == m)
		return climbed >= n ? 1 : 0;
	
	int& ret = cache[days][climbed];
	if(ret != -1)
		return ret;
	return ret = climb(days+1, climbed+1) + climb(days+1, climbed+2);
}
// 확률이 50%일 경우에는 경우의 수로 할 수 있지만 50%가 아니면 확률로 해야한다!
int main(){
	int T;

	cin >> T;

	while(T--){
		cin >> n >> m;

		cout << climb(0, 0) / 2^m << endl;
	}
}
