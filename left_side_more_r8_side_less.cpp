//Array 8)
#include <bits/stdc++.h> 
using namespace std; 
  
int findElement(int arr[], int n) 
{ 
    //Write your code here 
    int left[n];
    left[0] = INT_MIN;

    //creating left array
    for(int i=1;i<n;i++){
        left[i]=(arr[i-1]>left[i-1])?arr[i-1]:left[i-1];
    }

    int right=INT_MAX;
    
    //nt creating r8 array just compare and then chng r8 variable
    for(int i=n-1;i>=0;i--){
        if(left[i]<arr[i] && right>arr[i])
            return i;
        right=(arr[i+1]<right)?arr[i-1]:right;
    }

    return -1; 
} 
  

int main() 
{ 
    int arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9}; 
    int n = sizeof arr / sizeof arr[0]; 
    cout << "Index of the element is " << findElement(arr, n); 
    return 0; 
} 

/* Try more Inputs

findElement(array, length_of_array)


case1: 
actual = findElement([5, 1, 4, 3, 6, 8, 10, 7, 9],9)
expected = 4

case2: 
actual = findElement([6, 2, 5, 4, 7, 9, 11, 8, 10],9)
expected = 4

case3:
actual = findElement([5, 1, 4, 4],4)
expected = -1

*/