#include  <iostream>
#include  <vector>

int main(){
  int N;
  std::vector<int> arr;

  std::cin >> N;
  
  for(int i=0 ; i<N ; i++){
    int t;
    std::cin >> t;
    arr.push_back(t);
  }

  merge_sort(N, arr);

  std::vector<int>::iterator iter;
  for(iter = arr.begin() ; iter!= arr.end() ; i++){
    std::cout << *iter << " ";
  }
  std::cout << std::endl << std::endl;
  return 0;
}