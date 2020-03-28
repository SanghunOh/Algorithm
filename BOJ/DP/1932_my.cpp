#include	<iostream>

int main(){
	int N;
	int arr[501][500] = {0};
	long L[501][500] = {0};

	std::cin >> N;

	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<=i ; j++)
			std::cin >> arr[i][j];

	for(int i=0 ;  i<=N ; i++){
		for(int j=0 ; j<=i ; j++){
			if(i == 0 && j == 0)
				L[i][j] = arr[i][j];
			else if(i == j){
				L[i][j] = L[i-1][j-1] + arr[i][j];
			}
			else if(j == 0){
				L[i][j] = L[i-1][j] + arr[i][j];
			}
			else{
				if(L[i-1][j-1] > L[i-1][j]){
					L[i][j] = L[i-1][j-1] + arr[i][j];
				}
				else{
					L[i][j] = L[i-1][j] + arr[i][j];
				}
			}
		}
	}
	int m_index = 0;
	for(int i=1 ; i<N ; i++){
		if(L[N][i] > L[N][m_index])
			m_index = i;
	}
	std::cout << L[N][m_index] << std::endl;
}
