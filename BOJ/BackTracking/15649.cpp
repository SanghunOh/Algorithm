#include	<iostream>
#include	<stack>

int visit[10] = {false, };

void findC(int arr[], int N, int M, int idx){
	if(idx == M){
		for(int i=0 ; i<M ; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		return;
	}

	for(int i=0 ; i<N ; i++){
		if(visit[i])
			continue;
		visit[i] = true;
		arr[idx] = i+1;
		findC(arr, N, M, idx+1);
		visit[i] = false;
	}
}

int main(){
	int N, M;
	int arr[10];
	
	std::cin >> N >> M;

	for(int i=0 ; i<N ; i++)
		arr[i] = i+1;

	findC(arr, N, M, 0);
}
