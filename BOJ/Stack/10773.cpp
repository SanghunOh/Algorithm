#include	<iostream>
#include	<stack>

int main(){
	int N;
	std::stack<int> s;

	std::cin >> N;

	for(int i=0 ; i<N ; i++){
		int a;
		std::cin >> a;

		if(a != 0)
			s.push(a);
		else
			s.pop();
	}

	int sum = 0;
	int size = s.size();
	for(int i=0 ; i<size ; i++){
		sum += s.top();
		s.pop();
	}

	std::cout << sum << std::endl;

	return 0;
}
