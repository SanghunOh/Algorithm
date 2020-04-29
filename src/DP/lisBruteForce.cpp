#include	<iostream>
#include	<vector>
using namespace std;

/*
 *
 * 간단한 lis문제이다.
 * bruteforce 문제를 너무 배열의 인덱스만을 이용해서 풀려고 하면 안된다.
 * 처음에 start를 함수에 전달받아서
 * for(int j=start+1 ; j<length ; j++){
 *	if(lis[i] >= lis[j])
 *		continue;
 *	findLis(lis, N, j);
 * }
 * 이런식으로 했다.
 *
 * 이런 방식이 아니라 현재 인덱스의 수보다 큰 숫자들을 모은 배열을 만들어서
 * 그 배열을 전달하면 굳이 인덱스에 집착하지 않을 수 있다.
 *
*/


bool check[101] = {false};
int N;

int findLis(vector<int>& lis){
	int max_len = 0;

	if(lis.empty())
		return 0;

	for(int i=0 ; i<lis.size() ; i++){	//첫 번째 재귀호출에서 배열의 모든 수에 대해 검사한다.
		vector<int> b;			//인덱스에 연연하지 않는다.

		for(int j=i+1 ; j<lis.size() ; j++){
			if(lis[i] < lis[j])
				b.push_back(lis[j]);
		}
		max_len = max(max_len, findLis(b)+1);
	}

	return max_len;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		vector<int> lis;

		cin >> N;
		lis.resize(N);

		for(int i=0 ; i<N ; i++)
			cin >> lis[i];

		cout << findLis(lis) << endl;
	}
}
