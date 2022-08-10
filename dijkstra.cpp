//Graph 13)
#include<iostream>
#include<vector>
#include<queue>
#define n 5
using namespace std;
//graph format -- {vertex,weight}
vector<pair<int,int>> graph[n+1];

void add(int v,int u,int w){
    graph[v].push_back({u,w});
}
void dijkstra(int source,vector<int> &dist){
    //priority queue format -- {distance,node}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({dist[source],source});
    
    while(!pq.empty()){
        int d=pq.top().first;
        int v=pq.top().second;
        pq.pop();

        for(pair<int,int> p: graph[v]){
            //if current dist is small than prev dist change the dist array
            if(dist[p.first]>d+p.second){
                dist[p.first]=d+p.second;
                pq.push({dist[p.first],p.first});
            }
        }
    }
}

int main(){
    add(1,2,2);
    add(1,4,1);
    add(2,5,5);
    add(2,3,4);
    add(4,3,3);
    add(3,5,1);

    int source=2;
    vector<int> dist(n+1,INT8_MAX);
    dist[source]=0;
    dijkstra(source,dist);

    for(int d:dist){
        cout<<d<<" ";
    }
}