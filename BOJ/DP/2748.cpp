#include	<iostream>

long arr[100] = {0,};

long fibo(int N){
	if(N == 0)
		return arr[0];
	if(N == 1)
		return arr[1];
	else if(arr[N-1] > 0){
		return arr[N-1];
	}
	else{
		arr[N-1] = fibo(N-1) + fibo(N-2);
		return arr[N-1];
	}
}

int main(){
	int N;

	std::cin >> N;

	arr[1] = 1;

	std::cout << fibo(N) << std::endl;
}
