#include	<iostream>
#include	<vector>
#define INF 987654321
using namespace std;

vector<vector<int>> clockSwitch;

/*
 *
 * 16개의 시계를 모두 12시로 맞추기 위해 눌러야하는 최소 스위치 수
 * 시계는 3->6->9->12->3->...으로 진행되기 때문에 한 스위치를 4번 이상 누를 필요가 없다!
 * 또한 스위치의 누르는 순서는 결과와 전혀 상관이 없다!
 * -> 결과와 순서가 상관 없을 때는 순서를 강요한다. 
 * 이 문제의 경우 1번 스위치->2번 스위치->...->10번 스위치
 * 이 경우 고려하는 경우의 수는 4의 10승=1048576
 *
 * **최적화 문제**
 * 앞의 picnic, boardcover, boggle들은 경우의 수를 구하는 문제이므로
 * 어떤 조각을 방문했는지 하지 안았는지를 나타내는 bool배열을 이용하여
 * bool = true -> 함수 호출 -> bool = false로 했다면,
 *
 * 최적화 문제는 ret = INF -> ret = min(ret, 기본값 + 재귀함수 리턴값)을 이용하여
 * 구할 수 있다. 
 *
 * 또한, 이 문제에서 빠트린 점 : 어떤 스위치를 누르면 clock배열 값에 +3을 해준다.
 * 하지만 clock의 값은 3, 6, 9, 12밖에 없으므로
 * 12인 상태에서 +3을 해줬을 때 예외처리를 해줘야한다!
 *
*/

/*
int findTwelveClock(vector<int>& clock, vector<int>& switchCount, int a){
	int finished = true;
	int result = INF;

	for(int i=0 ; i<16 ; i++)
		if(clock[i] != 12)
			finished = false;

	if(finished)
		return a+1;

	for(int i=0 ; i<10 ; i++){
		int ret;
		if(switchCount[i]==3)
			continue;

		switchCount[i] += 1;
		for(int j=0 ; j<clockSwitch[i].size() ; j++){
			int idx = clockSwitch[i][j];
			clock[idx] += 3;
			if(clock[idx] == 15)
				clock[idx] = 3;
		}

		ret = findTwelveClock(clock, switchCount, a+1);

		switchCount[i] -= 1;
		for(int j=0 ; j<clockSwitch[i].size() ; j++){
			int idx = clockSwitch[i][j];
			clock[idx] -= 3;
			if(clock[idx] == 0)
				clock[idx] = 12;
		}


		result = min(result, ret);
	}

	return result;
}
*/

int findTwelveClock(vector<int>& clock, int swtch){
	if(swtch == 10){
		bool finished = true;
		for(int i=0 ; i<16 ; i++)
			if(clock[i] != 12)
				return INF;
		if(finished)
			return 0;
	}
	int ret = INF;

	for(int i=0 ; i<4 ; i++){
		ret = min(ret, i+findTwelveClock(clock, swtch+1));
		for(int j=0 ; j<clockSwitch[swtch].size() ; j++){
			int idx = clockSwitch[swtch][j];
			clock[idx] += 3;
			if(clock[idx] == 15)
				clock[idx] = 3;
		}
	}

	return ret;
}
int main(){
	int T;
	vector<int> tmp;

	tmp.push_back(0);
	tmp.push_back(1);
	tmp.push_back(2);

	clockSwitch.push_back(tmp);
	tmp.clear();

	tmp.push_back(3);
	tmp.push_back(7);
	tmp.push_back(9);
	tmp.push_back(11);

	clockSwitch.push_back(tmp);
	tmp.clear();

	tmp.push_back(4);
	tmp.push_back(10);
	tmp.push_back(14);
	tmp.push_back(15);

	clockSwitch.push_back(tmp);
	tmp.clear();

	tmp.push_back(0);
	tmp.push_back(4);
	tmp.push_back(5);
	tmp.push_back(6);
	tmp.push_back(7);

	clockSwitch.push_back(tmp);
	tmp.clear();

	tmp.push_back(6);
	tmp.push_back(7);
	tmp.push_back(8);
	tmp.push_back(10);
	tmp.push_back(12);

	clockSwitch.push_back(tmp);
	tmp.clear();

	tmp.push_back(0);
	tmp.push_back(2);
	tmp.push_back(14);
	tmp.push_back(15);

	clockSwitch.push_back(tmp);
	tmp.clear();

	tmp.push_back(3);
	tmp.push_back(14);
	tmp.push_back(15);

	clockSwitch.push_back(tmp);
	tmp.clear();

	tmp.push_back(4);
	tmp.push_back(5);
	tmp.push_back(7);
	tmp.push_back(14);
	tmp.push_back(15);

	clockSwitch.push_back(tmp);
	tmp.clear();

	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(3);
	tmp.push_back(4);
	tmp.push_back(5);

	clockSwitch.push_back(tmp);
	tmp.clear();

	tmp.push_back(3);
	tmp.push_back(4);
	tmp.push_back(5);
	tmp.push_back(9);
	tmp.push_back(13);

	clockSwitch.push_back(tmp);
	tmp.clear();
	
	cin >> T;

	
	while(T--){
		vector<int> clock(16);
		vector<int> switchCount(16, 0);

		for(int i=0 ; i<16 ; i++)
			cin >> clock[i];

		int count = findTwelveClock(clock, 0);
		if(count == INF)
			cout << -1 << endl;
		else
			cout << count << endl;
	}

	return 0;
}
