#include	<iostream>
#include	<string>
#include	<cstring>
#define INF 987654321
using namespace std;

/*
 *
 * 원주율 외우기
 * 숫자가 주어지고 이를 세자리에서 다섯자리로 끊어서 외울 때 최소의 난이도를 구하는 문제
 *
 * 먼저 완전 탐색 문제로 생각해보자.
 * 이 경우 숫자의 각자리를 순서대로 3, 4, 5자리로 끊은 후 이 문자열이
 * 어떤 난이도인지 파악한다. 
 *
 * calDifferential(string) = string의 최소 난이도
 *
 * 이때 어떤 자리에서 난이도를 판단할 때 이미 그 자리에서의 최소의 난이도를 
 * 파악한 경우 저장해두었던 난이도를 리턴하고 모를 경우 완전탐색으로 구한다.
 *
*/

int cache[10001];
string strPi;

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

int calDifficulty(int start){
	int ret = INF;
	if(strPi.length() - start < 3)
		return INF;
	int len = strPi.length() - start;
	if(cache[start] != -1)
		return cache[start];

	if(len >= 3 && len <= 5){
		if(isSame(strPi.substr(start)))
			ret = (cache[start] = 1);
		else if(isIncDec(strPi.substr(start)))
			ret = (cache[start] = 2);
		else if(isIriJuri(strPi.substr(start)))
			ret = (cache[start] = 4);
		else if(isDifferential(strPi.substr(start)))
			ret = (cache[start] = 5);
		else
			ret = (cache[start] = 10);
		return ret;
	}
	else{
		for(int i=3 ; i<=5 ; i++){
			if(isSame(strPi.substr(start, i)))
				ret = (cache[start] = min(ret, 1+calDifficulty(start+i)));
			else if(isIncDec(strPi.substr(start, i)))
				ret = (cache[start] = min(ret, 2+calDifficulty(start+i)));
			else if(isIriJuri(strPi.substr(start, i)))
				ret = (cache[start] = min(ret, 4+calDifficulty(start+i)));
			else if(isDifferential(strPi.substr(start, i)))
				ret = (cache[start] = min(ret, 5+calDifficulty(start+i)));
			else{
				ret = (cache[start] = min(ret, 10+calDifficulty(start+i)));
			}
		}
	}

	return ret;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		cin >> strPi;

		memset(cache, -1, sizeof(cache));
		cout << calDifficulty(0) << endl;
	}
}
