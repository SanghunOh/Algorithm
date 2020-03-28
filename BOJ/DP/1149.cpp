#include	<iostream>

int main(){
	int N;
	int arr[1001][3];
	int DP[1001][3];
	int min;

	std::cin >> N;

	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<3 ; j++)
			std::cin >> arr[i][j];

	DP[0][0] = arr[0][0];
	DP[0][1] = arr[0][1];
	DP[0][2] = arr[0][2];

	for(int i=1 ; i<N ; i++){
		DP[i][0] = std::min(DP[i-1][1], DP[i-1][2]) + arr[i][0];
		DP[i][1] = std::min(DP[i-1][0], DP[i-1][2]) + arr[i][1];
		DP[i][2] = std::min(DP[i-1][0], DP[i-1][1]) + arr[i][2];
	}

	min = std::min(DP[N-1][0], std::min(DP[N-1][1], DP[N-1][2]));
	
	std::cout << min << std::endl;
}
