#include	<iostream>

/*
 * 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
 *  - 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
 *  - 고른 수열은 오름차순이어야 한다.
 *  -> nCm
 *
*/
bool check[10];

void findArray(int arr[], int N, int M, int count, int idx){
	if(count == M && idx <= N){
		for(int i=0 ; i<N ; i++){
			if(check[i])
				std::cout << arr[i] << " ";
		}
		std::cout << std::endl;

		return;
	}
	else if(idx > N)
		return;
	check[idx] = true;			// idx 번째 원소를 선택
	findArray(arr, N, M, count+1, idx+1);
	check[idx] = false;			// idx 번재 원소를 선택하지 않음
	findArray(arr, N, M, count, idx+1);
}

int main(){
	int N;
	int M;
	int arr[10];

	std::cin >> N >> M;

	for(int i=0 ; i<N ; i++)
		arr[i] = i+1;

	findArray(arr, N, M, 0, 0);
}
