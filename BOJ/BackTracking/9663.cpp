#include	<iostream>
#include	<queue>
#include	<cstdlib>

int nq[16];

bool check(int N, int level){
	for(int i=1 ; i<level ; i++){
		if(nq[level] == nq[i])
			return false;
		if(std::abs(level-i) == std::abs(nq[level] - nq[i]))
			return false;
	}

	return true;
}

int nqueen(int N, int level){
	int sum = 0;
	if(!check(N, level)){
		return 0;
	}
	if(level == N){
		return 1;
	}

	for(int i=1 ; i<=N ; i++){
		nq[level+1] = i;
		sum += nqueen(N, level+1);
	}

	return sum;
}

int main(){
	int N;

	std::cin >> N;

	std::cout << nqueen(N, 0) << std::endl;
}
