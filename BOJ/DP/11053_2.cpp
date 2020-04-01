#include	<iostream>

int main(){
	int N;
	int A[1001];
	int LIS[1001] = {0};

	std::cin >> N;

	for(int i=1 ; i<=N ; i++)
		std::cin >> A[i];

	LIS[1] = 1;
	for(int i=2 ; i<=N ; i++){
		int max_index = 0;
		for(int j=1 ; j<=i-1 ; j++){
			if(A[j] < A[i] && LIS[max_index] < LIS[j])
				max_index = j;
		}
		if(max_index)
			LIS[i] = LIS[max_index] + 1;
		else
			LIS[i] = 1;
	}

	int max = 0;
	for(int i=1 ; i<=N ; i++){
		max = std::max(max, LIS[i]);
	}
	std::cout << max << std::endl;
}
