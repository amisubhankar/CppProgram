#include<iostream>
#include<stack>
using namespace std;

void findNextGreaterElement(int arr[],int n){
    int greater[n];
    stack<int> st;
    st.push(arr[n-1]);
    greater[n-1]=-1;
    for(int i=n-2;i>=0;i--){
        //till arr[i] is greater than st.top(), pop out
        while(!st.empty() && arr[i]>st.top())
            st.pop();
        //if st is empty then-> no NGE for current element
        //else NGE for current element is st.top() 
        greater[i]=(st.empty())?-1:st.top();
        st.push(arr[i]);
    }

    //print ans
    for(int i=0;i<n;i++)
        cout<<greater[i]<<" ";
}

int main(){
    int arr[]={12,8,6,10,7,9,11,1};
    int n=sizeof(arr)/sizeof(int);
    findNextGreaterElement(arr,n);
}