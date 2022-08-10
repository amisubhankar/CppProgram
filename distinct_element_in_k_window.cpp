#include<iostream>
#include<map>


using namespace std;

void countUniqueInK(int arr[],int n,int k){

    if(k>n){
        cout<<"Window size is more than array length";
        return;
    }
    int i=0,j=0;
    map<int,int> mp;
    int distinct_count=0;
    while(j<k){
        //new element to push
        if(mp[arr[j]]==0){
            distinct_count++;
        }
        mp[arr[j]]++;
        j++;
    }
    cout<<distinct_count<<" ";

    while(j<n){
        //delete i from window.....
        //this element is occured just one time so 
        //in window shifting delete this element from distinct_count
        if(mp[arr[i]]==1){
            distinct_count--;
            mp.erase(arr[i]);
        }
        else
            mp[arr[i]]--;
        
        i++;

        //adding j to window
        //new element to push
        if(mp[arr[j]]==0){
            distinct_count++;
            mp[arr[j]]++;
        }
        //old one just add 1 to its frequency
        else
            mp[arr[j]]++;

        j++;
        cout<<distinct_count<<" ";
    }
    
}

int main(){
    int arr[]={1,2,1,3,4,3};
    int n=sizeof(arr)/sizeof(int);

    countUniqueInK(arr,n,3);
    
}