#include	<iostream>

int findMinCoin(int coin[], int N, int K){
	int i=N-1;
	int count=0;
	while(K){
		if(K >= coin[i]){
			K-= coin[i];
			count++;
		}
		else
			i--;
	}

	return count;
}

int main(){
	int N, K;
	int coin[11];

	std::cin >> N >> K;

	for(int i=0 ; i<N ; i++)
		std::cin >> coin[i];

	std::cout << findMinCoin(coin, N, K) << std::endl;
}
