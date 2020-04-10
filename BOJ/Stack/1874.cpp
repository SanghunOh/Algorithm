#include	<iostream>
#include	<stack>
#include	<vector>

int main(){
	int N;
	std::vector<int> pp;
	std::stack<int> s;
	std::vector<char> push_pop;
	bool visit[100000] = {false};
	bool print[100000] = {false};
	int current = 1;

	std::cin >> N;

	for(int i=0 ; i<N ; i++){
		int a;

		std::cin >> a;
		pp.push_back(a);
	}

	for(int i=0 ; i<N ; i++){
		if(current < pp[i]){
			for(int j=current ; j<=pp[i] ; j++){
				if((!visit[j-1] && !print[j-1])){
					push_pop.push_back('+');
					s.push(j);
					visit[j-1] = true;
				}
				
			}
			int j;

			if(!s.empty()){
				j = s.top();
				s.pop();
			}
			else{
				std::cout << "NO" << std::endl;
				return 0;
			}
			push_pop.push_back('-');
			print[j-1] = true;
			current = pp[i];
		}
		else if(current > pp[i]){
			for(int j=current-1 ; j>=pp[i] ; j--){
				if(!print[j-1]){
					push_pop.push_back('-');
					if(!s.empty()){
						s.pop();
					}
					else{
						std::cout << "NO" << std::endl;
						return 0;
					}
					print[j-1] = true;
				}
			}
			current = pp[i];
		}
		else{
			push_pop.push_back('+');
			push_pop.push_back('-');
			s.push(current);
			s.pop();
			visit[current] = true;
			print[current] = true;
		}
	}
	for(int i=0 ; i<push_pop.size() ; i++)
		std::cout << push_pop[i] << std::endl;
}
