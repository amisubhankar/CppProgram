//hahing 4)
//assuming leftMax contains more element always
//and leftMax-rightMin= 0 || 1 else re-balancing
//priority_queue by default construct maxHeap
//for min Heap use below syntax or push(-1*item) and while fetch again -1*

#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> leftMax;
priority_queue<int, vector<int>, greater<int>> rightMin;

void add(int item){
    if(leftMax.size()==0 || item<leftMax.top()){
        leftMax.push(item);
    }
    else{
        rightMin.push(item);
    }
    
    if(leftMax.size()>1+rightMin.size()){
        rightMin.push(leftMax.top());
        leftMax.pop();
    }
    else if(rightMin.size()>leftMax.size()){
        leftMax.push(rightMin.top());
        rightMin.pop();
    }
    
}

int median(){
    if(leftMax.size()==rightMin.size())
        return (leftMax.top()+rightMin.top())/2;
    else
        return leftMax.top();
}

int main(){
    int arr[]={12,4,5,3,8,7};
    for(int item:arr){
        add(item);
        cout<<"insert("<<item<<") Median-->"<<median()<<endl;
    }
    
    return 0;
}