#include	<iostream>
#include	<climits>
#include	<string>

int main(){
	int N;
	int count = 0;

	std::cin >> N;
	
	for(int i=666 ; i<=INT_MAX ; i++){
		int DP[6] = {0};
		std::string s = std::to_string(i);

		if(s[0] == '6')
			DP[0] = 1;
		for(int j=1 ; j<s.length() ; j++){
			if(s[j] == '6')
				DP[j] = DP[j-1] + 1;
			else
				DP[j] = 0;
			if(DP[j] == 3){
				count++;
				break;
			}
		}
		if(count == N){
			std::cout << i << std::endl;
			break;
		}
	}
}
