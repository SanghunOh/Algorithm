#include	<iostream>

int n;

void heapify(int arr[], int h){
	int k;
	k = arr[2*h] > arr[2*h+1] ? 2*h : 2*h+1;

	if(arr[h] >= arr[k])
		return;

	int t = arr[h];
	arr[h] = arr[k];
	arr[k] = t;

	heapify(arr, k);
}

int main(){
	int* arr;

	std::cin >> n;

	arr = new int[n+1];

	for(int i=1 ; i<=n ; i++)
		std::cin >> arr[i];

	heapify(arr, 1);


	for(int i=1 ; i<=n ; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;


	return 0;
}
