#include	<iostream>
#include	<vector>
#include	<algorithm>

int main(){
	std::vector<int> a;
	int N;

	std::cin >> N;

	for(int i=0 ; i<N ; i++){
		int tmp;
		std::cin >> tmp;
		a.push_back(tmp);
	}

	sort(a.begin(), a.end());

	std::cout << a[0]*a[a.size()-1] << std::endl;
}
