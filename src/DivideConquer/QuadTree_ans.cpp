#include	<iostream>
#include	<string>

/*
 *
 * 문제를 풀고 기분이 좋았지만 해답을 보니 난 병신인가보다
 *
 * 나의 답과 해답을 근본적인 차이점은 
 * 나는 문자열을 각 4개의 픽셀(문자열)로 나눈 후 
 * 그 문자열에 대해 함수를 재귀로 호출했다.(인자로 토큰화된 문자열을 넘겼다)
 *
 * 반면 해답은 문자열의 문자 하나하나를 검사하였다.
 * 문자 하나가 'b' 또는 'w'이면 재귀를 탈출하고,
 * 'x'이면 그 픽셀을 재귀를 통해 해결한 후 
 * 다음 픽셀을 구한다.
 *
*/
string reverse(string::iterator& it){
	char head = *it;

	it++;
	
	if(head == 'b' || head == 'w')
		return string(1, head);

	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(){
	int T;

	while(T--){
		string s;

		cin >> s;

		cout << reverse(s.begin() << endl;
	}
}
