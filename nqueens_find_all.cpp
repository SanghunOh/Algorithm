#include	<iostream>

bool promising(int N, int arr[], int level){
	for(int i=1 ; i<level ; i++){
		if(arr[level] == arr[i])
			return false;
		if((level-i == arr[level]-arr[i]) || (level-i == arr[i]-arr[level]))
			return false;
	}
	return true;
}

void printNQueens(int N, int arr[]){
	for(int i=1 ; i<=N ; i++){
		for(int j=1 ; j<=N ; j++){
			if(arr[i] == j)
				std::cout << "1 ";
			else
				std::cout << "0 ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool nqueens(int N, int arr[], int level){
	if(!promising(N, arr, level))
		return false;
	if(level == N){
		printNQueens(N, arr);
		return true;
	}
	
	for(int i=1 ; i<=N ; i++){
		arr[level+1] = i;
		
		if(nqueens(N, arr, level+1)){
			if(i != N)	
				continue;	// 마지막이 아니면 굳이 프린트할 필요없고 다음을 검사!
			return true;
		}
	}
	return false;
}

int main(){
	int N;

	std::cin >> N;

	int *arr = new int [N+1];
	nqueens(N, arr, 0);

	return 0;
}
