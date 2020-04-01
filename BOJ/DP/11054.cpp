#include	<iostream>

/*
 * 가장 긴 바이토닉 수열
 * ex) 
 * 10 20 30 25 20
 * 10 20 30 40
 * 50 40 25 10
 *
 * 가장 긴 바이토닉 부분 수열
 * 1 5 2 1 4 3 4 5 2 1 -> 1 2 3 4 5 2 1
 *
 * 바이토닉 수열에서 가장 큰 숫자 bit[j]에 대하여 j 앞쪽으로는 증가하는 수열,
 * j뒤쪽으로는 감소하는 수열이므로 j앞쪽으로는 LIS문제, 뒤쪽으로는 LIS반대 부호 문제이다.
 *
 * 그런데 이를 각각 j에 대해서 매번 앞뒤의 LIS문제를 해결하기에는 시간이 많이 소요됨
 * -> 미리 계산해놓는다.
 *
*/
int main(){
	int N;
	int bit[1001];
	int LIS[1001] = {0};
	int LDS[1001] = {0};

	std::cin >> N;

	for(int i=1 ; i<=N ; i++)
		std::cin >> bit[i];

	for(int i=1 ; i<=N ; i++){
		LIS[i] = 1;
		for(int j=1 ; j<=i ; j++){
			if(bit[j] < bit[i] && LIS[j] +1 > LIS[i])
				LIS[i] = LIS[j] + 1;
		}
	}

	for(int i=N ; i>0 ; i--){
		LDS[i] = 1;
		for(int j=N ; j>=i ; j--){
			if(bit[j] < bit[i] && LDS[j] + 1 > LDS[i])
				LDS[i] = LDS[j] + 1;
		}
	}
	int max = -1;
	for(int i=1 ; i<=N ; i++){
		int a = LIS[i] + LDS[i];
		max = std::max(max, a);
	}
	std::cout << max-1 << std::endl;;
}
