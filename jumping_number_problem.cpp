//graph 8)
#include<iostream>
#include<queue>
using namespace std;

void generateJumpingNumber(queue<int> qu,int n){
    while(!qu.empty()){
        int num=qu.front();
        qu.pop();
        cout<<num<<" ";
        //as if 0 is last digit then 0-1 = -1
        if(num%10!=0){
            int num2=(num*10)+((num%10)-1);
            if(num2<=n) qu.push(num2);    
        }
        //if 9 is last digit 9+1=10
        if(num%10!=9){
            int num1=(num*10)+((num%10)+1);
            if(num1<=n) qu.push(num1);
        }
    }
}

int main(){
    int n=1000;
    queue<int> qu;
    //insert 1 to 9
    for(int i=1;i<=9;i++)
        qu.push(i);
    generateJumpingNumber(qu,n);
}