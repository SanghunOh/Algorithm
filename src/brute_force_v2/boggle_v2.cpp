#include	<iostream>
#include	<string>
using namespace std;

/*
 * boggle문제 2차원 문자 배열 속에서 단어 찾기
 *
 *
*/

char boggle[5][5];
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};		//방향에 대한 배열을 만들어서 탐색이 용이하도록 한다.
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool hasWord(string word, int y, int x, int idx){
	if(y<0 || y>4 || x<0 || x>4)		//index 범위를 제일 먼저 검사하여 유효하지 않은 범위이면
		return false;			// 바로 종료한다.

	if(word[idx] != boggle[y][x])
		return false;
	if(idx == word.length()-1){
		return true;
	}					// base case들을 앞으로 뺌으로서 간결한 for문 내부를 만듬

	for(int i=0 ; i<8 ; i++){
		if(hasWord(word, y+dy[i], x+dx[i], idx+1))	//호출문을 통해서 조건문을 만들 수 있다.
			return true;
	}

	return false;
}

int main(){
	string s;

	for(int i=0 ; i<5 ; i++)
		for(int j=0 ; j<5 ; j++)
			cin >> boggle[i][j];

	cin >> s;
	
	for(int i=0 ; i<5 ; i++){		// 격자일 경우 각 위치에 대해 함수를 호출할 수도 있다.
		for(int j=0 ; j<5 ; j++){
			if(hasWord(s, j, i, 0)){
				cout << "O" << endl;
				return 0;
			}
		}
	}
	cout << "X" << endl;

	return 0;
}
