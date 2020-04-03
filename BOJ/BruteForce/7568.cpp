#include	<iostream>

int main(){
	int N;
	std::pair<int, int> arr[51];
	std::pair<int, int> brr[51];
	int rank[51];

	std::cin >> N;

	for(int i=0 ; i<N ; i++){
		std::cin >> arr[i].first >> arr[i].second;
		brr[i] = arr[i];
	}

	int r=1;
	for(int i=0 ; i<N ; i++){
		for(int j=i+1 ; j<N ; j++){
			if(arr[i].first < arr[j].first){
				std::pair<int, int> tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	rank[0] = r;
	for(int i=0 ; i<N-1 ; i++){
		if(arr[i].second > arr[i+1].second){
			rank[i+1] = i+2;
			r++;
		}
		else{
			rank[i] = r;
			rank[i+1] = r;
		}	
	}

	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			if(brr[i] == arr[j]){
				std::cout << rank[j] << std::endl;
			}
		}
	}
}
