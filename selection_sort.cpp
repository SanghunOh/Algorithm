#include	<iostream>

void selection_sort(int arr[], int N){
	for(int i=0 ; i<N ; i++){
		int idx = i;
		for(int j=i+1 ; j<N ; j++){
			if(arr[idx] > arr[j]){
				idx = j;
			}
		}
		int t = arr[i];
		arr[i] = arr[idx];
		arr[idx] = t;
	}
}

int main(){
	int N;
	int* arr;
	

	std::cin >> N;
	arr = new int [N];

	for(int i=0 ; i<N ; i++)
		std::cin >> arr[i];

	selection_sort(arr, N);

	for(int i=0 ; i<N ; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl << std::endl;
}
