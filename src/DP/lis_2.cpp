#include	<iostream>
#include	<vector>
#include	<cstring>
using namespace std;

/*
 *
 * lis.cpp의 findLis와 다르게 이 findLis는 매개변수로 시작위치만을 받는다.
 * 따라서 처음 start는 무조건 lis의 첫 번째 수라고 박아놓고 시작한다.
 *
 * 앞의 findLis와 마찬가지로 cache[start]가 이미 계산된 값이라면
 * 다시 계산할 필요가 없으므로 바로 cache[start]를 리턴한다.
 *
 * 아니라면 start...N-1까지의 수까지 lis[start]보다 큰 수에 대해
 * findLis를 진행하고 이를 cache에 저장한다.
 * 또한 이findLis함수는 현재 start를 항상 포함한다는 특징이 있다.
 * -> cache[start]를 1로 초기화한다.
*/

int N;
int cache[501];
int lis[501];

int findLis(int start){
	int& ret = cache[start];

	if(cache[start])
		return cache[start];

	ret = 1;
	for(int i=start+1 ; i<N ; i++)
		if(lis[start] < lis[i])
			ret = max(findLis(i)+1, ret);

	return ret;
}

int findLis2(int start){
	int& ret = cache[start+1];

	if(ret)
		return ret;
	ret = 1;

	for(int i=start+1 ; i<N ; i++)
		if(start == -1 ||lis[start] < lis[i]) // start가 -1일때는 무조건 findLis를 호출한다.
			ret = max(findLis2(i)+1, ret);

	return ret;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		int max_lis = 0;
		cin >> N;

		for(int i=0 ; i<N ; i++)
			cin >> lis[i];
		memset(cache, 0, sizeof(cache));

		for(int i=0 ; i<N ; i++)		// 함수에서 시작위치가 고정되어있을 때 쓰는 기법
			max_lis = max(max_lis, findLis(i));
		cout << max_lis << endl;

		memset(cache, 0, sizeof(cache));

		cout << findLis2(-1)-1 << endl; 	//위의 과정을 대체할 수 있는 기법이다.
							//위의 과정을 한 번더 수행하므로 1을 빼줘야함
	}
}
