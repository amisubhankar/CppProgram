
#include<iostream> 
#include<climits> 
#include<cstdlib> 
using namespace std; 
  
int partition(int array1[],int low,int high);
int randomPartition(int array1[],int low,int high);
void swap(int *a,int *b);
  
// This function returns k'th smallest element in array1[l..r] using  
int findKthSmallest(int array1[], int low, int high, int k) 
{ 
    int index=randomPartition(array1,low,high);

    if(index==k-1)
        return array1[index];
    //my required position is less then index so go left
    if(k-1<index)
        return findKthSmallest(array1,low,index-1,k);
    //my required position is more then index so go right
    return findKthSmallest(array1,index+1,high,k);
} 

//partition the array and return pivot's index
int partition(int array1[],int low,int high){
    //j is incementing 
    //i points to 1st greater element
    int i,j;
    int pivot=array1[high];
    for(i=low,j=low;j<high;j++){
        if(array1[j]<=pivot){
            swap(&array1[i],&array1[j]);
            i++;
        }
    }
    swap(&array1[i],&array1[high]);
    return i;
}

//select a random index as pivot and then call partition()
int randomPartition(int array1[],int low,int high){
    //1st check no. of elements in current partition
    int n=high-low+1;
    int pivot=rand()%n;
    swap(&array1[low+pivot],&array1[high]);
    return partition(array1,low,high);
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
  
  
int main() 
{ 
    int array1[] = {54, 26, 93, 17, 77, 31, 44,20,55}; 
    int n = sizeof(array1)/sizeof(array1[0]), k = 3; 
    cout << "K'th smallest element is " << findKthSmallest(array1, 0, n-1, k); 
    return 0; 
}


/* Try more Inputs
case 1: 
actual = findKthElement([7, 10, 4, 3, 20, 15],0,5,3)
expected = 7

case2: 
 actual = findKthElement([7, 10, 4, 3, 20, 15],0,5,4)
 expected = 10
 
case3: 
actual = findKthElement([12, 3, 5, 7, 19],0,4,2)
expected = 5
*/