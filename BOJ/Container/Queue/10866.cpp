#include	<iostream>
#include	<string>
#include	<deque>

int main(){
	int N;
	std::deque<int> dq;

	std::cin >> N;

	for(int i=0 ; i<N ; i++){
		std::string s;

		std::cin >> s;

		if(s == "push_front"){
			int data;
			std::cin >> data;
			dq.push_front(data);
		}
		else if(s == "push_back"){
			int data;
			std::cin >> data;
			dq.push_back(data);
		}
		else if(s == "pop_front"){
			if(dq.empty())
				std::cout << -1 << '\n';
			else{
				std::cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if(s == "pop_back"){
			if(dq.empty())
				std::cout << -1 << '\n';
			else{
				std::cout << dq.back() << '\n';
				dq.pop_back();
			}		
		}
		else if(s == "size")
			std::cout << dq.size() << '\n';
		else if(s == "empty"){
			if(dq.empty())
				std::cout << 1 << '\n';
			else
				std::cout << 0 << '\n';
		}
		else if(s == "front"){
			if(dq.empty())
				std::cout << -1 << '\n';
			else
				std::cout << dq.front() << '\n';
		}
		else if(s == "back"){
			if(dq.empty())
				std::cout << -1 << '\n';
			else
				std::cout << dq.back() << '\n';
		}
	}

	return 0;
}
