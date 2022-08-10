//Graph 12)
//DFS approach
#include<iostream>
#include<vector>
#include<stack>
#define size 6
using namespace std;

vector<int> graph[size];

void add(int u,int v){
    graph[u].push_back(v);
}

void DFS(int u,bool *visited,stack<int> &stk){
    visited[u]=true;
    for(int v:graph[u]){
        if(!visited[v]){
            DFS(v,visited,stk);
        }
    }
    stk.push(u);
}

void topologicalSorting(){
    bool visited[size]={false};
    stack<int> stk;
    for(int i=0;i<size;i++){
        if(!visited[i]){
            DFS(i,visited,stk);
        }
    }
    //print sorted vertices
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
}

int main(){
    add(5,0);
    add(5,2);
    add(4,0);
    add(4,1);
    add(2,3);
    add(3,1);

    topologicalSorting();
}