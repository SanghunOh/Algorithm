#include	<iostream>
#include	<cmath>

void get_radix(int* A, int* radix, int N, int k){
	int mod = (int)pow(10, k+1);
	int div = (int)pow(10, k);
	for(int i=0 ; i<N ; i++){
		radix[i] = A[i]%mod;
		radix[i] = radix[i]/div;
	}
}

void counting_sort(int* A, int* B, int* radix, int N, int k){
	int* C = new int[10];
	
	for(int i=0 ; i<10 ; i++)
		C[i] = 0;
	for(int i=0 ; i<N ; i++)
		C[radix[i]]++;
	for(int i=1 ; i<10 ; i++)
		C[i] += C[i-1];
	for(int i=N-1 ; i>=0 ; i--){
		B[C[radix[i]]-1] = A[i];
		C[radix[i]]--;
	}
}

void radix_sort(int* A, int* B, int N, int d){
	int* radix;
	radix = new int[N];
	for(int i=0 ; i<N ; i++)
		B[i] = A[i];

	for(int i=0 ; i<d ; i++){
		get_radix(B, radix, N, i);

		for(int i=0 ; i<N ; i++)
			A[i] = B[i];

		counting_sort(A, B, radix, N, i);
	}
}

int main(){
	int N;
	int d;
	int* A;
	int* B;

	std::cin >> N;
	std::cin >> d;

	A = new int[N];
	B = new int[N];

	for(int i=0 ; i<N ; i++)
		std::cin >> A[i];

	radix_sort(A, B, N, d);

	for(int i=0 ; i<N ; i++)
		std::cout << B[i] << " ";
	std::cout << std::endl;

	return 0;
}
