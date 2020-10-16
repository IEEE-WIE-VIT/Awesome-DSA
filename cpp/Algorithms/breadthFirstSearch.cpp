/* Author : Shreyash Vardhan */
// Implementation of breadth first search in undirected graph 
#include<bits/stdc++.h>
using namespace std;
#define N 100005
vector<int> gr[N];
int main(){
	int n,m;
	cin>>n>>m;
	while(m--){
		// input  the edges of graph and build the graph 
		int u,v;
		cin>>u>>v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	// maintain a visited boolean array to check we are not visiting same vertex again 
	bool vis[n];
	memset(vis,0,sizeof vis);
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int node=q.front();
		vis[node]=1;
		// now take the node out of the queue 
		q.pop();
		cout<<node<<" ";
		for(auto x:gr[node])
		{
			// if neighbours of node are not visited then push them to the queue
			if(!vis[x])
			{
			q.push(x);
		}
		}
	}
}






