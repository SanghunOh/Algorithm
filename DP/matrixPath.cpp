#include	<iostream>

void findPath(int P[][10], int N, int y, int x){
	if(!y && !x){
		std::cout << y << " " << x << std::endl;
		return;
	}
	if(P[y][x] == -1){
		findPath(P, N, y-1, x);
	}
	else if(P[y][x] == 1){
		findPath(P, N, y, x-1);
	}
	std::cout << y << " " << x << std::endl;
}

int main(){
	int N;
	int arr[10][10] = {0};
	int L[10][10] = {0};
	int P[10][10] = {0};

	std::cin >> N;

	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			std::cin >> arr[i][j];

	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			if(i == 0 && j == 0){
				L[i][j] = arr[i][j];
				P[i][j] = 0;
			}
			else if(i == 0){
				L[i][j] = arr[i][j] + L[i][j-1];
				P[i][j] = 1;
			}
			else if(j == 0){
				L[i][j] = arr[i][j] + L[i-1][j];
				P[i][j] = -1;
			}
			else{
				if(L[i-1][j] > L[i][j-1]){
					L[i][j] = arr[i][j] + L[i][j-1];
					P[i][j] = 1;
				}
				else{
					L[i][j] = arr[i][j] + L[i-1][j];
					P[i][j] = -1;
				}
				
			}
		}
	}

	std::cout << L[N-1][N-1] << std::endl;

	findPath(P, N, N-1, N-1);
}
