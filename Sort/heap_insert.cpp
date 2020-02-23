#include	<iostream>

int n;

void insert_num(int arr[], int key){

	int parent;
	int cur = ++n;
	while(cur != 1){
		parent = cur/2;
		if(arr[parent] < key){
			arr[cur] = arr[parent];
			cur = parent;
		}
		else
			break;
	}
	arr[cur] = key;
}

int main(){
	int* arr;

	std::cin >> n;

	arr = new int[n+1];

	for(int i=1 ; i<=n ; i++)
		std::cin >> arr[i];


	insert_num(arr, 10);

	for(int i=1 ; i<=n ; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;


	return 0;
}
