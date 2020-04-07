#include	<iostream>
#include	<queue>

typedef std::pair<int, int> iPair;

struct cmp{
	bool operator()(iPair& a, iPair& b){
		return a.second >= b.second;
	}
};

int main(){
	int N;
	int time[100000][2];
	int count = 0;
	std::priority_queue<iPair, std::vector<iPair>, cmp> pq;

	std::cin >> N;

	for(int i=0 ; i<N ; i++){
		int a, b;
		std::cin >> a >> b;
		pq.push(std::make_pair(a, b));
	}

	int finish_time = pq.top().second;
	pq.pop();
	count++;
	while(!pq.empty()){
		iPair tmp = pq.top();

		if(tmp.first >= finish_time){
			count++;
			finish_time = pq.top().second;
		}
		pq.pop();	
	}

	std::cout << count << std::endl;
}
