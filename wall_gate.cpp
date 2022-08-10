//graph 7)
#include<iostream>
#include<queue>
#define INF 1001
using namespace std;

class myQueue{
    public:
    int i;
    int j;
    int d;
    public:
    myQueue(int i,int j,int d){
        this->i=i;
        this->j=j;
        this->d=d;
    }
};

bool fillUp(int arr[4][4],int i,int j,int d){
    if(i<0 || j<0 || i>3 || j>3 || arr[i][j]==-1 || arr[i][j]==0)   return false;
    else if(arr[i][j]==INF || d+1<arr[i][j]){
        arr[i][j]=d+1;
        return true;
    }
    return false;
}

void fillArray(int arr[4][4],queue<myQueue> qu){
    while(!qu.empty()){
        myQueue obj=qu.front();
        qu.pop();
        if(fillUp(arr,obj.i-1,obj.j,obj.d)){
            myQueue obj1(obj.i-1,obj.j,obj.d+1);
            qu.push(obj1);
        }
        if(fillUp(arr,obj.i,obj.j+1,obj.d)){
            myQueue obj1(obj.i,obj.j+1,obj.d+1);
            qu.push(obj1);
        }
        if(fillUp(arr,obj.i+1,obj.j,obj.d)){
            myQueue obj1(obj.i+1,obj.j,obj.d+1);
            qu.push(obj1);
        }
        if(fillUp(arr,obj.i,obj.j-1,obj.d)){
            myQueue obj1(obj.i,obj.j-1,obj.d+1);
            qu.push(obj1);
        }
    }
}

int main(){
    int arr[4][4]={
        {INF,  -1,  0,  INF},
        {INF, INF, INF,  -1},
        {INF,  -1, INF,  -1},
        {0,  -1, INF, INF}
        };

    queue<myQueue> qu;
    //insert all the window
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]==0)
            {
                myQueue obj(i,j,0);
                qu.push(obj);
            }
        }
    }
    fillArray(arr,qu);  
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}
