#include	<iostream>

int main(){
	int N;
	int M;
	int arr[101];

	std::cin >> N >> M;

	for(int i=0 ; i<N ; i++)
		std::cin >> arr[i];

	int max = -1;
	for(int i=0 ; i<N-2 ; i++){
		for(int j=i+1 ; j<N-1 ; j++){
			for(int k=j+1 ; k<N ; k++){
				int tmp = arr[i] + arr[j] + arr[k];
				if(tmp > max && tmp <= M)
					max = tmp;
			}
		}
	}
	std::cout << max << std::endl;
}
