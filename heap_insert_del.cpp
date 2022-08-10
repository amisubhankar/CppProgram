//hashing 1)
//implementing min heap
//insertion & heapify up
//deletion & heapify down
#include<iostream>
#include<vector>
using namespace std;

vector<int> heapifyUp(vector<int> arr,int index){
    int parent=(index-1)/2;

    if( arr[parent] > arr[index] ){
        swap(arr[index],arr[parent]);
        arr=heapifyUp(arr,parent);
    }

    return arr;
}

vector<int> heapifyDown(vector<int> arr,int index){
    int l=(2*index)+1;
    int r=(2*index)+2;
    int smallest=index;

    if(l<arr.size() && arr[l]<arr[smallest])
        smallest=l;
    if(r<arr.size() && arr[r]<arr[smallest])
        smallest=r;

    if(smallest!=index){
        swap(arr[index],arr[smallest]);
        arr=heapifyDown(arr,smallest);
    }

    return arr;

}

vector<int> insert(vector<int> arr,int item){
    arr.push_back(item);
    arr=heapifyUp(arr,arr.size()-1);

    return arr;
}

vector<int> del(vector<int> arr){
    cout<<arr[0]<<" ";
    arr[0]=arr.back();
    arr.pop_back();
    arr=heapifyDown(arr,0);

    return arr;
}

int main(){
    int a[]={10,4,11,12,2,9,7,5};
    vector<int> arr;
    for(int item:a){
        arr=insert(arr,item);
    }
    
    while(arr.size()!=0){
        arr=del(arr);
    }
}