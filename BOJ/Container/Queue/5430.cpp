#include	<iostream>
#include	<string>
#include	<stack>
#include	<deque>

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
/*
	for(int i=0 ; i<size ; i++)
		s.push(dq[i]);
	dq.clear();

	for(int i=0 ; i<size ; i++){
		dq.push_back(s.top());
		s.pop();
	}
*/

	for(int i=0 ; i<size/2 ; i++){
		int t = dq[i];
		dq[i] = dq[N-1-i];
		dq[N-1-t] = t;
	}
	return true;
}

int main(){
	int T;

	std::cin >> T;

	while(T--){
		std::string func;
		bool flag = false;
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
				if(!funcR(dq, N)){
					flag = true;
					break;
				}
			}
			else if(func[i] == 'D'){
				if(!funcD(dq)){
					flag = true;
					break;
				}
			}
		}

		if(flag){
			std::cout << "error\n";
			continue;
		}

		std::cout << "[";
		for(int i=0 ; i<dq.size()-1 ; i++)
			std::cout << dq[i] << ",";
		std::cout << dq[dq.size()-1] << "]\n";
	}

	return 0;
}
