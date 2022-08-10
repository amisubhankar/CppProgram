#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void combSum(vector<int> arr,int index,vector<char> str,int target){
    if(target==0){
        for(int i=0;i<str.size();i++)
            cout<<str[i];
        cout<<endl;
        return;
    }
    for(int i=index;i<arr.size();i++){
        if(arr[i]<=target){
            str.push_back(arr[i]+48);
            target-=arr[i];
            combSum(arr,i,str,target);
            target+=arr[i];
            str.pop_back();
        }
        //if array is sorted use this else
        
        else
            return;
        
                
    }
}

int main(){
    vector<int> arr={1,2,3};
    int target=4;
    vector<char> str;
    combSum(arr,0,str,target);
    
}


/*
//combinational sum-II
//here arr can contain duplicates also
//op should be unique and each index can be taken just for once

void combSum(vector<int> arr,int index,vector<char> str,int target){
    if(target==0){
        for(int i=0;i<str.size();i++)
            cout<<str[i];
        cout<<endl;
        return;
    }
    int newitem=0;
    for(int i=index;i<arr.size();i++){
        //if arr[i] is same with arr[i-1] then don't take
        //means arr[i]==newitem
        if(arr[i]<=target && arr[i]!=newitem){
            newitem=arr[i];
            str.push_back(arr[i]+48);
            target-=arr[i];
            combSum(arr,i+1,str,target);
            target+=arr[i];
            str.pop_back();
        }
        //as arr is sorted
        else if(arr[i]>=target){
            return;
        }       
    }
}

int main(){
    vector<int> arr={10,1,2,7,6,1,5};
    sort(arr.begin(),arr.end());
    int target=8;
    vector<char> str;
    combSum(arr,0,str,target);  
}
*/