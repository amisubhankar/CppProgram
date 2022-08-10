//Array 14)
#include<iostream>
#include<vector>
using namespace std;

int median(vector<int> arr1,vector<int> arr2){
    
    //arr1 should always have lesser elements
    if(arr1.size()>arr2.size())
        median(arr2,arr1);

    int n1=arr1.size();
    int n2=arr2.size();

    //high=short length array's length
    int low=0,high=n1;

    while(low<=high){
        int cut1=(low+high)/2;
        //if n1+n2 is even then ok but if odd add 1 to find out left portion
        int cut2=(n1+n2+1)/2-cut1;

        int l1= (cut1==0)?INT32_MIN:arr1[cut1-1];
        int l2= (cut2==0)?INT32_MIN:arr2[cut2-1];
        int r1= (cut1==n1)?INT32_MAX:arr1[cut1];
        int r2= (cut2==n2)?INT32_MAX:arr2[cut2];

        // cout<<l1<<"-"<<r1<<endl;
        // cout<<l2<<"-"<<r2<<endl;

        if(l1<=r2 && l2<=r1){//right partition
            if((n1+n2)%2==0)//for even number of elements
                return (max(l1,l2)+min(r1,r2))/2;
            else//for odd no. of elements
                return max(l1,l2);
        }
        //as l1 is more decrease l1 by picking less element
        //or cut at previous portion
        else if(l1>r2)
            high=cut1-1;
        //as l2 is more decrease l2 and increase r1 by picking more element
        //or cut at next portion       
        else
            low=cut1+1;
    }
}

int main(){
    vector<int> arr1={7,12,14,15};
    vector<int> arr2={1,2,3,4,9};

    cout<<"Median of two array: "<<median(arr1,arr2);

    return 0;
}