#include	<iostream>
#include	<cstring>
#include	<vector>
#include	<limits>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m;
int cache[101][101];

int jlis(int A[], int B[], int idxa, int idxb){
	int&ret = cache[idxa+1][idxb+1];

	if(ret != -1)
		return ret;

	ret = 0;
	long long a = (idxa==-1 ? NEGINF : A[idxa]);
	long long b = (idxb==-1 ? NEGINF : B[idxb]);
	long long maxEl = max(a, b);

	for(int i=idxa+1 ; i<n ; i++)
		if(maxEl < A[i])
			ret = max(jlis(A, B, i, idxb)+1, ret);

	for(int i=idxb+1 ; i<m ; i++)
		if(maxEl < B[i])
			ret = max(jlis(A, B, idxa, i)+1, ret);

	return ret;
}

int main(){
	int T;

	cin >>T;

	while(T--){
		int A[101], B[101];
		cin >> n >> m;

		memset(cache, -1, sizeof(cache));
		for(int i=0 ; i<n ; i++)
			cin >> A[i];
		for(int i=0 ; i<m ; i++)
			cin >> B[i];

		cout << jlis(A, B, -1, -1) << endl;
	}
}
