#include	<iostream>

int main(){
	int N;
	int int_triangle[501][501];

	std::cin >> N;

	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=i ; j++)
			std::cin >> int_triangle[i][j];

	for(int i=2 ; i<=N ; i++){
		for(int j=0 ; j<=i ; j++){
			if(j == 1)
				int_triangle[i][j] += int_triangle[i-1][j];
			else if(j == N)
				int_triangle[i][j] += int_triangle[i-1][j-1];
			else
				int_triangle[i][j] += std::max(int_triangle[i-1][j], int_triangle[i-1][j-1]);
		}
	}

	int max = 0;

	for(int i=1 ; i<=N ; i++)
		max = std::max(max, int_triangle[N][i]);

	std::cout << max << std::endl;
}
