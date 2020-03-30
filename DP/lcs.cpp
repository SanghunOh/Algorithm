#include	<iostream>
#include	<string>
#include	<algorithm>

void findSubString(std::string& str, int** p, std::string a, int y, int x){
	if(!y || !x)
		return;
	if(p[y][x] == 0){
		findSubString(str, p, a, y-1, x-1);
		str.push_back(a[y-1]);
	}
	else if(p[y][x] == -1){
		findSubString(str, p, a, y, x-1);
	}
	else if(p[y][x] == 1){
		findSubString(str, p, a, y-1, x);
	}
}

int lcs(std::string a, std::string b){
	int **p;
	int n = a.length();
	int m = b.length();
	std::string str;
	int ** c;

	c = new int* [n+1];
	p = new int* [n+1];
	for(int i=0 ; i<n+1 ; i++){
		c[i] = new int[m+1];
		p[i] = new int[m+1];
		std::fill(c[i], c[i]+m+1, 0);
		std::fill(p[i], p[i]+m+1, 0);
	}

	for(int i=0 ; i<=n ; i++){
		for(int j=0 ; j<=m ; j++){
			if(!i || !j)
				c[i][j] = 0;
			else if(a[i-1] == b[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
				p[i][j] = 0;
			}
			else{
				if(c[i-1][j] < c[i][j-1]){
					c[i][j] = c[i][j-1];
					p[i][j] = -1;
				}
				else{
					c[i][j] = c[i-1][j];
					p[i][j] = 1;
				}
			}
		}
	}

	findSubString(str, p, a, n, m);
	std::cout << str << std::endl;
	return c[n][m];
}

int main(){
	std::string a;
	std::string b;

	std::cin >> a >> b;

	std::cout << lcs(a, b) << std::endl;
}
