#include	<iostream>

/*
 * Bubble Sort 
 */
int main(){
	int N;
	int arr[1001];

	std::cin >> N;

	for(int i=0 ; i<N ; i++){
		std::cin >> arr[i];
	}

	for(int i=0 ; i<N ; i++){
		for(int j=i+1 ; j<N ; j++){
			if(arr[i] > arr[j]){
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}

	for(int i=0 ; i<N ; i++)
		std::cout << arr[i] << std::endl;
}
