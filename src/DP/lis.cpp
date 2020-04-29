#include	<iostream>
#include	<cstring>
#include	<vector>
using namespace std;

/*
 * 브루트 포스와 똑같은 알고리즘이다. 매개변수 또한 똑같다.
 * 배열이 1 2 3 4일때
 * lis배열로 채택한 배열이 1 2 3 4인 배열과
 * 2 3 4인 배열에서 2 3 4 배열과 그 하위 배열을 findLis를 수행하는 조각이 중복된다
 * 따라서 조각을 계산할 때마다 그 값을 cache배열에 저장한다. *
 *
*/

int N;
int cache[501];

int findLis(vector<int>& lis){
	int ret = 0;

	if(lis.empty())
		return 0;

	for(int i=0 ; i<lis.size() ; i++){
		if(cache[lis[i]]){
			ret =  max(ret, cache[i]);
		}
		else{
			vector<int> b;
	
			for(int j=i+1 ; j<lis.size() ; j++)
				if(lis[i] < lis[j])
					b.push_back(lis[j]);
			cache[i] = max(ret, findLis(b) + 1);
			ret = cache[i];
		}
	}

	return ret;
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

		memset(cache, 0, sizeof(cache));
		cout << findLis(lis) << endl;
	}
}
