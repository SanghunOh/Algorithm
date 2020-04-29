#include	<iostream>
#include	<vector>
using namespce std;
int N;

int findMaxFenceSize(vector<int>& fence, int left, int right){
	int ret;
	int mid;

	if(left == right)
		return fence[left];

	mid = (left+right)/2;

	ret = max(findMaxFenceSize(fence, left, mid), findMaxFenceSize(fence, mid+1, right));

	int lo = mid;
	int hi = mid+1;
	int height = min(h[lo], h[hi]);

	ret = max(ret, 2*height);

	while(left < lo || hi < right){
		if(hi < right && (left == lo || fence[lo-1] < fence[hi+1])){
			hi++;
			height = min(height, fence[hi];
		}
		else{
			lo--;
			height = min(height, fence[lo];
		}

		ret = max(ret, height*(hi-lo+1));
	}

	return ret;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		vector<int> fence;

		cin >> N;
		for(int i=0 ; i<N ; i++){
			int tmp;
			cin >> tmp;

			fence.push_back(tmp);
		}

		findMaxFenceSize(fence, 0, N-1);
	}
}
