#include	<iostream>

/*
 *
 * INSERTION_SORT
 *
*/
 int main(){
	int N;
	int arr[1001];

	std::cin >> N;

	for(int i=0 ; i<N ; i++)
		std::cin >> arr[i];

	for(int i=1 ; i<N ; i++){
		int a = arr[i];
		int j=i-1;
		for( ; j>=0 ; j--){
			if(a < arr[j])
				arr[j+1] = arr[j];
			else
				break;
		}
		arr[j+1] = a;
	}

	for(int i=0 ; i<N ; i++)
		std::cout << arr[i] << std::endl;
}
