#include<iostream>
using namespace std;

//using extra space
//TC->O(n) and SC->O(n)
int maxDiff(int arr[], int n) {
    int leftMin[n],rightMax[n];

    //constructing rightMax
    rightMax[n-1]=n-1;
    for(int i=n-2;i>=0;i--){
        rightMax[i]=arr[rightMax[i+1]]>arr[i]?rightMax[i+1]:i;
    }

    //constructing leftMin
    leftMin[0]=0;
    for(int i=1;i<n;i++){
        leftMin[i]=arr[leftMin[i-1]]<arr[i]?leftMin[i-1]:i;
    }

    //i=right max array
    //j=leftmin array
    int i=0,j=0;
    int maxDist=-1;
    while(i<n && j<n){
        if(arr[leftMin[j]]<=arr[rightMax[i]]){
            maxDist=max(maxDist,rightMax[i]-leftMin[j]);
            i++;
        }
        else
            j++;
    }

    return maxDist;
}

//TC->O(n) and SC->O(1)
int maxDiff2(int arr[], int n) {
    int i=0,j=n-1;
    while(1){
        //when odd array loop break frm here
        if(arr[j]>=arr[i])
            return j-i;
        //when even array loop break frm here
        else if((arr[j-1]>=arr[i]) || (arr[j]>=arr[i+1]))
            return j-i-1;
        else{
            i++;
            j--;
        }
    }
}

int main() {
   int array[] = { 35, 33, 32, 3, 2, 70, 31, 29, 1 };
   int n = sizeof(array) / sizeof(array[0]);
   cout<<"The maximum value of |arr[i] - arr[j]| + |i-j| is "<<maxDiff2(array, n);
   return 0;
}
/* Try more Inputs
case1:
actual = findDiff([35, 9, 12, 3, 2, 70, 31, 33, 1])
expected = 6

case2:
actual = findDiff([1, 2, 3, 4, 5, 6])
expected = 5

case3:
actual = findDiff([9, 2, 3, 4, 5, 6, 7, 8, 18, 0])
expected = 8

case4:
actual = findDiff([6, 5, 4, 3, 2, 1])
expected = -1

*/