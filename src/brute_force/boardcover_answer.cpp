#include	<iostream>
#include	<vector>

const int coverType[4][3][2] = {
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};

bool set(std::vector<std::vector<int>>& board, int y, int x, int shape, int delta){
	bool ok = true;

	for(int i=0 ; i<3 ; i++){
		const int _y = y+coverType[shape][i][0];
		const int _x = x+coverType[shape][i][1];

		if(_y<0 || _y >= board.size() || _x<0 || x>=board[0].size())
			ok = false;
		else if((board[_y][_x] += delta) > 1)
			ok = false;
	}
	return ok;
}

int cover(std::vector<std::vector<int>>& board){
	int y = -1, x = -1;

	for(int i=0 ; i<board.size() ; i++){
		for(int j=0 ; j<board[i].size() ; j++){
			if(board[i][j] == 0){
				y = i;
				x = j;
				break;
			}
		}
		if(y == -1)
			break;
	}

	if(y == -1)
		return 1;

	int ret = 0;

	for(int shape=0 ; shape<4 ; shape++){
		if(set(board, y, x, shape, 1))
			ret += cover(board);
		set(board, y, x, shape, -1);
	}

	return ret;
}

int main(){
	int T;
	int H, W;
	std::vector<std::vector<int>> board;

	std::cin >> T;

	for(int i=0 ; i<T ; i++){
		std::cin >> H >> W;
		for(int j=0 ; j<H ; j++){
			std::vector<int> tmp;
			for(int k=0 ; k<W ; k++){
				char c;
				std::cin >> c;
				if(c == '#')
					tmp.push_back(1);
				else if(c == '.')
					tmp.push_back(0);	
			}
			board.push_back(tmp);
			
		}

		std::cout << cover(board) << std::endl;
	}

	return 0;
}
