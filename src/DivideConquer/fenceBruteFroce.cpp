#include	<iostream>
#include	<vector>
using namespace std;

int main(){
	int T;

	cin >> T;

	while(T--){
		int N;
		vector<int> fence;

		cin >> N;

		for(int i=0 ; i<N ; i++){
			int tmp;
			cin >> tmp;

			fence.push_back(tmp);
		}

		int min_size = 0;
		for(int i=0 ; i<N ; i++){
			int size = 0;
			int piv = i;

			for(int j=piv-1 ; j>=0 ; j--){
				if(fence[piv] <= fence[j])
					size++;
				else
					break;
			}
			for(int j=piv ; j<N ; j++){
				if(fence[piv] <= fence[j])
					size++;
				else
					break;
			}

			size *= fence[piv];

			min_size = max(min_size, size);
		}

		cout << min_size << endl;
	}

	return 0;
}
