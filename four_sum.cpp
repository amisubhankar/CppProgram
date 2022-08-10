//hashing 5)
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class point{
    public:
        int x;
        int y;
    public:
        point(int x,int y){
            this->x=x;
            this->y=y;
        }
};

bool fourSum(int arr[],int n,int target){
    map<int,vector<point>> mp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int partSum=target-(arr[i]+arr[j]);
            //chk partsum already exist or not in map
            if(mp.find(partSum)!=mp.end()){
                //chk for uniqueness
                for(point obj:mp[partSum]){
                    if( obj.x!=i && obj.y!=j ){
                        cout<<"Found 4 points;;"<<endl;
                        cout<<obj.x<<","<<obj.y<<","<<i<<","<<j;
                        return true;
                    }
                }
            }
            //not exist so add to map
            point obj(i,j);
            mp[arr[i]+arr[j]].push_back(obj);
        }
    }
    return false;
}

int main(){
    int arr[]={1,5,1,2,6,0};
    int target=7;

    if(!fourSum(arr,sizeof(arr)/sizeof(int),target)){
        cout<<"Not found";
    }
}