#include	<iostream>
#include	<algorithm>
#include	<vector>

void print(std::vector<int>& T){
	std::cout << "[ ";
	for(std::vector<int>::size_type i=0 ; i<T.size() ; i++){
		std::cout << T[i] << " ";
	}
	std::cout << "]" << std::endl;
}

void find_set(std::vector<int> set, int N, int T, int num, int set_num){
	if(set_num == N+1)
		return;

	if(num == T){
		print(set);
		set.pop_back();
		return;
	}

	find_set(set, N, T, num, set_num+1);
	set.push_back(set_num);
	find_set(set, N, T, num+1, set_num+1);
}


int main(){
	int N;
	int T;
	std::vector<int> set;

	std::cin >> N >> T;

	find_set(set, N, T, 0, 0);

	return 0;
}
