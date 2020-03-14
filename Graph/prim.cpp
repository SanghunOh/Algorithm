#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>

typedef struct _edge{
	int v1, v2, w;
}edge;

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
			g[v].push_back(edge{u, v, w});
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
	
	friend std::istream& operator>>(std::istream& is, Graph& g);
};

std::istream& operator>>(std::istream& is, Graph& g){
	is >> g.N >> g.M;
	return is;
}

int prim(Graph& mst, int s){
	int N = mst.getN();
	int* key;
	int* p;
	std::priority_queue<int> pq;
	std::vector<edge>* g = mst.getGraph();

	key = new int[N];
	p = new int[N];

	for(int i=0 ; i<N ; i++){
		key[i] = INF;
		p[i] = -1;
	}

	key[s] = 0;
	for(int i=0 ; i<N ; i++)
		pq.push(i);

	while(!pq.empty()){
		int u = pq.top();
		pq.pop();

		for(std::vector<int>::size_type i=0 ; i<g[u].size() ; i++){
			int v = g[u][i].v2;
			
			if(g[u][i].w < key[v]){
				p[v] = u;
				key[v] = g[u][i].w;
			}
		}
	}

	return 0;
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
