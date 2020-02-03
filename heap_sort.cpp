#include	<iostream>

int N;

void heapify(int arr[], int h){
	int k;
	
	k = arr[2*h] > arr[2*h+1] ? 2*h : 2*h+1;

	if(arr[h] >= arr[k])
		return;

	int t = arr[k];
	arr[k] = arr[h];
	arr[h] = t;

	heapify(arr, k);
}

void heap_sort(int arr[]){
	for(int i=N ; i>=2 ; i++){
		int t = arr[i];
		arr[i] = arr[1];
		arr[1] = t;

		N--;
		heapify(arr, 1);
	}
}

void build_heap(int arr[]){
	for(int i=N/2 ; i>=1 ; i++)
		heapify(arr, i);
}

int main(){
	int *arr;

	std::cin >> N;
	arr = new int[N+1];

	for(int i=1 ; i<=N ; i++)
		std::cin >> arr[i];

	heap_sort(arr);

	for(int i=1 ; i<=N ; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return 0;
}
