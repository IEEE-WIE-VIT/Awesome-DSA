/* Author: Shreyash Vardhan */
/*Shortest path faster algorithm is used to ccalulate single source shortest path in a weighted directed graph. It is an improvement of Belmann
Ford algorithm . However worst case time complexity is same as Belmann Ford algorithm O(V*E) but average case time complexity is O(E)
*/ 
#include<bits/stdc++.h>
using namespace std;
int main(){
	// Edge list representation of weighted graph
	vector<pair<int,int>> gr[10000];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		--a,--b;
		gr[a].push_back({b,c});
	}
	queue<int> q;
	int dist[n];
	for(int i=0;i<n;i++){
		dist[i]=INT_MAX;
	}
	dist[0]=0;
	q.push(0);
	bool inq[n];
	for(int i=0;i<n;i++){
		inq[i]=0;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=1;
		for(auto x:gr[u]){
			int node=x.first;
			int wt=x.second;
			if(dist[node]>dist[u]+wt)
			{
				dist[node]=dist[u]+wt;
				if(!inq[node]){
				q.push(node);
				inq[node]=1;
				
			}
		}
	}
}
for(int i=0;i<n;i++){
	cout<<dist[i]<<" ";
}
}
