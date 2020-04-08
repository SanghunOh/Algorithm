#include	<iostream>
#include	<string>
#include	<stack>

int main(){
	int N;

	std::cin >> N;

	for(int i=0 ; i<N ; i++){
		std::string parenthesis;
		bool flag = false;
		std::stack<int> s;

		std::cin >> parenthesis;

		for(int j=0 ; j<parenthesis.length() ; j++){
			if(parenthesis[j] == '('){
				s.push(1);
			}
			else{
				if(s.empty()){
					flag = true;
					break;	
				}
				else
					s.pop();
			}
		}
		if(s.empty() && !flag)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

	return 0;
}
