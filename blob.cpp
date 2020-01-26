#include	<iostream>

static int N = 8;
static int pix[8][8] = {
	{1,0,0,0,0,0,0,1},
	{0,1,1,0,0,1,0,0},
	{1,1,0,0,1,0,1,0},
	{0,0,0,0,0,1,0,0},
	{0,1,0,1,0,1,0,0},
	{0,1,0,1,0,1,0,0},
	{1,0,0,0,1,0,0,1},
	{0,1,1,0,0,1,1,1}
};

int blob(int y, int x){
	if(y<0 || x<0 || y>N-1 || x>N-1)
		return 0;
	if(pix[y][x] != 1)
		return 0;
	
	pix[y][x] = 2;
	return 1 + blob(y-1, x) + blob(y-1, x+1) + blob(y, x+1) + blob(y+1, x+1) + blob(y+1, x) + blob(y+1, x-1) + blob(y, x-1) + blob(y-1, x-1);
}

int main(){
	std::cout << "count : " << blob(7, 7) << std::endl;

	return 0;	
}
