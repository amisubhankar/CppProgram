//Stack/Queue 
//5
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
    int arr[]={6,2,5,4,5,1,6};
    int n=sizeof(arr)/sizeof(int);

    cout<<calcMaxArea(arr,n);
}