#include	<iostream>
#include	<vector>
using namespace std;

/*
 *
 * 인원수, 짝의수가 입력으로 주어지고, 서로 친구인 사람의 번호가 주어질 때, 
 * 2명 씩 짝 지을 수 있는 경우의 수
 *
 * -> 모든 조합을 고려해봐야한다. -> 조합은 check 배열을 true -> 함수 호출 -> false식으로 구한다.
 *  2명씩 짝을 지어야하므로 두 개의 변수를 가지고 check를 고려해야한다.
 *  2명을 고르는 방법에 대표적으로 이중 for문이 있지만 이럴경우 중복되는 것이 생긴다.
 *  ex) (0, 1), (1, 0) / ((0, 1), (2, 3)), ((2, 3), (0, 1))
 *
 *  따라서 순서를 강제로 지정해야한다.
 *  그 방법으로 check되지 않은 가장 빠른 번호를 구한 다음 그 이후의 번호와 검사하는것이다.
 *
*/
int findPair(bool areFriends[][11], int n, int m, bool check[]){
	int first = -1;
	int sum = 0;

	for(int i=0 ; i<n ; i++){
		if(!check[i]){
			first = i;
			break;
		}
	}
	
	if(first == -1)
		return 1;

	for(int i=first+1 ; i<n ; i++){
		if(!check[i] && areFriends[first][i]){
			check[i] = check[first] = true;
			sum += findPair(areFriends, n, m, check);
			check[i] = check[first] = false;
		}
	}

	return sum;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		int n, m;
		bool areFriends[11][11] = {false};
		bool check[11] = {false};

		cin >> n >> m;

		for(int i=0 ; i<m ; i++){
			int f1, f2;

			cin >> f1 >> f2;

			areFriends[f1][f2] = true;
			areFriends[f2][f1] = true;
		}

		cout << findPair(areFriends, n, m, check) << endl;
	}
}
