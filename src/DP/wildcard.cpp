#include	<iostream>
#include	<vector>
#include	<string>
using namespace std;

int cache[101][101];
string pattern;

bool match(string str, int w, int s){
	int& ret = cache[w][s];

	if(ret != -1)
		return ret;
	while(w < pattern.length() && s<str.length()&&(pattern[w] == '?' || pattern[w] == str[s])){
		w++;
		s++;
	}

	if(w == pattern.length())
		return ret = (s == str.length());

	if(pattern[w] == '*')
		for(int skip=0 ; skip+s<=str.length() ; skip++)
			if(match(str, w+1, s+skip))
				return ret = 1;

	return ret = 0;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		int N;
		vector<string> s;

		cin >> pattern;
		cin >> N;
		s.resize(N);
		for(int i=0 ; i<N ; i++){
			cin >> s[i];

			if(match(s[i], 0, 0))
				cout << s[i] << endl;
		}
	}

	return 0;
}
