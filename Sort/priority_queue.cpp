#include	<iostream>

void insert(int arr[], int& N, int x){
	int pos = ++N;
	int par;
	arr[pos] = x;

	par = pos/2;

	while(pos != 1 && arr[par] < x){
		arr[pos] = arr[par];
		pos = par;
		par = pos/2;
	}
	arr[pos] = x;
}

void dequeue(int arr[], int& N){
	int pos = 1;
	int child = 2;
	int x = arr[N];

	arr[1] = arr[N--];


	while(pos <= N){
		child = arr[child] >= arr[child+1] ? child : child+1;
		if(x <= arr[child]){
			arr[pos] = arr[child];
			pos = child;
			child = pos*2;
		}
		else
			break;
	}
	arr[pos] = x;
}

int main(){
	int N;
	int* arr;

	std::cin >> N;

	arr = new int[N+1];

	for(int i=1 ; i<=N ; i++){
		std::cin >> arr[i];
	}
	insert(arr, N, 15);

	for(int i=1 ; i<=N ; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;	

	dequeue(arr, N);

	for(int i=1 ; i<=N ; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;	

	return 0;
}
