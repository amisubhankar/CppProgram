//graph 2)
#include<iostream>
#include<vector>
using namespace std;
vector<int> graph[4];

void addEdge(int u,int v){
    graph[u].push_back(v);
}

void DFS(int i,bool *visited){
    visited[i]=true;
    for(int u:graph[i]){
        if(!visited[u])
            DFS(u,visited);
    }
}

bool isConnected(){
    for(int i=0;i<graph->size();i++){
        bool visited[4]={false};
        DFS(i,visited);
        for(bool ch:visited){
            if(!ch) return false;
        }
    }
    return true;
}

int main(){
    addEdge(0,1);
    addEdge(1,0);
    addEdge(1,3);
    addEdge(2,0);
    addEdge(3,0);
    addEdge(3,2);

    cout<<isConnected();
}