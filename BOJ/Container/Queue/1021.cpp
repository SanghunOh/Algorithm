#include	<iostream>
#include	<deque>

void firstOperation(std::deque<int>& q){
	q.pop_front();
}

void secondOperation(std::deque<int>& q){
	int a = q.front();
	q.pop_front();
	q.push_back(a);
}

void thirdOperation(std::deque<int>& q){
	int a = q.back();
	q.pop_back();
	q.push_front(a);
}

int main(){
	int N, M;
	int count = 0;
	int order[51];
	std::deque<int> q;

	std::cin.tie(0);
	std::cin.sync_with_stdio(false);

	std::cin >> N >> M;
	for(int i=0 ; i<M ; i++)
		std::cin >> order[i];

	for(int i=0 ; i<N ; i++)
		q.push_back(i+1);

	int i=0;
	while(i<M){
		int idx;
		for(int j=0 ; j<q.size() ; j++){
			if(order[i] == q[j]){
				idx = j;
				break;
			}
		}
		if(idx == 0){
			firstOperation(q);
			i++;
		}
		else if(idx <= q.size()/2){
			secondOperation(q);
			count++;
		}
		else{
			thirdOperation(q);
			count++;
		}
	}

	std::cout << count << '\n';

	return 0;
}
