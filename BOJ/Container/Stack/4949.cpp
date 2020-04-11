#include	<iostream>
#include	<string>
#include	<stack>

int main(){
	
	while(1){
		std::string str;
		std::stack<char> s;
		bool flag = false;

		std::getline(std::cin, str);

		if(str.length() == 1 && str[0] == '.'){
			break;
		}
		if(str.length() == 1 && str[0] == '\n')
			break;

		for(int j=0 ; j<str.length() ; j++){
			if(str[j] == '(' || str[j] == '['){
				s.push(str[j]);
			}
			else if(str[j] == ')' || str[j] == ']'){
				if(!s.empty()){
					if(s.top() == '[' && str[j] != ']'){
						std::cout << "no" << std::endl;
						flag = true;
						break;
					}
					else if(s.top() == '(' && str[j] != ')'){
						std::cout << "no" << std::endl;
						flag = true;
						break;
					}
					else
						s.pop();
				}
				else{
					std::cout << "no" << std::endl;
					flag = true;
					break;
				}
			}
		}
		
		if(!flag && s.empty()){
			std::cout << "yes" << std::endl;
		}
		else if(!s.empty() && flag == false)
			std::cout << "no" << std::endl;
	}

	return 0;
}
