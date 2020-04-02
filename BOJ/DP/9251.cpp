#include	<iostream>
#include	<string>

// 단순 longest common subsequence 문제

int main(){
	std::string a;
	std::string b;
	int lcs[1001][1001] = {0};

	std::cin >> a >> b;

	for(int i=0 ; i<=a.length() ; i++){
		for(int j=0 ; j<=b.length() ; j++){
			if(!i || !j){
				lcs[i][j] = 0;
			}
			else if(a[i-1] == b[j-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
			}
			else{
				lcs[i][j] = std::max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}

	for(int i=0 ; i<=a.length() ; i++){
		for(int j=0 ; j<=b.length() ; j++)
			std::cout << lcs[i][j] << " ";
		std::cout << std::endl;
	}

	std::cout << lcs[a.length()][b.length()] << std::endl;
}
