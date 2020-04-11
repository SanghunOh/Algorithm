#include	<iostream>
#include	<string>
#include	<queue>

int main(){
	int N;
	std::queue<int> q;

	std::cin.tie(0);
	cin.sync_with_stdio(false);

	std::cin >> N;

	for(int i=0 ; i<N ; i++){
		std::string s;

		std::cin >> s;

		if(s == "push"){
			int d;

			std::cin >> d;

			q.push(d);
		}
		else if(s == "pop"){
			if(q.empty())
				std::cout << -1 << '\n';
			else{
				std::cout << q.front() << '\n';
				q.pop();
			}
		}
		else if(s == "size")
			std::cout << q.size() << '\n';
		else if(s == "empty"){
			if(q.empty())
				std::cout << 1 << '\n';
			else
				std::cout << 0 << '\n';
		}
		else if(s == "front"){
			if(q.empty())
				std::cout << -1 << '\n';
			else
				std::cout << q.front() << '\n';
		}
		else if(s == "back"){
			if(q.empty())
				std::cout << -1 << '\n';
			else
				std::cout << q.back() << '\n';
		}
	}
}
