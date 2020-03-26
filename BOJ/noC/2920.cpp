#include	<iostream>

int main(){
	int arr[8];

	for(int i=0 ; i<8 ; i++){
		std::cin >> arr[i];
	}

	if(arr[0] == 1){
		for(int i=0 ; i<8 ; i++){
			if(arr[i] != i+1){
				std::cout << "mixed" << std::endl;
				return 0;
			}
		}
		std::cout << "ascending" << std::endl;
	}
	else if(arr[0] == 8){
		for(int i=0 ; i<8 ; i++){
			if(arr[i] != 8-i){
				std::cout << "mixed" << std::endl;
				return 0;
			}
		}
		std::cout << "descending" << std::endl;
	}
	else
		std::cout << "mixed" << std::endl;

	return 0;

}
