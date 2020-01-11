#include	<iostream>
#include	<vector>

void printPicked(const std::vector<int>& picked){
	std::cout << "[ ";
	for(std::vector<int>::size_type i=0 ; i<picked.size() ; i++){
		std::cout << picked[i] << " ";
	}
	std::cout << "]" << std::endl;
}

void pick(int n, int toPick, std::vector<int>& picked){
	if(!toPick){
		printPicked(picked);
		return;
	}

	int smallest = picked.empty() ? 0 : picked.back() + 1;

	for(int next = smallest ; next < n ; next++){
		picked.push_back(next);
		pick(n, toPick-1, picked);
		picked.pop_back();
	}
}

int main(){
	int N, T;
	std::vector<int> pickn;

	std::cin >> N >> T;

	pick(N, T, pickn);

	return 0;
}
