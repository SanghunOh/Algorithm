#include	<iostream>

void heapify(int arr[], int h, int N){
	int k;
	
	k = h*2;
	if(k > N)
		return;
	if(k == N){
		int t = arr[k];
		arr[k] = arr[h];
		arr[h] = t;
	
		heapify(arr, k, N);
		return;
	}

	k = arr[k] > arr[k+1] ? k : k+1;

	if(arr[h] >= arr[k])
		return;

	int t = arr[k];
	arr[k] = arr[h];
	arr[h] = t;

	heapify(arr, k, N);
}

void build_heap(int arr[], int N){
	for(int i=N/2 ; i>=1 ; i--)
		heapify(arr, i, N);
}

void heap_sort(int arr[], int& N){
	build_heap(arr, N);
	for(int i=N ; i>=2 ; i--){
		int t = arr[i];
		arr[i] = arr[1];
		arr[1] = t;

		N--;
		heapify(arr, 1, N);
	}
}


int main(){
	int *arr;
	int N;
	int N_;

	std::cin >> N;
	arr = new int[N+1];

	for(int i=1 ; i<=N ; i++)
		std::cin >> arr[i];

	N_ = N;
	heap_sort(arr, N);

	for(int i=1 ; i<=N_ ; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return 0;
}
