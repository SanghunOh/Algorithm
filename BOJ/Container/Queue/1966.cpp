#include	<iostream>
#include	<algorithm>
#include	<vector>
#include	<queue>

/*
 *
 * 1966 프린터 큐
 *
*/

typedef std::pair<int, int> iPair;

int findOrder(int N, int M, std::deque<iPair>& dq){
	int count = 0;
	while(1){
		int max = 0;
		int size = dq.size();
		for(int j=0 ; j<size ; j++)
			if(dq[max].second < dq[j].second)
				max = j;


		if(dq.front().second == dq[max].second){
			count++;
			if(M == dq.front().first){
				break;
			}
			dq.pop_front();
		}
		else{
			iPair a = dq.front();
			dq.pop_front();
			dq.push_back(a);
		}
	}

	return count;
}

int main(){
	int T;
	int arr[101];

	std::cin >> T;

	for(int i=0 ; i<T ; i++){
		int N, M;
		std::deque<iPair> dq;

		std::cin >> N >> M;

		for(int j=0 ; j<N ; j++){
			int a;
			std::cin >> a;

			dq.push_back(std::make_pair(j, a));
		}

//		for(int j=0 ; j<dq.size() ; j++)
//			std::cout << dq[j] << " ";
//		std::cout << std::endl;

		std::cout << findOrder(N, M, dq) << std::endl;
	}
}
