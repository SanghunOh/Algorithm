#include	<iostream>
#include	<climits>

int main(){
	int N;
	int constructor = INT_MAX;

	std::cin >> N;

	for(int i=1 ; i<N ; i++){
		int tmp = i;
		int num = i;
		int div = 10;

		while(num != 0){
			tmp += num%10;
			num /= 10;
		}

		if(constructor > tmp && tmp == N)
			constructor = i;
	}

	if(constructor == INT_MAX)
		std::cout << 0 << std::endl;
	else
		std::cout << constructor << std::endl;
}
