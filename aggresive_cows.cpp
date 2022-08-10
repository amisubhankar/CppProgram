#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> v={2,1,9,4,8};
    sort(v.begin(),v.end());

    int n=v.size();
    int cows=3;

    int low=v[0];
    int high=v[n-1]-v[0];
    int mid;;
}