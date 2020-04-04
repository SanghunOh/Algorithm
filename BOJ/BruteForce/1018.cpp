#include	<iostream>
#include	<climits>

int countR(bool chess[][51], int y, int x, bool color){
	int count=0;

	int row_ind=0;
	if(chess[y][x] != color)
		count++;
	
	color = !color;
	for(int i=0 ; i<8 ; i++){
		for(int j=0 ; j<8 ; j++){
			if(!i && !j)
				continue;
			if(chess[y+i][x+j] != color){
				count++;
			}
			color = !color;
		}
		color = !color;
	}

	return count;
}

int RecolorChess(bool chess[][51], int N, int M){
	int min = INT_MAX;
	for(int i=0 ; i<=N-8 ; i++){
		for(int j=0 ; j<=M-8 ; j++){
			int tmp;

			tmp = countR(chess, i, j, true);
			if(min > tmp)
				min = tmp;
			tmp = countR(chess, i, j, false);
			if(min > tmp)
				min = tmp;
		}
	}
	
	return min;
}

int main(){
	int N, M;
	bool chess[51][51];

	std::cin >> N >> M;

	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<M ; j++){
			char a;

			std::cin >> a;
			if(a == 'W')
				chess[i][j] = false;
			else
				chess[i][j] = true;
		}
	}

	std::cout << RecolorChess(chess, N, M) << std::endl;

	return 0;
}
