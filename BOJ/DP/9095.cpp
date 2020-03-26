#include	<iostream>

int add[1000];

int add123(int n){
	if(n == 1 || n == 2 || n == 3 || !n)
		return add[n];
	if(!add[n]){
		add[n] += add123(n-1);
		add[n] += add123(n-2);
		add[n] += add123(n-3);
	}
	return add[n];

/*
 * 1
 *
 * 2
 * 1 1
 *
 * 3
 * 1 2
 * 1 1 1
 * 2 1
 *
 * 4
 * 1 3
 * 2 2
*/
	 
}

int main(){
	int T;

	std::cin >> T;

	add[0] = 0;
	add[1] = 1;
	add[2] = 2;
	add[3] = 4;

	for(int i=0 ; i<T ; i++){
		int n;

		std::cin >> n;

		std::cout << add123(n) << std::endl;
	}
	
	return 0;
}


