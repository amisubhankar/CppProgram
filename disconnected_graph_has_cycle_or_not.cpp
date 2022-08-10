//graph 3)
//for disconnected graph BFS & DFS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> graph[],int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

bool BFS(int s,bool *visited,vector<int> graph[]){
    //int,int -- vertex,parent
    queue<pair<int,int>> qu;
    qu.push({s,-1});
    visited[s]=true;
    while(!qu.empty()){
        int v=qu.front().first;
        int par=qu.front().second;
        qu.pop();
        for(int u:graph[v]){
            if(!visited[u]){
                visited[u]=true;
                qu.push({u,v});
            }
            else if(u!=par){
                return true;
            }
        }
    }
    return false;
}
bool DFS(int v,int par,bool *visited,vector<int> graph[]){
    visited[v]=true;
    for(int u:graph[v]){
        if(!visited[u]){
            if(DFS(u,v,visited,graph))  return true;
        }
        else if(u!=par){
            return true;
        }
    }
    return false;
}

int main(){
    int vertex=5;
    
    vector<int> graph[vertex+1];
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,2,4);
    addEdge(graph,2,5);
    addEdge(graph,5,4);
    
    bool visited[vertex+1]={false};
    // //BFS approach
    // for(int i=1;i<=vertex;i++){
    //     if(!visited[i]){
    //         if(BFS(i,visited,graph)){
    //             cout<<"Cycle Exist!!";
    //             exit(0);
    //         }
    //     }
    // }
    // cout<<"No Cycle";

    //DFS approach
    for(int i=1;i<=vertex;i++){
        if(!visited[i]){
            if(DFS(i,-1,visited,graph)){
                cout<<"Cycle Exist!!";
                exit(0);
            }
        }
    }
    cout<<"No Cycle";
}