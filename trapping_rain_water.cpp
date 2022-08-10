#include <iostream> 
using namespace std; 

//for this soln TC-> O(n) SC->O(n)  
int storeWater(int array1[], int n) 
{ 
    int lmax[n],rmax[n];

    //construct lmax
    lmax[0]=array1[0];
    for(int i=1;i<n;i++){
        lmax[i]=max(lmax[i-1],array1[i]);
    }

    //construct rmax
    rmax[n-1]=array1[n-1];
    for(int i=n-2;i>=0;i--){
        rmax[i]=max(rmax[i+1],array1[i]);
    }

    //count trapping water
    int water=0;
    for(int i=0;i<n;i++){
        water+=min(lmax[i],rmax[i])-array1[i];
    }

    return water;
} 

//for this soln TC-> O(n) SC->O(1)  
int storeWater2(int array1[],int n){
    int l=0,r=n-1;
    int lmax=0,rmax=0;
    int water=0;

    while(l<=r){
        //making sure same or greater bar present on r8 side
        if(array1[l]<=array1[r]){
            //present left max bar is lower so update
            if(array1[l]>=lmax)
                lmax=array1[l];
            //present lmax is higher so add trapped water
            else
                water+=(lmax-array1[l]);
            
            l++;
        }
        //array1[l]>array1[r]
        //making sure at left side >= bar is prsnt
        else{
            if(array1[r]>=rmax)
                rmax=array1[r];
            else
                water+=rmax-array1[r];

            r--;
        }
    }

    return water;
}
  
int main() 
{ 
    int array1[] = { 0,1,0,2,1,0,1,3,2,1,2,1 }; 
    int n = sizeof(array1) / sizeof(array1[0]); 
    cout << "Maximum water that can be stored is "
         << storeWater2(array1, n); 
    return 0; 
}

/* Another test case
int array1[] = { 5,3,4,6,3,6 };
Expected = 6
*/ 