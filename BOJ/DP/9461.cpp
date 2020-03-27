#include	<iostream>

long arr[100];

int main(){
	int T;

	std::cin >> T;

	while(T--){
		long N;
	
		std::cin >> N;
	
		arr[0] = 1;
		arr[1] = 1;
		arr[2] = 1;
	
		for(int i=3 ; i<=N ; i++)
			arr[i] = arr[i-2] + arr[i-3];
		std::cout << arr[N-1] << std::endl;
	}
}
