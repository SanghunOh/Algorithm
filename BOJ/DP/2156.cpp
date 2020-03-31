#include	<iostream>

int main(){
	int N;
	int grape[10001] = {0};
	int sum[10001] = {0};

	std::cin >> N;

	for(int i=1 ; i<=N ; i++)
		std::cin >> grape[i];
	
	sum[1] = grape[1];
	sum[2] = grape[1] + grape[2];

	for(int i=3 ; i<=N ; i++){
		int a = sum[i-1];				//i번째 잔을 선택하지 않는 경우의 수
		int b = sum[i-3] + grape[i-1] + grape[i];	//i-3, i-1, i번째 잔을 선택
		int c = sum[i-2] + grape[i];			//i-2, i번째 잔을 선택
		

		sum[i] = std::max(a, std::max(b, c));
	}

	std::cout << sum[N] << std::endl;
}
