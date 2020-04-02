#include	<iostream>

int main(){
	int N;
	long A[100001] = {0};
	long DP[100001]={0};

	std::cin >> N;

	for(int i=1 ; i<=N ; i++)
		std::cin >> A[i];

	DP[1] = A[1];
	for(int i=2 ; i<=N ; i++){
		DP[i] = std::max(DP[i-1] + A[i] , A[i]);
	}

	long max = DP[1];
	for(int i=1 ; i<=N ; i++)
		max = std::max(max, DP[i]);
	std::cout << max << std::endl;
}
