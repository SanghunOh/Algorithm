#include	<iostream>
#include	<string>

int main(){
	int N;

	std::cin >> N;

	for(int i=0 ; i<N ; i++){
		std::string ox;
		int score[100] = {0};

		std::cin >> ox;

		if(ox[0] == 'O')
			score[0] = 1;

		for(int i=1 ; i<ox.length() ; i++){
			if(ox[i] == 'O')
				score[i] = score[i-1] + 1;
		}
	
		int sum = 0;
		for(int i=0 ; i<ox.length() ; i++){
			sum += score[i];
		}
	
		std::cout << sum << std::endl;
	}
}
