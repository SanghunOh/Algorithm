#include	<iostream>

int board_y[4][3] = {{0, 1, 1}, {0, 0, 1}, {0, 0, 1}, {0, 1, 1}};
int board_x[4][3] = {{0, 0, 1}, {0, 1, 0}, {0, 1, 1}, {1, 0, 1}};

bool can_put_board(char board[][20], int H, int W, int y, int x, int shape){
	if(y<0 || y>H || x<0 || x>W)
		return false;
	for(int i=0 ; i<4 ; i++){
		for(int j=0 ; j<3 ; j++){
			int _y = y+board_y[i][j];
			int _x = x+board_x[i][j];

			if(y<0 || y>H || x<0 || x>W)
				return false;
			if(board[_y][_x] == '#')
				return false;
		}
	}
	return true;
}
/*
int count_covering(char board[][20], int H, int W, int N){
	int ret = 0;
	int y = -1, x;

	for(int i=0 ; i<H ; i++){
		for(int j=0 ; j<W ; j++){
			if(board[i][j] == '.'){
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1)
			break;
	}
	if(x == W-1)
		x -= 1;

//	std::cout << y << ", " << x << std::endl;
	
	for(int i=0 ; i<4 ; i++){
		for(int j=0 ; j<3 ; j++)
			board[y+board_y[i]][x+board_x[j]] = '#';

		ret += put_board(board, H, W, N, y, x, i, 0);

		for(int j=0 ; j<3 ; j++)
			board[y+board_y[i]][x+board_x[j]] = '.';
	}

	return ret;
	
}
*/
int put_board(char board[][20], int H, int W, int N, int y, int x, int shape, int num){
	int ret = 0;
	if(num == N)
		return 1;
	if(!can_put_board(board, H, W, y, x, shape))
		return 0;
	y = -1;

	for(int i=0 ; i<H ; i++){
		for(int j=0 ; j<W ; j++){
			if(board[i][j] == '.'){
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1)
			break;
	}
	if(x == W-1)
		x -= 1;
	for(int i=0 ; i<4 ; i++){
		for(int j=0 ; j<3 ; j++){
			board[y+board_y[i][j]][x+board_x[i][j]] = '#';

		ret += put_board(board, H, W, N, y, x, i, num+1);

		for(int j=0 ; j<3 ; j++)
			board[y+board_y[i][j]][x+board_x[i][j]] = '.';
		}
	}

	return ret;
}

int main(){
	int T;
	int H, W;
	char board[20][20];

	std::cin >> T;

	for(int i=0 ; i<T ; i++){
		int count_point=0;
		std::cin >> H >> W;

		for(int j=0 ; j<H ; j++)
			for(int k=0 ; k<W ; k++){
				std::cin >> board[j][k];
				if(board[j][k] == '.')
					count_point++;
			}

		if((count_point%3))
			std::cout << 0;
		else
			std::cout << put_board(board, H, W, count_point/3, 0, 0, 0, 0) << std::endl;
	}

	return 0;
}
