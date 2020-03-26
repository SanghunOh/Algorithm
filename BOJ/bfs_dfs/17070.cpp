#include	<iostream>

int find_path(int base[][16], int N, int state, int y, int x){
	int sum = 0;
	if(y<0 || y>N-1 || x<0 || x>N-1)
		return 0;

	if(y == N-1 && x == N-1)
		return ++sum;

	if(state == 0){
		if(!base[y][x+1])
			sum += find_path(base, N, 0, y, x+1);
		if(!base[y][x+1] && !base[y+1][x+1] && !base[y+1][x])
			sum += find_path(base, N, 2, y+1, x+1);
	}
	else if(state == 1){
		if(!base[y+1][x])
			sum += find_path(base, N, 1, y+1, x);
		if(!base[y+1][x] && !base[y+1][x+1] && !base[y][x+1])
			sum += find_path(base, N, 2, y+1, x+1);
	}
	else if(state == 2){
		if(!base[y][x+1])
			sum += find_path(base, N, 0, y, x+1);
		if(!base[y+1][x] && !base[y+1][x+1] && !base[y][x+1])
			sum += find_path(base, N, 2, y+1, x+1);
		if(!base[y+1][x])
			sum += find_path(base, N, 1, y+1, x);
	}

	return sum;
}

int main(){
	int base[16][16];
	int N;

	std::cin >> N;

	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			std::cin >> base[i][j];

	std::cout << find_path(base, N, 0, 0, 1) << std::endl;
}
