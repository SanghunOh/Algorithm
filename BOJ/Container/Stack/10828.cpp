#include	<iostream>
#include	<stack>
#include	<string>

int main(){
	int N;
	std::stack<int> s;

	std::cin >> N;

	for(int i=0 ; i<N ; i++){
		std::string str;

		std::cin >> str;

		if(str == "push"){
			int d;

			std::cin >> d;

			s.push(d);
		}
		else if(str == "top"){
			if(s.empty())
				std::cout << -1 << std::endl;
			else
				std::cout << s.top() << std::endl;
		}
		else if(str == "empty"){
			if(s.empty())
				std::cout << 1 << std::endl;
			else
				std::cout << 0 << std::endl;
		}
		else if(str == "pop"){
			if(s.empty())
				std::cout << -1 << std::endl;
			else{
				std::cout << s.top() << std::endl;
				s.pop();
			}
		}
		else if(str == "size")
			std::cout << s.size() << std::endl;

	}
}
