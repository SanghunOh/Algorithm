#include	<iostream>

void bubble_sort(int arr[], int N){
	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N-1-i ; j++){
			if(arr[j] > arr[j+1]){
				int t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
		}
	}
}

int main(){
	int N;
	int* arr;

	std::cin >> N;

	arr = new int [N];

	for(int i=0 ; i<N ; i++)
		std::cin >> arr[i];

	bubble_sort(arr, N);

	for(int i=0 ; i<N ; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl << std::endl;
}
