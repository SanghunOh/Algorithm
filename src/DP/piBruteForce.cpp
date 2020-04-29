#include	<iostream>
#include	<string>
using namespace std;

bool isSame(string str){
	if(str.length() < 3)
		return false;
	char a = str[0];
	for(int i=1 ; i<str.length() ; i++)
		if(a != str[i])
			return false;
	return true;
}

bool isIncDec(string str){
	if(str.length() < 3)
		return false;
	char a = str[0];
	for(int i=1 ; i<str.length() ; i++)
		if(abs(a-str[i]) != i)
			return false;
	return true;
}

bool isIriJuri(string str){
	if(str.length() < 3)
		return false;
	if(str[0] != str[2])
		return false;
	if(str.length() >= 4)
		if(str[1] != str[3])
			return false;
	if(str.length() == 5)
		if(str[2] != str[4])
			return false;
	return true;
}

bool isDifferential(string str){
	if(str.length() < 3)
		return false;
	int dif = str[1] - str[0];
	for(int i=2 ; i<str.length() ; i++)
		if(str[i]-str[i-1] != dif)
			return false;
	return true;
}

int calDifficulty(string str){
	int ret = 987654321;
	if(str.length() < 3)
		return 987654321;

	if(str.length() >= 3 && str.length() <= 5){
		if(isSame(str))
			ret = 1;
		else if(isIncDec(str))
			ret = 2;
		else if(isIriJuri(str))
			ret = 4;
		else if(isDifferential(str))
			ret = 5;
		else{
			ret = 10;
		}
	}
	else{
		for(int i=3 ; i<=5 ; i++){
			if(isSame(str.substr(0, i)))
				ret = min(ret, 1 + calDifficulty(str.substr(i)));
			else if(isIncDec(str.substr(0, i)))
				ret = min(ret, 2 + calDifficulty(str.substr(i)));
			else if(isIriJuri(str.substr(0, i)))
				ret = min(ret, 4 + calDifficulty(str.substr(i)));
			else if(isDifferential(str.substr(0, i)))
				ret = min(ret, 5 + calDifficulty(str.substr(i)));
			else{
				if(str.substr(i).length() >= 3)
					ret = min(ret, 10 + calDifficulty(str.substr(i)));
			}
		}
	}

	return ret;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		string pi;

		cin >> pi;

//		cout << pi.substr(0, 5) << " " << pi.substr(5) << endl;
		cout << calDifficulty(pi) << endl;
	}
}
