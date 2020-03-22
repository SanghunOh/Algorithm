#include	<iostream>
#include	<algorithm>
#include	<vector>
#define INF	99999

void FloydWarshall(int** graph, int N){
	int** d;
	int** pre;

	d = new int* [N];
	pre = new int* [N];
	for(int i=0 ; i<N ; i++){
		d[i] = new int[N];
		pre[i] = new int[N];
		std::fill(pre[i], pre[i] + N, -1);
		for(int j=0 ; j<N ; j++){
			d[i][j] = graph[i][j];
		}
	}

	for(int k=0 ; k<N ; k++){
		for(int i=0 ; i<N ; i++){
			for(int j=0 ; j<N ; j++){
				if(d[i][j] > d[i][k] + d[k][j] && d[i][k] != INF && d[k][j] != INF){
					d[i][j] = d[i][k] + d[k][j];
					pre[i][j] = k;
				}
			}
		}
	}

	for(int i=0 ; i<N ; i++){
		std::cout << "------from " << i << " ----------" << std::endl;
		for(int j=0 ; j<N ; j++){
			std::cout << "To " << j << " : " << d[i][j] << std::endl;
		}
	}
	return;
}

int main(){
	int N, M;
	int** graph;

	std::cin >> N >> M;

	graph = new int* [N];
	for(int i=0 ; i<N ; i++){
		graph[i] = new int[N];
		std::fill(graph[i], graph[i] + N, INF);
		graph[i][i] = 0;
	}

	for(int i=0 ; i<M ; i++){
		int u, v, w;		

		std::cin >> u >> v >> w;

		graph[u][v] = w;
	}

	FloydWarshall(graph, N);

	return 0;
}
