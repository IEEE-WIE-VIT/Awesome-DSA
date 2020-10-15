/* Author : Shreyash Vardhan */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b) for(int i=a;i<b;i++)
#define FORE(a,b) for(int i=a;i<=b;i++)
#define vi vector<int>
#define vl vector<ll>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);
#define mod 1e9=7
#define N 100005
#define pinf INT_MAX
#define ninf INT_MIN
//Adjacency list representation of graph
vector<int> gr[N];
// dfs function 
void dfs(int src, int par){
	cout<<src<<" ";
	for(auto x:gr[src]){
		if(x!=par){
			// call dfs again as x as current node and src as parent
			dfs(x,src);
		}
	}
}
int main(){
	//input no. vertex and no. of edges
	int n,m;
	cin>>n>>m;
	while(m--){
		//input edges
		int u,v;
		cin>>u>>v;
		// build a bidirectional graph
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	// call dfs function from node 0 and parent as -1
	dfs(0,-1);
}






