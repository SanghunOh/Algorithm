#include	<iostream>

int main(){
	int N;
	int div = 2;

	std::cin >> N;
	while(N != 1){
		if(N%div == 0){
			std::cout << div << std::endl;
			N = (int)N/div;
		}
		else
			div++;
	}

	return 0;
}
