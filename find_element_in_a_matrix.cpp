//in this program row is sorted as well as col is also sorted..
#include<iostream>
using namespace std;
#define size 4

bool findElement(int matrix[][size],int n,int item){
    int i=0;
    int j=n-1;
    while (i<n && j>=0)
    {
        if(matrix[i][j]==item)
            return true;
        //if value is less then come left side 
        //so decrement col
        else if(item<matrix[i][j])
            j--;
        //if value is more then go down
        //so increment row
        else    
            i++;
    }

    return false;
    
}

int main(){
    int matrix[][size]={ { 10, 20, 30, 40 }, 
                      { 15, 25, 35, 45 }, 
                      { 27, 29, 37, 48 }, 
                      { 32, 33, 39, 50 } };
    
    if(findElement(matrix,size,39)){
        cout<<"Element found";
    }
    else{
        cout<<"Not Found";
    }
}