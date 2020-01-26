#include	<iostream>

bool visit[10] = {false, };
bool areFriends[10][10] = {false, };

int countParings(int n, int m){
	int count=0;
	int first = -1;

	for(int i=0 ; i<n ; i++){
		if(!visit[i]){
			first = i;
			break;
		}
	}

	if(first == -1)
		return 1;


	for(int pairwith = first+1 ; pairwith<n ; pairwith++){
		if(!visit[pairwith] && areFriends[pairwith][first]){
			visit[first] = visit[pairwith] = true;

			count += countParings(n, m);

			visit[first] = visit[pairwith] = false;
		}
	}
	return count;
}

int main(){
	int T;
	int n, m;

	std::cin >> T;

	for(int i=0 ; i<T ; i++){
		int f1, f2;
		std::cin >> n >> m;


		for(int i=0 ; i<m ; i++){
			std::cin >> f1 >> f2;
			areFriends[f1][f2] = true;
			areFriends[f2][f1] = true;
		}

		std::cout << countParings(n, m) << std::endl;

	}


	return 0;
}
