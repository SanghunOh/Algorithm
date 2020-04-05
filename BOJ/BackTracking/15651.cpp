#include	<iostream>

/*
 * N과 M
 * 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
 * - 1부터 N까지 자연수 중에서 M개를 고른 수열
 * - 같은 수 를 여러번 골라도 된다.
 *  --> 중복 순열
 * 
*/

int arr[10];

void findC(int N, int M, int count){
	if(count == M){
		for(int i=0 ; i<M ; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
		
		return;
	}

	for(int i=0 ; i<N ; i++){
		arr[count] = i+1;
		findC(N, M, count+1);
	}
}

int main(){
	int N, M;

	std::cin >> N >> M;
	
	findC(N, M, 0);
}
