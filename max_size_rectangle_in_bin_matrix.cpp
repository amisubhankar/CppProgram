#include<iostream>
#include<stack>
using namespace std;

int calcMaxArea(int arr[],int n){
    stack<int> st;
    int maxArea=INT8_MIN;
    int i;
    for(i=0;i<n;i++){
        if(st.empty() || arr[i]>arr[st.top()])
            st.push(i);
        else{
            while(!st.empty() && arr[i]<arr[st.top()]){
                //i-> r8 smallest || top-1 -> lft smallest
                int topE=st.top();
                st.pop();
                int area=(st.empty())?arr[topE]*(i-0):arr[topE]*(i-st.top()-1);
                maxArea=max(maxArea,area);
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        int topE=st.top();
        st.pop();
        int area=(st.empty())?arr[topE]*(i-0):arr[topE]*(i-st.top()-1);
        maxArea=max(maxArea,area);
    }

    return maxArea;
}

int main(){
    int mat[4][4]={
                    {0,1,1,0},
                    {0,1,1,0},
                    {1,1,0,0},
                    {0,0,1,0}
                  };
    int arr[4];
    int maxArea=INT8_MIN;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(mat[i][j]==1 && i!=0){
                mat[i][j]+=mat[i-1][j];
            }
        }
        maxArea=max(calcMaxArea(mat[i],4),maxArea);
    }
    cout<<maxArea;


}