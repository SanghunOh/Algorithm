#include	<iostream>
#include	<vector>
#include	<string>
using namespace std;

bool match(const string& pattern, const string& s){
	int pos = 0;

	while(pos<pattern.length() && pos<s.length() && (pattern[pos]=='?' || pattern[pos]==s[pos]))
		pos++;

	if(pos == pattern.length())
		return pos == s.length();
	if(pattern[pos] =='*'){
		for(int skip=0 ; skip+pos<=s.length() ; skip++){
			if(match(pattern.substr(pos+1), s.substr(skip+pos)))
				return true;
		}
	}
	return false;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		string pattern;
		int N;
		vector<string> s;

		cin >> pattern;
		cin >> N;
		s.resize(N);

		for(int i=0 ; i<N ; i++){
			cin >> s[i];

			if(match(pattern, s[i]))
				cout << s[i] << endl;
		}
	}

	return 0;
}
