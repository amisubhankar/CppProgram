//given that array element's from 1-n
#include<iostream>
using namespace std;
 
// Function to find counts of all elements present in
// arr[0..n-1]. The array elements must be range from
// 1 to n
void findfrequency(int arr[],int n)
{
    //as item range is 1 to n
    //add with n+1 as it's not present
    int add=n+1;
    for(int i=0;i<n;i++){
        if(arr[i]>add){
            //what is the original value getting by the remainder
            int orgValue=arr[i]%add;
            arr[orgValue-1]+=add;
        }
        else{
            //actual index=arr[i]-1 on that I'm adding the n+1 val..
            //-1 because highest val is n which is not present as array index
            arr[arr[i]-1]+=add;
        }
    }
    // for(int i=0;i<n;i++)
    //     cout<<arr[i]<<" ";

    for(int i=0;i<n;i++){
        if(arr[i]>add){
            //getting frequency by dividing with n+1
            cout<<i+1<<" --> "<<arr[i]/add<<endl;
        }
    }

}
 

int main()
{
    int arr[] = {1, 2, 2, 1, 1, 2, 3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    findfrequency(arr,n);
    return 0;
}