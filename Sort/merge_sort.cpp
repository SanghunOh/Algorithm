#include  <iostream>
#include  <vector>

void merge(std::vector<int>& arr, int p, int q, int r){
	std::vector<int> tmp(q-p+1);
	int first = p;
	int second = r+1;
	int idx = p;
	while(first <= r && second <= q){
		if(arr[first] <= arr[second]){
			tmp[idx++] = arr[first++];
		}
		else{
			tmp[idx++] = arr[second++];
		}
	}

	while(first <= r)
		tmp[idx++] = arr[first++];
	while(second <= q)
		tmp[idx++] = arr[second++];
	for(int i=p ; i<=q ; i++)
		arr[i] = tmp[i];
}

void merge_sort(int p, int q, std::vector<int>& arr){
	if(p<q){
		int r = (p+q)/2;
	
		merge_sort(p, r, arr);
		merge_sort(r+1, q, arr);
		merge(arr, p, q, r);
	}
}


int main(){
  int N;
  std::vector<int> arr;

  std::cin >> N;
  
  for(int i=0 ; i<N ; i++){
    int t;
    std::cin >> t;
    arr.push_back(t);
  }

  merge_sort(0, N-1, arr);

  std::vector<int>::iterator iter;
  for(iter = arr.begin() ; iter!= arr.end() ; iter++){
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  for(std::vector<int>::size_type i=0 ; i<arr.size() ; i++)
	  std::cout << arr[i] << " ";
  std::cout << std::endl << std::endl;

  return 0;
}
