#include<iostream>
#include<vector>
#define n 4
using namespace std;


//this isSafe() take O(n)
bool isSafe(int row,int col,vector<string> board){
    int drow=row;
    int dcol=col;

    //check '\' -- leftUpper
    while(col>=0 && row>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }

    row=drow;
    col=dcol;
    //check for left
    while(col>=0 && row>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }

    row=drow;
    col=dcol;
    //check '/' -- leftLower
    while(col>=0 && row<n){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }

    return true;
}

//this function take O(n) to check each col and for each col check all row
//so again take O(n)
//so TC-> O(n)*O(n) = O(n2) 
void nqueen(vector<string> &board,int col,vector<vector<string>> &ans){
    //base cond
    //when all the queens are placed
    if(col==n){
        ans.push_back(board);
        return;
    }

    //check at all row for a particular col
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board)){
            //placed queen at that pos
            board[row][col]='Q';
            //call for next column
            nqueen(board,col+1,ans);
            //"bactracking step" -- whn came back frm function undo prev work
            board[row][col]='.';
        }
    }
}

int main(){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
        board[i]=s;
    
    nqueen(board,0,ans);
    for(int i=0;i<ans.size();i++){
        for(string str: ans[i]){
            cout<<str<<endl;        
        }
        cout<<"---------------"<<endl;
    }
}


/*
//this efficient approach it takes O(n)
void nqueen(vector<string> &board,vector<int> &leftUpper,vector<int> &left,vector<int> &leftLower,int col,vector<vector<string>> &ans){
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(leftUpper[(n-1) + (col-row)]==0 && left[row]==0 && leftLower[col+row]==0){
            board[row][col]='Q';
            leftUpper[(n-1) + (col-row)]=1;
            left[row]=1;
            leftLower[row+col]=1;
            nqueen(board,leftUpper,left,leftLower,col+1,ans);
            //bactracking steps
            board[row][col]='.';
            leftUpper[(n-1) + (col-row)]=0;
            left[row]=0;
            leftLower[row+col]=0;
        }
    }
}

int main(){
    vector<vector<string>> ans;
    //created 3 hash
    vector<int> leftUpper(2*n-1,0);
    vector<int> left(n,0);
    vector<int> leftLower(2*n-1,0);

    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
        board[i]=s;
    
    nqueen(board,leftUpper,left,leftLower,0,ans);
    for(int i=0;i<ans.size();i++){
        for(string str: ans[i]){
            cout<<str<<endl;        
        }
        cout<<"---------------"<<endl;
    }
}
*/