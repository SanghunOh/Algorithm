#include	<iostream>

int arr[10];
int visit[10] = {false, };

void findC(int N, int M, int count, int pre){
	if(count == M){
		for(int i=0 ; i<M ; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		return;
	}

	for(int i=0 ; i<N ; i++){
		if(visit[i])
			continue;
		arr[count] = i+1;

		if(pre < i+1){
			visit[i] = true;
			findC(N, M, count+1, i+1);
			visit[i] = false;
		}
	}
}

int main(){
	int N, M;

	std::cin >> N >> M;

	findC(N, M, 0, 0);
}
