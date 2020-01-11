#include	<iostream>
#include	<string>

const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

char board[5][5]={'U', 'R', 'L', 'P', 'M', 'X', 'P', 'R', 'E', 'T', 'G', 'I', 'A', 'E', 'T', 'X', 'T', 'N', 'Z', 'Y', 'X', 'O', 'Q', 'R', 'S'};

bool inRange(int y, int x){
	if(y < 0 || y > 4 || x < 0 || x > 4)
		return false;
	return true;
}

bool hasWord(int y, int x, const std::string& word){
	if(!inRange(y, x))			// 아래의 for문 안에서 검사 할 수도 있지만 앞으로 빼면 코드가 간결해짐!
		return false;
	if(board[y][x] != word[0])		// 방향에 따라 검사 할 필요가 없어짐
		return false;

						// 이 아래로는 모두 방향에 따라 검사해야되는 케이스!
	if(word.size() == 1)
		return true;

	for(int dir=0 ; dir<8 ; dir++){
		int nextY = y + dy[dir];
		int nextX = x + dx[dir];

		if(hasWord(nextY, nextX, word.substr(1)))
			return true;
		
	}

	return false;
}

int main(){
	for(int i=0 ; i<5 ; i++){
		for(int j=0 ; j<5 ; j++)
			std::cout << board[i][j] << ' ';
		std::cout << std::endl;
	}

	std::string word;

	std::cin >> word;

	for(int i=0 ; i<5 ; i++){
		for(int j=0 ; j<5 ; j++){
			if(hasWord(i, j, word)){
				std::cout << word << " is in board!" << std::endl;
				return 0;
			}
			else
				std::cout << word << " is not in board" << std::endl;
		}
	}

	return 0;
}
