//Array 4)
#include <iostream> 
using namespace std; 
  
/*My soln::
void moveZeroToTheEnd(int array1[], int n) 
{ 
   int a=0,b=1;
   while(b<n){
       //swap for case 0 1
       if(array1[a]==0 && array1[b]!=0){
           int temp=array1[a];
           array1[a]=array1[b];
           array1[b]=temp;
           
           a++;
           b++;
       }
       //for case 0 0
       else if(array1[a]==0 && array1[b]==0)
            b++;
        //for case 1 0 || 1 1
        else{
            a++;
            b++;
        }
   }
}*/ 
  

void moveZeroToTheEnd(int array1[], int n){
    int ind=0;//ind always points to an zero where to put the non-zero

    //if i=0 skip else put at ind
    for(int i=0;i<n;i++){
        if(array1[i]!=0)
            array1[ind++]=array1[i];
    }

    //now put ind to n 0s
    while(ind<n)
        array1[ind++]=0;
}

int main() 
{ 
    int array1[] = {1, 0, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9}; 
    int n = sizeof(array1) / sizeof(array1[0]); 
    moveZeroToTheEnd(array1, n); 
    cout << "Result is :\n"; 
    for (int i = 0; i < n; i++) 
        cout << array1[i] << " "; 
    return 0; 
} 

/* Try more Inputs
case1:
 actual = MoveZeroToEnd([1,3,0,0,4,0,9],7)
 expected = [1,3,4,9,0,0,0]
 
case2:
actual = MoveZeroToEnd([0,1,0,3,12],5)
expected = [1,3,12,0,0]

case3:
actual = MoveZeroToEnd([0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9],13)
expected = [1,9,8,4,2,7,6,9,0,0,0,0,0]

*/