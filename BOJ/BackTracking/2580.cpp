#include	<iostream>
#include	<stack>

bool checkVertical(int sudo[][9], int y, int x){
	int count = 0;
	for(int i=0 ; i<9 ; i++){
		if(!sudo[i][x])
			count++;
	}
	return count == 1;
}

bool checkHor(int sudo[][9], int y, int x){
	int count = 0;
	for(int i=0 ; i<9 ; i++){
		if(!sudo[y][i])
			count++;
	}
	return count == 1;
}

bool checkRect(int sudo[][9], int y, int x){
	int count = 0;
	int _y = (y/3)*3;
	int _x = (x/3)*3;

	for(int i=0 ; i<3 ; i++){
		for(int j=0 ; j<3 ; j++){
			if(!sudo[_y+i][_x+j])
				count++;
		}
	}

	return count == 1;
}

int calFromVertical(int sudo[][9], int y, int x){
	int a = 45;
	for(int i=0 ; i<9 ; i++)
		a -= sudo[i][x];
	return a;
}

int calFromHor(int sudo[][9], int y, int x){
	int a = 45;
	for(int i=0 ; i<9 ; i++)
		a -= sudo[y][i];

	return a;
}

int calFromRect(int sudo[][9], int y, int x){ 
	int a = 45;
	int _y = (y/3)*3;
	int _x = (x/3)*3;

	for(int i=0 ; i<3 ; i++)
		for(int j=0 ; j<3 ; j++)
			a -= sudo[_y+i][_x+j];

	return a;
}

bool findSudoku(int sudo[][9], int y, int x){
	if(y == 9 && x == 0){
		return true;
	}
	if(sudo[y][x]){
		findSudoku(sudo, y+(x+1)/9, (x+1)%9);
	}

	bool vert = checkVertical(sudo, y, x);
	bool hor = checkHor(sudo, y, x);
	bool rect = checkRect(sudo, y, x);

	if(!vert && !hor && !rect){
		findSudoku(sudo, y+(x+1)/9, (x+1)%9);
	}

	if(checkVertical(sudo, y, x)){
		sudo[y][x] = calFromVertical(sudo, y, x);
		std::cout << y << " " << x << " : " << sudo[y][x] << std::endl;
	findSudoku(sudo, y+(x+1)/9, (x+1)%9);
	}
	else if(checkHor(sudo, y, x)){
		sudo[y][x] = calFromHor(sudo, y, x);
		std::cout << y << " " << x << " : " << sudo[y][x] << std::endl;
	findSudoku(sudo, y+(x+1)/9, (x+1)%9);
	}
	else if(checkRect(sudo, y, x)){
		sudo[y][x] = calFromRect(sudo, y, x);
		std::cout << y << " " << x << " : " << sudo[y][x] << std::endl;
	findSudoku(sudo, y+(x+1)/9, (x+1)%9);
	}

	return true;
}

int main(){
	int sudoku[9][9];
	std::stack<std::pair<int, int>> s;

	for(int i=0 ; i<9 ; i++)
		for(int j=0 ; j<9 ; j++)
			std::cin >> sudoku[i][j];

	findSudoku(sudoku, 0, 0);

	for(int i=0 ; i<9 ; i++){
		for(int j=0 ; j<9 ; j++)
			std::cout << sudoku[i][j] << " ";
		std::cout << std::endl;
	}

	return 0;
}
