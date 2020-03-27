#include	<iostream>

int arr[1000000] = {0, };


int main(){
	int N;

	std::cin >> N;
	arr[0] = 1;
	arr[1] = 1;

	for(int i=2 ; i<=N ; i++){
		arr[i] = (arr[i-1] + arr[i-2]) % 15746;
	}

	std::cout << arr[N] << std::endl;
}
