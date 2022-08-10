//hashing 3)
#include<iostream>
#include<vector>
using namespace std;

class MinHeapNode{
    public:
        int i;
        int j;
        int value;
    public:
        MinHeapNode(int i,int j,int value){
            this->i=i;
            this->j=j;
            this->value=value;
        }
};

vector<MinHeapNode> heapifyUp(vector<MinHeapNode> vc,int index){
    int parent=(index-1)/2;
    if(vc[parent].value>vc[index].value){
        swap(vc[parent],vc[index]);
        vc=heapifyUp(vc,parent);
    }

    return vc;
}

vector<MinHeapNode> heapifyDown(vector<MinHeapNode> vc, int index){
    int L=2*index+1;
    int R=2*index+2;
    int smallest=index;

    if(L<vc.size() && vc[L].value<vc[smallest].value)
        smallest=L;
    if(R<vc.size() && vc[R].value<vc[smallest].value)
        smallest=R;
    
    if(smallest!=index){
        swap(vc[index],vc[smallest]);
        vc=heapifyDown(vc,smallest);
    }

    return vc;
}

void mergeKSortedArrays(vector<vector<int>> arr,int k){
    vector<MinHeapNode> vc;

    //insert 1st coluumn and Min Heapify them
    for(int i=0;i<k;i++){
        MinHeapNode node(i,0,arr[i][0]);
        vc.push_back(node);
        vc=heapifyUp(vc,vc.size()-1);
    }

    while(vc.size()>0){
        int lastJ=vc[0].j;
        int lastI=vc[0].i;
        cout<<vc[0].value<<" ";
        swap(vc[0],vc[vc.size()-1]);
        vc.pop_back();
        vc=heapifyDown(vc,0);

        lastJ++;
        //insert into vector only if there exist next element 
        if(lastJ < arr[lastI].size()){
            MinHeapNode node(lastI,lastJ,arr[lastI][lastJ]);
            vc.push_back(node);
            vc=heapifyUp(vc,vc.size()-1);
        }
    }
}


int main() 
{ 
   
    vector<vector<int>> arr =  {{1, 3, 5, 7}, 
                {2, 4, 6, 8}, 
                {0, 9, 10, 11}}; 
    int k = 3; 
  
    mergeKSortedArrays(arr, k); 
  
    return 0; 
} 