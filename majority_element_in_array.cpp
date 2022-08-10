#include <iostream>
 
// Function to return majority element present in given array
int majorityElement(int arr[], int n)
{
    int candidate=arr[0];
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[i]==candidate){
            //increase the count
            count++;
        }
        else{
            //found a pair so decrease count
            count--;
        }

        if(count==0){
            //probably the new Majority element candidate
            candidate=arr[i];
            count=1;
        }
    }

    return candidate;
}
 
int main(void)
{
    // Assumtion - valid input (majority element is present)
    int arr[] = { 3, 8, 3, 3, 1, 2, 2, 2, 2, 2, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);
    
    //if it's not sure whether the majority element is present or not 
    //after getting the element frm funtion check once if it appears
    //more than [n/2] times or not.
    printf("Majority element is %d", majorityElement(arr, n));
 
    return 0;
}