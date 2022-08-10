//get Min element at any point of time in O(1)
#include<iostream>
#include<stack>
using namespace std;

stack<int> push(stack<int> st,int i,int &min){
    if(st.empty()){
        st.push(i);
        min=i;
    }
    else if(i<min){
        st.push(2*i-min);
        min=i;
    }
    else{
        st.push(i);
    }
    cout<<"Push("<<i<<") -- Min= "<<min<<" "<<st.top()<<endl;
    return st;
}

stack<int> pop(stack<int> st,int &min){
    //have to modify when st has only one element and removal of that means min=0
    if(st.top()<min){
        min=2*min-st.top();
        cout<<"pop("<<(st.top()+min)/2<<")";
    }
    else{
        cout<<"pop("<<st.top()<<")";
    }
    st.pop();
    cout<<" min= "<<min<<endl;

    return st;
}

int main(){
    int arr[]={3,5,2,1,1,-1};
    int n=sizeof(arr)/sizeof(int);
    int min=INT8_MAX;
    stack<int> st;
    for(int i:arr)
        st=push(st,i,min);
    cout<<endl;
    for(int i=0;i<n;i++)
        st=pop(st,min);
}