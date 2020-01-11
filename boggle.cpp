#include	<iostream>
#include	<string>
#include	<vector>

char boggle[5][5] = {'U', 'R', 'L', 'P', 'M', 'X', 'P', 'R', 'E', 'T', 'G', 'I', 'A', 'E', 'T', 'X', 'T', 'N', 'Z', 'Y', 'X', 'O', 'Q', 'R', 'S'};
int dirx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int diry[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int find_num = 0;
int count;

void hasWord(int y, int x, std::string word){
	if(word.size() == 1 && boggle[y][x] == word[find_num]){
		count++;
		return;
	}
	else
		return;
	if(find_num == word.size()-1){
		count++;
		return;
	}

	if(boggle[y][x] == word[find_num]){
		for(int i=0 ; i<8 ; i++){
			if(x+dirx[i] < 0 || x+dirx[i] > 4 || y+diry[i] < 0 || y+diry[i] > 4)
				continue;

			if(boggle[y+diry[i]][x+dirx[i]] == word[find_num+1]){
				int tmp_find = find_num;
				find_num++;
				hasWord(y+diry[i], x+dirx[i], word);
				find_num = tmp_find;
			}
		}
	}
	return;
}

int main(){
	std::string word;

	for(int i=0 ; i<5 ; i++){
		for(int j=0 ; j<5 ; j++)
			std::cout << boggle[i][j] << " ";
		std::cout << std::endl;
	}

	std::cin >> word;

	for(int i=0 ; i<5 ; i++){
		for(int j=0 ; j<5 ; j++){
			hasWord(i, j, word);
			find_num = 0;
		}
	}

	std::cout << count << std::endl;
	
	return 0;
}
