#include	<iostream>
#include	<algorithm>
#include	<vector>

int main(){
	int N;
	std::vector<int> ATM;
	std::vector<int> time;

	std::cin >> N;

	for(int i=0 ; i<N ; i++){
		int k;
		std::cin >> k;

		ATM.push_back(k);
	}

	sort(ATM.begin(), ATM.end());

	int sum = 0;
	for(int i=0 ; i<N ; i++){
		sum += ATM[i];
		time.push_back(sum);
	}
	sum = 0;
	for(int i=0 ; i<N ; i++)
		sum += time[i];
	std::cout << sum << std::endl;
}
