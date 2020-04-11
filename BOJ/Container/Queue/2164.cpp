#include	<iostream>
#include	<queue>

int main(){
	int N;
	std::queue<int> q;

	std::cin >> N;

	for(int i=1 ; i<=N ; i++)
		q.push(i);

	while(q.size() != 1){
		q.pop();

		if(q.size() == 1)
			break;

		int a = q.front();
		q.pop();
		q.push(a);
	}

	std::cout << q.front() << std::endl;

	return 0;
}
