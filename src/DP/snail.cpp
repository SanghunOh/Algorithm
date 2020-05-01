#include	<iostream>
#include	<cstdio>
using namespace std;

/*
 *
 * SNAIL
 * 달팽이가 비오는 날에는 2만큼 올라가고 맑은 날에는 1만큼 올라간다.
 * 이때 높이 N만큼 올라가는데 M일 안에 올라갈 확률
 *
 * 먼저 확률이므로 여사건으로 풀 수도 있다는 사실!
 *
 * 먼저 완전 탐색으로 푼 문제는 여사건을 이용하여 풀었다.
 * height이 N보다 크면 도착한 것이므로 탈출 조건을 만들어주면 된다.
 * 이 조건을 만족시키지 못했는데 day가 M에 도달하면 M일 안에 N만큼
 * 올라갈 수 없다는 뜻이므로 해당 조각의 확률은 0이다!
 *
 * 동적계획법
 * 이 문제를 처음에 못 풀었을 때는 cache배열을 일차원배열로 선언하여 
 * double& ret = cache[height]라 선언하여 풀었다.
 * 그런데 이런식으로 하니 확률이 1을 넘기는 경우가 생겼다.
 * 아직 계산되지 않은 조각인데 계산된 조각을 참조하였기 때문에 1을 넘겼다.
 * 따라서 cache배열을 2차원배열로 선언하였어야 한다.
 *
*/

int N, M;
double cache[1003][1003];

double snail(int height, int day, double pos){
	double& ret = cache[height][day];

	if(height >= N){
		ret = pos;
		return ret;
	}
	else if(day == M)
		return 0;

	if(ret != -1){
		return ret;
	}
	ret = 0;

	ret += snail(height+1, day+1, pos*0.25);
	ret += snail(height+2, day+1, pos*0.75);

	return ret;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		cin >> N >> M;

		for(int i=0 ; i<N+3 ; i++)
			for(int j=0 ; j<N+3 ; j++)
			cache[i][j] = -1;

		printf("%.10f\n", snail(0, 0, 1));
//		cout << fixed;		고정소수점 방식으로 출력하라!
//		cout << precision(10);	소수점 10자리까지 표현하겠다!
	}

	return 0;	
}
