//Array 10)
#include<iostream>
#include<vector>

using namespace std;

int totalCandy(vector<int> rating){
    vector<int> left(rating.size(),1);
    vector<int> right(rating.size(),1);

    //traversing left to right
    for(int i=1;i<rating.size();i++){
        if(rating[i]>rating[i-1])
            left[i]=left[i-1]+1;
    }

    //traversing right to left
    for(int i=rating.size()-2;i>=0;i--){
        if(rating[i]>rating[i+1])
            right[i]=right[i+1]+1;
    }

    int sum=0;
    //finding max and sum up
    for(int i=0;i<rating.size();i++){
        sum+=max(left[i],right[i]);
    }

    return sum;

}

int main(){
    vector<int> rating={1,2,1,5};

    cout<<"Minimum candy : "<<totalCandy(rating);

    return 0;
}