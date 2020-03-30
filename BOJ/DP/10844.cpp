#include	<iostream>

//45656이란 수를 보자.
//이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.
//세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.
//N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)
//
int main(){
	int N;
	long long stairNumber[101][10];
//입력 N에 대하여 각 자리수 대해 분할한다.
//0~9까지 숫자에 대해 분할한다.
	std::cin >> N;

	for(int i=0 ; i<10 ; i++){
		stairNumber[1][i] = 1;
	}
	stairNumber[1][0] = 0;

	for(int i=2 ; i<=N ; i++){
		for(int j=0 ; j<10 ; j++){
			if(j == 0)
				stairNumber[i][0] = stairNumber[i-1][1];
			else if(j == 9)
				stairNumber[i][9] = stairNumber[i-1][8];
			else
				stairNumber[i][j] = stairNumber[i-1][j-1] + stairNumber[i-1][j+1];
			stairNumber[i][j] %=1000000000;
		}
	}

	long long sum = 0;
	for(int i=0 ; i<10 ; i++)
		sum += stairNumber[N][i];
	std::cout << sum % 1000000000  << std::endl;
}
