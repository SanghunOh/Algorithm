#include	<iostream>

enum path{
	PATHWAY_COLOR, WALL_COLOR, BLOCKED_COLOR, PATH_COLOR,
};

static int N = 8;
int maze[8][8] = {
	{0,0,0,0,0,0,0,1},
	{0,1,1,0,1,1,0,1},
	{0,0,0,1,0,0,0,1},
	{0,1,0,0,1,1,0,0},
	{0,1,1,1,0,0,1,1},
	{0,1,0,0,0,1,0,1},
	{0,0,0,1,0,0,0,1},
	{0,1,1,1,0,1,0,0}
};

bool findPath(int y, int x){
	if(y<0 || x<0 || x>N-1 || y>N-1)
		return false;
	else if(maze[y][x] != PATHWAY_COLOR)
		return false;
	else if(y == N-1 && x == N-1){
		maze[y][x] = PATH_COLOR;
		return true;
	}

	maze[y][x] = PATH_COLOR;
	if(findPath(y-1, x) || findPath(y, x+1) || findPath(y+1, x) || findPath(y, x-1))
		return true;
	maze[y][x] = BLOCKED_COLOR;
	return false;
}

int main(){
	if(findPath(0, 0))
		std::cout << "Able!" << std::endl;
	else
		std::cout << "Disable!" << std::endl;

	return 0;
}
