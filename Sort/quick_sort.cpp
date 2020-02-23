#include	<iostream>

int pivot(int p, int r, int arr[]){
	int piv = r;
	int i = p-1;
	int j = p;

	for( ; j<r ; ){
		if(arr[piv] >= arr[j]){
			i++;
			int t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
			j++;
		}
		else
			j++;
	}
	i++;
	int t = arr[piv];
	arr[piv] = arr[i];
	arr[i] = t;

	return i;
}

void quick_sort(int p, int r, int arr[]){
	if(p>=r)
		return;

	int t = pivot(p, r, arr);
	quick_sort(p, t-1, arr);
	quick_sort(t+1, r, arr);
}


int main(){
	int N;
	int* arr;

	std::cin >>  N;
	arr = new int [N];

	for(int i=0 ; i<N ; i++)
		std::cin >> arr[i];

	quick_sort(0, N-1, arr);

	for(int i=0 ; i<N ; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return 0;
}
