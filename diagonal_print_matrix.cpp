//Array 11)
#include<iostream>
using namespace std;

void diagonalPrint(int matrix[][4],int row,int col){
    //print 1st half row wise 0 to row-1
    for(int k=0;k<row;k++){
        int i=k;
        int j=0;
        while(i>=0){
            cout<<matrix[i][j]<<" ";
            i--;
            j++;
        }
        cout<<endl;
    }

    //printing 2nd half col wise 1 to col-1
    for(int k=1;k<col;k++){
        int j=k;
        int i=row-1;
        while(j<col){
            cout<<matrix[i][j]<<" ";
            i--;
            j++;
        }
        cout<<endl;
    }
}
int main(){
    int matrix[4][4]={
                        {1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}
                    };
    diagonalPrint(matrix,4,4);
    return 0;

}