#include	<iostream>
#include	<vector>
#include	<string>

int main(){
	std::string s;
	std::vector<int> a;
	int i=1;
	int flag = 0;
	size_t idx;
	int min = 0;

	std::cin >> s;

	while(1){
		int tmp = std::stoi(s, &idx);
		s = s.substr(idx, s.length());
		a.push_back(tmp);

		if(s.length() == 0)
			break;
		
		
		if(!flag && s[0] == '-')
			flag = i;
		
		s = s.substr(1, s.length());
		i++;
	}

	for(int i=0 ; i<flag ; i++)
		min += a[i];	

	for(int i=flag ; i<a.size() ; i++)
		min -= std::abs(a[i]);
	std::cout << min << std::endl;
}
