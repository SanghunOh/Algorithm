#include	<iostream>
#include	<string>

const int INF = 987654321;
string N;

int classify(int a, int b){
	string M = N.substr(a, b-a+1);

	if(M == string(M.size(), M[0]))
		return 1;

	bool progressive = true;;
	for(int i=0 ; i<M.size() ; i++)
		if(M[i+1] - M[i] != M[1] - M[0])
			progressive = false;
	if(progressive && abs(M[1] - M[0]) == 1)
		return 2;

	bool alternating = true;
	for(int i=0 ; i<M.size() ; i++)
		if(M[i] != M[i%2])
			alternating = false;
	if(alternating)
		return 4;
	if(progressive)
		return 5;
	return 10;
}

int cache[10002];

int memorize(int begin){
	if(begin == N.size())		//딱 맞으면 0을 반환 굳이 길이가 3~5일 경우를 나눌 필요가 없었다.
		return 0;

	int& ret = cache[begin];

	if(ret != -1)
		return ret;

	ret = INF;
	if(int L=3 ; L<=5 ; L++)
		if(begin + L <= N.size())	//미리 길이가 넘어가는 것을 방지!
			ret = min(ret, memorize(begin+L) + classify(begin, begin+L-1));

	return ret;
}
