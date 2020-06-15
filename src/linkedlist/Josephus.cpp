#include	<iostream>
#include	<list>
using namespace std;

void josephus(int N, int K, list<int> circle){
	circle.pop_front();
	N--;

	for(int i=0 ; i<N-2 ; i++){
		list<int> tmp;

		for(int j=0 ; j<K-1 ; j++){
			tmp.push_back(circle.front());
			circle.pop_front();
		}
		circle.pop_front();
		for(int j=0 ; j<K-1 ; j++){
			circle.push_back(tmp.front());
			tmp.pop_front();
		}
	}

	list<int>::iterator it;
	for(it=circle.begin() ; it!= circle.end() ; it++)
		cout << *it << " ";
	cout << endl;

	return;
}

int main(){
	int T;
	int N, K;

	cin >> T;

	while(T--){
		cin >> N >> K;

		list<int> circle;
		for(int i=1 ; i<=N ; i++)
			circle.push_back(i);

		josephus(N, K, circle);
	}

	return 0;
}
