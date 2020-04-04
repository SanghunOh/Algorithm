#include	<iostream>
#include	<vector>
#include	<string>
#include	<algorithm>

bool cmp(std::pair<int, std::string> a, std::pair<int, std::string> b){
	return a.first < b.first;
}

int main(){
	std::ios::sync_with_stdio(false);
	int N;
	std::vector<std::pair<int, std::string>> member;

	std::cin >> N;

	for(int i=0 ; i<N ; i++)
		std::cin >> member[i].first >> member[i].second;

	std::stable_sort(member.begin(), member.end(), cmp);

	for(auto it: member)
		std::cout << it.first << " " << it.second << std::endl;
}
