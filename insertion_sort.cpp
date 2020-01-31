#include	<iostream>

void insertion_sort(int arr[], int N){
	for(int i=1 ; i<N ; i++){
		int item = arr[i];
		int j=i-1;
		while(arr[j] > item && j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = item;
	}	
}

int main(){
	int N;
	int* arr;
	

	std::cin >> N;
	arr = new int [N];

	for(int i=0 ; i<N ; i++)
		std::cin >> arr[i];

	insertion_sort(arr, N);

	for(int i=0 ; i<N ; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl << std::endl;
}
