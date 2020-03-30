#include	<iostream>

/*
 * 정수 X에 사용할 수 있는 연산은 다음과 같이 세가지이다.
 * 1. X가 3으로 나누어떨어지면, 3으로 나눈다.
 * 2. X가 2로 나누어 덜어지면, 2로나눈다.
 * 3. 1을 뺀다.
 *
 * 정수 X가 주어졌을 때, 위와 같은 연산 세개르르 적절히 사용해서 1을 만들려고 한다.
 * 연산을 사용하는 횟수의 최솟값을  출력하시오.
 *
 * sol)
 * 정수 X에 대해서 (X/3, X/2, X-1)에 해당하는 횟수의 최솟값으로 연산을 진행한다.
*/
int main(){
	int X;
	int count[1000001] = {0};

	std::cin >> X;

	count[1] = 0;
	count[2] = 1;

	for(int i=3 ; i<=X ; i++){
		int a = count[i/3] + 1;
		int b = count[i/2] + 1;
		int c = count[i-1] + 1;

		if(i%3!=0 && i%2!=0)
			count[i] = c;
		else if(i%3 == 0)
			count[i] = std::min(a, c);
		else if(i%2 == 0)
			count[i] = std::min(b, c);
		if(i%3==0 && i%2==0)
			count[i] = std::min(a, std::min(b, c));
	}

	std::cot << count[X] << std::endl;
}
