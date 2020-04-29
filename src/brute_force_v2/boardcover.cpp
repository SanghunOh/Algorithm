#include	<iostream>
#include	<vector>
using namespace std;

int H, W;
const int shape[4][3][2] = {
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};

bool able(char board[][21], bool cover[][21], int y, int x, int sh){
	for(int i=0 ; i<3 ; i++){
		int _y = y+shape[sh][i][0];
		int _x = x+shape[sh][i][1];

		if(_y < 0 || _y > H-1 || _x < 0 || _x > W-1)
			return false;

		if(board[_y][_x] == '#' || cover[_y][_x] == true)
			return false;
	}

	return true;
}

int countCovering(char board[][21], bool cover[][21]){
	int sum = 0;
	int _y = -1;
	int _x = -1;

	for(int i=0 ; i<H ; i++){
		for(int j=0 ; j<W ; j++){
			if(board[i][j] == '.' && !cover[i][j]){
				_y = i;
				_x = j;
				break;
			}
		}

		if(_y != -1)
			break;
	}
	if(_y == -1)
		return 1;

	for(int i=0 ; i<4 ; i++){
		if(able(board, cover, _y, _x, i)){
			for(int j=0 ; j<3 ; j++){
				int ny = _y + shape[i][j][0];
				int nx = _x + shape[i][j][1];
				cover[ny][nx] = true;
			}

			sum += countCovering(board, cover);

			for(int j=0 ; j<3 ; j++){
				int ny = _y + shape[i][j][0];
				int nx = _x + shape[i][j][1];
				cover[ny][nx] = true;
			}
		}
	}

	return sum;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		int count = 0;
		int sum = 0;
		char board[21][21];
		bool cover[21][21] = {false};

		cin >> H >> W;

		for(int i=0 ; i<H ; i++){
			for(int j=0 ; j<W ; j++){
				cin >> board[i][j];
				cover[i][j] = false;
				if(board[i][j] == '.')
					count++;
			}
		}

		if(count%3)
			cout << 0 << endl;
		else{
			cout << countCovering(board, cover) << endl;
		}
	}

	return 0;
}
