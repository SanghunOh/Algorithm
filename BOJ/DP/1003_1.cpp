#include	<iostream>

int arr[45]{1, 1,};

int fibo(int n){
	if(n <= 2)
		return arr[n-1];
	else if(arr[n-1] > 0)
		return arr[n-1];
	else{
		arr[n-1] = fibo(n-1)+fibo(n-2);
		return arr[n-1];
	}
}

int main(){
	int T;

	std::cin >> T;

	for(int i=0 ; i<T ; i++){
		int n;
		std::cin >> n;

		if(n == 0)
			std::cout << "1 0" << std::endl;
		else if(n == 1)
			std::cout << "0 1" << std::endl;
		else{
			fibo(n);
			std::cout << arr[n-2] << " " << arr[n-1] << std::endl;
		}
	}
	return 0;
}
