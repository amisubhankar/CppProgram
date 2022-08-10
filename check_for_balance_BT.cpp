#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;

public:
    Node(){}
    Node(int item){
        data=item;
        left=right=NULL;
    }
    int height(Node *root){
        if(root==NULL)
            return -1;
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        return 1+max(leftHeight,rightHeight);
    }

    //TC-> O(N^2)
    bool isBalance(Node *root){
        if(root==NULL)  return true;

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        if(abs(leftHeight-rightHeight)<=1 && isBalance(root->left) && isBalance(root->right))
            return true;
        return false;
    }

    //TC-> O(N)
    //by modifying height() function
    int isBalance2(Node *root){
        if(root==NULL)
            return 0;//if it returns -1 then it means tree is not balanced so return 0
        
        int leftHeight=isBalance2(root->left);
        if(leftHeight==-1)  return -1;

        int rightHeight=isBalance2(root->right);
        if(rightHeight==-1) return -1;

        if(abs(leftHeight-rightHeight)>1)   return -1;

        //returning height means it's balanced
        return 1+max(leftHeight,rightHeight);
    }
};

int main(){
    Node obj;
    Node *root;
    root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    //root->left->left->left=new Node(5);

    if(obj.isBalance2(root)==-1)
        cout<<"The tree is: Not Balanced";
    else
        cout<<"The tree is: Balanced";
}