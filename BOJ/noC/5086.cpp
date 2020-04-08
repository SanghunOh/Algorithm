#include	<iostream>

int main(){
	while(1){
		int a, b;

		std::cin >> a >> b;

		if(!a && !b)
			break;

		if(b%a == 0)
			std::cout << "factor" << std::endl;
		else if(a%b==0)
			std::cout << "multiple" <<std::endl;
		else
			std::cout << "neither" << std::endl;
	}

	return 0;
}
