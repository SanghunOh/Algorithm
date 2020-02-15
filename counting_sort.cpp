#include	<iostream>

int* counting_sort(int*&arr, int N, int k){
	int* C;
	int* B;

	B = new int[N];
	C = new int[k];
	for(int i=0 ; i<k ; i++)
		C[i] = 0;

	for(int i=0 ; i<N ; i++)
		C[arr[i]]++;
	for(int i=1 ; i<=k ; i++){
		C[i] += C[i-1];
	}

	for(int i=N ; i>=0 ; i--){
		B[C[arr[i]]] = arr[i];
		C[arr[i]]--;
	}
	
	return B;
}

int main(){
	int* arr;
	int N;
	int k;

	std::cin >> N;
	std::cin >> k;

	arr = new int[N];
	for(int i=0 ; i<N ; i++)
		std::cin >> arr[i];

	int* B = counting_sort(arr, N, k);

	for(int i=0 ; i<N ; i++)
		std::cout << B[i] << " ";

	std::cout << std::endl;
}
