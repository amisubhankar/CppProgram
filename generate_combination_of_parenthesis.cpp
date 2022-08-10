#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void generate(char arr[],int index,int n,int open,int close){
    if(close==n){
        //print ans
        for(int i=0;i<index;i++)
            cout<<arr[i];
        cout<<endl;
        return;
    }
    //1st try to put close braces
    if(open>close){
        arr[index]=')';
        generate(arr,index+1,n,open,close+1);
    }
    //try to put open braces
    if(open<n){
        arr[index]='(';
        generate(arr,index+1,n,open+1,close);
    }
}

int main(){
    char arr[7];
    generate(arr,0,3,0,0);
}