/*Author : Shreyash Vardhan */
// Program to check whether a graph is bipartite or not
#include<bits/stdc++.h>
using namespace std;
const int v=100001;
vector<int> m[v];
int visit[v];
bool bip=0;
// function build to build the undirected graph  
void build(int a,int b){
	m[a].push_back(b);
	m[b].push_back(a);
}
void dfs(int src,int par,int col){
	visit[src]=col;
	for(auto child: m[src]){
		if(!visit[child]){
			dfs(child,src,3-col);
			
		}else if(child!=par and col==visit[child]){
			bip=1;
		}
	}
}
int main(){
	build(1,2);
	build(2,3);
	build(3,1);
	build(3,4);
	build(1,4);
	build(5,1);
	dfs(1,-1,1);
	if(bip){
		cout<<"Not Bipartite"<<endl;
	}else{
		cout<<"Bipartite"<<endl;
	}
}
