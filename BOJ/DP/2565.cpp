#include	<iostream>
#include	<queue>

/*
 *
 * 전깃줄 문제
 * 입력으로 꼬여잇는 전깃줄의 번호가 들어온다.
 * 이때 서로 교차하지 않도록 하기 위해 없애야 하는 전깃줄의 최소개수는 
 * 전체 전깃줄의 개수에서 가장 긴 증가하는 부분 수열의 크기를 빼주면 된다.
 *
*/

typedef std::pair<int, int> iPair;

int main(){
	int N;
	int A[501] = {0};
	int DP[501] = {0};
	std::priority_queue<iPair> q;

	std::cin >> N;

	for(int i=1 ; i<=N ; i++){
		int a, b;

		std::cin >> a >> b;

		q.push(std::make_pair(-a, b));
	}

	for(int i=1 ; i<=N ; i++){
		A[i] = q.top().second;
		q.pop();
	}

	for(int i=1 ; i<=N ; i++){
		if(A[i])
			DP[i] = 1;
		for(int j=1 ; j<=i ; j++){
			if(A[j] < A[i] && DP[j]+1 > DP[i])
				DP[i] = DP[j]+1;
		}
	}

	int max = 0;
	for(int i=1 ; i<=N ; i++){
		max = std::max(max, DP[i]);
	}
	std::cout << N-max << std::endl;
}
