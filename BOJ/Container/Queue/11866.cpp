#include	<iostream>
#include	<algorithm>
#include	<vector>
#include	<deque>

int main(){
	int N, K;
	bool check[1001] = {false};
	std::vector<int> result;
	std::deque<int> q;
	std::deque<int>::iterator it;

	std::cin >> N >> K;

	for(int i=0 ; i<N ; i++)
		q.push_back(i+1);

	it = q.begin();

	int idx=0;
	int count = N;
	while(result.size() != N){
		std::cout << idx << std::endl;
		for(int i=0 ; i<K-1 ; i++, idx++){
			if(idx >= N)
				idx -= N;
			if(check[idx]){
				i--;
			}
		}
		std::cout << "after for : " << idx << std::endl;


		check[idx] = true;
		result.push_back(q[idx]);
		while(1){
			if(check[idx])
				idx++;
			else{
				break;
			}
		}
	}

	std::cout << "<";
	for(int i=0 ; i<N-1 ; i++)
		std::cout << result[i] << ", ";
	std::cout << result[N-1];
	std::cout << ">" << '\n';
	
}
