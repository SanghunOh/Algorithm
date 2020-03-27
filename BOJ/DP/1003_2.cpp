#include	<iostream>

int arr[2][41];

int main(){
	arr[0][0] = 1;
	arr[1][1] = 1;

	int T;

	std::cin >> T;

	for(int i=0 ; i<T ; i++){
		int n;
		std::cin >> n;

		for(int i=2 ; i<=40 ; i++){
			arr[0][i] = arr[0][i-1] + arr[0][i-2];
			arr[1][i] = arr[1][i-1] + arr[1][i-2];
		}

		std::cout << arr[0][n] << " " << arr[1][n] << std::endl;
	}
	return 0;
}
