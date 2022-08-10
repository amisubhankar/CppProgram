//Array 5)
#include <bits/stdc++.h> 
using namespace std; 
  
// Returns minimum number of jumps 
// to reach array1[n-1] from array1[0] 
int minJumpToReachEnd(int array1[], int n) 
{ 
  
    //Practise Yourself : Write your code Here
    int jump=1;
    int a=array1[0];
    int b=array1[0];

    //when array has single element of no element
    //if single element then no jump is required as that is the end. so jump=0
    if(n<=1)
        return 0;
    
    for(int i=1;i<n;i++){
        //reached last pos
        if(i==n-1)
            return jump;
        a--;
        b--;
        //not possible to jump moment
        if(b==0 && array1[i]==0)
            return -1;
            
        if(array1[i]>b)
            b=array1[i];
        
        if(a==0){
            jump++;
            a=b;
        }
    }
    return jump; 
} 
  

int main() 
{ 
    int array1[] = { 3,2,1,0,4}; 
    int size = sizeof(array1) / sizeof(int); 
  
    cout << minJumpToReachEnd(array1, size); 
    return 0; 
} 

/* Try more Inputs
case 1: 
actual = minJumpToReachEnd([1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9],11)
expected = 3

case2: 
 actual = minJumpToReachEnd([1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],10)
 expected = 10
 
case3: 
actual = minJumpToReachEnd([3,2,1,0,4],5)
expected = -1
Jump not possible
*/