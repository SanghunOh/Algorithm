#include	<iostream>
#include	<string>
#include	<vector>
using namespace std;

/*
 *
 * 처음으로 내 힘으로 푼 문제!!!!!!!!
 * 
 * 흑백그림에 대한 압축데이터(쿼드트리)가 문자열로 변환되어 주어진다.
 * 이때 이 그림을 상하로 반전시킨 데이터에 대한 문자열을 출력하는 문제이다.
 *
 * 한 픽셀을
 * 1 2
 * 3 4 분면으로 볼 때 상하로 반전시킨 픽셀은
 *
 * 3 4 
 * 1 2 이다.
 * 따라서 이 문자열을 1, 2, 3, 4, 분면으로 분할 한뒤 
 * -> 3, 4, 1, 2 순서로 병합하면 반전시킨 문자열을 된다.
 *
 *
*/
string reverseQuadTree(string s){
	vector<string> div;
	string result;

	if(s.length() == 1){	
		if(s[0] == 'w')
			return string("w");
		else if(s[0] == 'b')
			return string("b");
	}

	int idx;

	if(s[0] == 'x'){
		idx = 1;
		result += string("x");
	}
	else
		idx = 0;

	for(int i=0 ; i<4 ; i++){
		if(s[idx] == 'x'){		//한 픽셀이 또 분할되어야하는 경우
			int first = idx;
			int length = 0;
			int count = 0;

			for(int j=0 ; j<s.size()-first ; j++){
				count++;
				length++;
				if(s[idx++] == 'x')
					count -= 4;

				if(count == 1)
					break;
			}

			string str = reverseQuadTree(s.substr(first, length));	// 현재 픽셀을 분할 후 
			div.push_back(str);					// 병합된 문자열을 받는다.
		}
		else{
			string str = reverseQuadTree(s.substr(idx, 1));		// 현재 픽셀이 더 이상
			idx++;							// 분할되지 않을 때
			div.push_back(str);
		}
	}

	result += div[2];
	result += div[3];
	result += div[0];
	result += div[1];

	return result;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		string s;
		string ret;

		cin >> s;

		ret = reverseQuadTree(s);

		cout << ret << endl;
	}
}
