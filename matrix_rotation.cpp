#include<iostream>
using namespace std;
#define size 4

void matrixRotation(int matrix[][size],int n){
    //i is going layer by layer if size is 4 layer=2
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-1-i;j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[n-1-j][i];
            matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
            matrix[j][n-1-i]=temp;
        }
    }
}

int main(){
    int matrix[][size]={ { 1, 2, 3, 4 }, 
                         { 5, 6, 7, 8 }, 
                         { 9, 10, 11, 12 }, 
                         { 13, 14, 15, 16 } };

    
    
    matrixRotation(matrix,size);

    cout<<"After rotation: "<<endl;

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
            cout<<matrix[i][j]<<"\t";
        cout<<endl;
    }
}