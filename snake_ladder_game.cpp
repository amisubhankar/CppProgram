//graph 6)
#include<iostream>
#include<queue>
using namespace std;

class myQueue{
    public:
        int cell;
        int d;
    public:
        myQueue(int cell,int d){
            this->cell=cell;
            this->d=d;
        }
};

int snakeLadder(int *moves,queue<myQueue> qu){
    bool visited[31]={false};
    visited[1]=true;
    while(1){
        myQueue obj=qu.front();
        qu.pop();
        for(int i=1;i<=6;i++){
            int c=obj.cell+i;
            int x=moves[c];
            //if this cell has snake or ladder..determine that
            while(x!=0){
                c=x;
                x=moves[c];
            }
            //check this cell is already visited or not
            if(!visited[c]){
                visited[c]=true;
                //current cell is our destiantion or not 
                if(c==30)   return obj.d+1;
                myQueue obj1(c,obj.d+1);
                qu.push(obj1);
            }
        }
    }
}

int main(){
    int moves[31]={0};
    //For ladder in cell i, it jumps to move[i]
    moves[3] = 22;
    moves[5] = 8;
    moves[11] = 26;
    moves[20] = 29;

    //For snake in cell i, it jumps to move[i]
    moves[27] = 1;
    moves[21] = 9;
    moves[17] = 4;
    moves[19] = 7;    

    queue<myQueue> qu;
    myQueue obj(1,0);
    qu.push(obj);
    cout<<snakeLadder(moves,qu);

    // int moves[37]={0};
    // moves[2]=15;
    // moves[14]=35;
    // moves[17]=13;
    // queue<myQueue> qu;
    // myQueue obj(1,0);
    // qu.push(obj);
    // cout<<snakeLadder(moves,qu);
    //op is 4
    
}