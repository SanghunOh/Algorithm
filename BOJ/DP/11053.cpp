#include	<iostream>

/*
 *
 * 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
 * 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50}인 경우에 가장 긴 증가하는 부분 수열은 {10, 20, 30, 50}이다.
 * 길이는 4이다.
 * 
*/

int main(){
	int N;
	int A[1001];
	int LIS[1001][1001] = {0};

	std::cin >> N;

	for(int i=1 ; i<=N ; i++)
		std::cin >> A[i];

	LIS[1][1] = 1;

	for(int i=2 ; i<=N ; i++){
		int max = 0;
		for(int j=1 ; j<=i-1 ; j++){
			if(A[i] > A[j]){
				LIS[i][j] = LIS[j][j];
			}
			if(max < LIS[i][j])
				max = LIS[i][j];
		}
		LIS[i][i] = max+1;
	}

/*
 * 현재 고려하는 수 : i
 * LIS[i][j]에는 j : 1~i-1까지 숫자 중에 A[i] > A[j]에 해당하는 수 j에 대해 LIS[i][j] = LIS[j][j]를 수행한다.
 * LIS[i][i]에는 i번째 숫자까지의 가장 긴 증가하는 부분 수열의 길이가 저장된다.
*/

	int max = 0;
	for(int i=1 ; i<=N ; i++){
		if(max < LIS[i][i])
			max = LIS[i][i];
	}
	std::cout << max << std::endl;

	return 0;
}
