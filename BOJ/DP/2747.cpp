#include	<iostream>

int arr[45];

int main(){
	int N;

	std::cin >> N;

	arr[1] = 1;

	for(int i=2 ; i<=N ; i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	
	std::cout << arr[N] << std::endl;
}
