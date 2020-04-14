#include	<iostream>
#include	<string>
#include	<stack>
#include	<deque>
/*
bool funcD(std::deque<int>& dq){
	if(dq.empty())
		return false;
	dq.pop_front();
	return true;
}

bool funcR(std::deque<int>& dq, int N){
	if(dq.empty())
		return false;

	std::stack<int> s;
	int size = dq.size();

	for(int i=0 ; i<size ; i++)
		s.push(dq[i]);
	dq.clear();

	for(int i=0 ; i<size ; i++){
		dq.push_back(s.top());
		s.pop();
	}
	return true;
}
*/
int main(){
	int T;
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;

	while(T--){
		std::string func;
		bool flag = false;
		bool rev = false;
		int N;
		std::string arr;
		std::deque<int> dq;
	
		std::cin >> func;
		std::cin >> N;
		std::cin >> arr;

		for(int i=0 ; i<N ; i++)
			dq.push_back(arr[2*i+1]-'0');

		for(int i=0 ; i<func.size() ; i++){
			if(func[i] == 'R'){
				rev = !rev;
			}
			else if(func[i] == 'D'){
				if(dq.empty()){
					flag = true;
					break;
				}
				if(rev)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}
		if(!N)
			std::cout << "[]" << '\n';
		else if(flag){
			std::cout << "error\n";
			continue;
		}
		else if(dq.size()){
			std::cout << "[";
			while(!dq.empty()){
				if(!rev){
					if(dq.size() == 1)
						std::cout << dq.front();
					else
						std::cout << dq.front() << ",";
					dq.pop_front();
				}
				else{
					if(dq.size() == 1)
						std::cout << dq.back();
					else
						std::cout << dq.back() << ",";
					dq.pop_back();
				}
			}
			std::cout << "]\n";
		}
	}

	return 0;
}
