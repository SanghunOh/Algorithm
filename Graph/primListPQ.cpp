#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>

struct _edge{
	int v1, v2, w;
};

bool operator==(_edge& a, _edge& b){
	if(a.v1 == b.v1 && a.v2 == b.v2 && a.w == b.w)
		return true;
	return false;
}

typedef struct _edge edge;

const int INF = 9999999;

class Graph{
	int N;
	int M;
	std::vector<edge>* g;

public:
	Graph(){}

	void init(){
		g = new std::vector<edge>[N];

		for(int i=0 ; i<M ; i++){
			int u, v, w;
			std::cin >> u >> v >> w;

			g[u].push_back(edge{u, v, w});
			g[v].push_back(edge{v, u, w});
		}
	}

	int getN(){
		return N;
	}

	int getM(){
		return M;
	}

	std::vector<edge>*& getGraph(){
		return g;
	}

	~Graph(){
		for(int i=0 ; i<N ; i++)
			std::vector<edge>().swap(g[i]);
	}
	
	friend std::istream& operator>>(std::istream& is, Graph& g);
};

std::istream& operator>>(std::istream& is, Graph& g){
	is >> g.N >> g.M;
	return is;
}

int prim(Graph& mst, int s){
	int N = mst.getN();
	int M = mst.getM();
	std::vector<edge>* g = mst.getGraph();
	int sum=0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	std::vector<int> key(N, INF);
	std::vector<bool> sel(N, false);

	pq.push(std::make_pair(0, s));
	key[s] = 0;

	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();

		sel[u] = true;

		std::vector<edge>::iterator i;
		for(i=g[u].begin() ; i != g[u].end() ; i++){
			int v = i->v2;
			int w = i->w;
			
			if(!sel[v] && key[v] > w){
				key[v] = w;
				pq.push(std::make_pair(key[v], v));
			}
		}
	}

	for(int i=0 ; i<N ; i++){
		sum += key[i];
		std::cout << key[i] << " ";
	}
	std::cout << std::endl;
//		sum += key[i];

	return sum;
}

int main(){
	Graph mst;
	int s;

	std::cin >> mst;
	std::cin >> s;
	mst.init();

	std::cout << prim(mst, s) << std::endl;

	return 0;
}
