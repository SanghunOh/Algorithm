#include	<iostream>
#include	<cstdio>
using namespace std;

int N, M;
double possibility;

int snailPossibility(double poss, int height, int day){
	if(height >= N){
		possibility -= poss;
		return 0;
	}
	if(day == M)
		return 0;

	snailPossibility(poss*0.75, height+2, day+1);
	snailPossibility(poss*0.25, height+1, day+1);

	return 0;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		cin >> N >> M;

		possibility = 1;
		snailPossibility(1, 0, 0);
		printf("%.10f\n", 1-possibility);
	}
}
