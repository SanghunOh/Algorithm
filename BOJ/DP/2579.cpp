#include	<iostream>

int main(){
	int N;
	int stair[301];
	int score[301] = {0};

	std::cin >> N;

	for(int i=0 ; i<N ; i++)
		std::cin >> stair[i];

	score[0] = stair[0];
	score[1] = stair[0] + stair[1];

	score[2] = stair[0] + stair[2] > stair[1] + stair[2] ? stair[0] + stair[2] : stair[1] + stair[2];

	for(int i=3 ; i<N ; i++){
		int a = score[i-2] + stair[i];
		int b = score[i-3] + stair[i-1] + stair[i];

// i번째 계단까지 올라가는 경우는 2가지 경우
// 1. i-2번째 계단까지 올라온 후 i번째 계단을 선택하는 경우(i-3번째 계단까지 올라온 경우로 생각할 필요가 없다.)
// 2. i-3번째 계단까지 올라온 후 i-1번째 계단 선택, i번째 계단 선택
		score[i] = a > b ? a : b;
	}

	std::cout << score[N-1] << std::endl;
}
