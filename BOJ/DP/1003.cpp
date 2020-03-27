#include	<iostream>

int zero;
int one;

int fibo(int n){
	if(n == 0){
		zero++;
		return 0;
	}
	else if(n == 1){
		one++;
		return 1;
	}
	return fibo(n-1) + fibo(n-2);
}

int main(){
	int T;

	std::cin >> T;
	for(int i=0 ; i<T ; i++){
		int n;
		zero = 0;
		one = 0;
		
		std::cin >> n;

		fibo(n);

		std::cout << zero << " " << one << std::endl;
	}

	return 0;
}
