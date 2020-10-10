#include <iostream>
using namespace std;
#include<queue>
#include<map>
#include<list>

class graph{
    public:
    map<int,list<int>>mp;
    int *visited;
    
    graph(int n){
        visited = new int[n];
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
    }

    void add_edge(int x,int y){
        mp[x].push_back(y);
    }

    void dfs(int s,int *visited,list<int>&topologicalorder){ //ensure to pass by ref
        visited[s]=1;
        for(auto nbr:mp[s]){
            if(!visited[nbr]){
                dfs(nbr,visited,topologicalorder);
            }
        }
        topologicalorder.push_front(s);
        return;

    }

    void dfs_assist(){
        
        list<int> topologicalorder;
        for(auto it:mp){
            int node = it.first;
            if(!visited[node]){
                dfs(node,visited,topologicalorder);
            }
        }
        for(auto it:topologicalorder){
            cout<<it<<" ";
        }
        
    }


};

int main() {
    graph g(6);
    g.add_edge(0,0);
    g.add_edge(1,0);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(4,5);
    g.add_edge(5,1);
    g.dfs_assist();
}
