#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adjList;
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V);
	void addedge(int v, int w);
	void DFS(int v);
};
Graph::Graph(int V){
	this->V = V;
	adjList = new list<int>[V];
}
Graph::addedge(int v, int w){
	adjList[v].push_back(w);
}
Graph::DFS(int v){
	bool* visited = new bool[v];
	for(int i = 0; i < v; i++)
		visited[v] = false;
	DFSUtil(v, visited);
}
Graph::DFSUtil(int v, bool visited[]){
	visited[v] = true;
	cout << v << " ";
	list<int>::iterator itr;
	for(itr = adjList.begin(); itr != adjList.end(); itr++){
		if(!visited[*itr])
			DFSUtil(*itr, visited);
	}
}


int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	int V, A[2];
	cin >> V;
	Graph g(V);
	while(cin >> A[0] >> A[1])
		g.addedge(A[0], A[1]);
	g.DFS(2);
	return 0;
}


