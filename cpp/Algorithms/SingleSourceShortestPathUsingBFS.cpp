/* Author :Shreyash Vardhan */
// Single source shortest path using BFS is used to calculate the minimum distance to go from point A to point B
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
	map<T,list<T>> m;
	public:
		// Building the graph
		void addEdge(T a,T b){
			m[a].push_back(b);
			m[b].push_back(a);
		}
		// Breadth First function
		void bfs(T src){
			map<T,int> dist;
			queue<int> q;
			for(auto it: m){
				T node=it.first;
				dist[node]=INT_MAX;
			}
			q.push(src); 
			dist[src]=0;
			while(!q.empty()){
				T node=q.front();
				q.pop();
				for(auto it: m[node]){
					if(dist[it]==INT_MAX){
						q.push(it);
						dist[it]=dist[node]+1;
						}
				}
			}
			for(auto it: m){
				T node_pair=it.first;
				int d=dist[node_pair];
				// Printin the distance
				cout<<"Distance of node " << node_pair << " is "<< d<<endl;
			}
		}
};

int main(){
	graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.bfs(0);
}
