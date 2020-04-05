#include	<iostream>

/*
 * INPUT
 * 	N,
 *	N개의 수,
 *	각각 연산자의 수
 * INPUT
 *
 * OUTPUT
 *	가능한 연산 결과의 최댓, 최솟값
 * OUTPUT
 *
 * 가능한 연산자의 배열을 재귀를 통해 만들고
 * 만들 때마다 연산자에 따른 계산결과를 도출한다.
 *
*/
enum oper{ADD, SUB, MUL, DIV};
int arr[12];
int min = 1000000000;
int max = -1000000000;

int calculateOP(int op_arr[], int N, int M){
	int ret = arr[0];
	for(int i=0 ; i<M ; i++){
		switch(op_arr[i]){
			case ADD : 
				ret += arr[i+1];
				break;
			case SUB : 
				ret -= arr[i+1];
				break;
			case MUL : 
				ret *= arr[i+1];
				break;
			case DIV : 
				ret /= arr[i+1];
		}
	}
	return ret;
}

void makeOPArr(int op_arr[], int op[], int N, int M, int count){
	if(count == M){
		int t = calculateOP(op_arr, N, M);

		max = std::max(max, t);
		min = std::min(min, t);
		return;
	}

	//여기서 헷갈렸음! 
	//M번 반복하는 반복문은 재귀가 대체하므로 만들필요가 없었다!
	for(int i=0 ; i<4 ; i++){
		if(op[i]){
			op[i] -= 1;
			op_arr[count] = i;
			makeOPArr(op_arr, op, N, M, count+1);
			op[i] += 1;
		}
	}
	
	return;
}

int main(){
	int N;
	int op_arr[12];
	int op[4];

	std::cin >> N;

	for(int i=0 ; i<N ; i++)
		std::cin >> arr[i];

	for(int i=0 ; i<4 ; i++){
		std::cin >> op[i];
	}

	makeOPArr(op_arr, op, N, N-1, 0);

	std::cout << max << std::endl;
	std::cout << min << std::endl;
}
