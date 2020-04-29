#include	<iostream>
#include	<vector>

#define INF 987654321
using namespace std;

double dist[11][11];
int N;

double shortestPath(vector<int>& path, vector<bool>& visit, int length){
	double ret = INF;

	if(path.size() == N)
		return length + dist[path[0]][path.back()];

	for(int i=0 ; i<N ; i++){
		if(visit[i])
			continue;
		int current = path.back();
		path.push_back(i);
		visit[i] = true;

		double cand = shortestPath(path, visit, length+dist[current][i]);

		ret = min(ret, cand);
		visit[i] = false;
		path.pop_back();
	}

	return ret;
}

int main(){
	vector<int> path;
	vector<bool> visit;

	cin >> N;

	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++){
			int a, b;
			double c;

			cin >> a >> b >> c;

			dist[a][b] = c;
		}

	cout << shortestPath(path, visit, 0) << endl;
}
