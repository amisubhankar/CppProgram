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
        right=left=NULL;
    }

    bool isBST(Node *root,int min,int max){
        if(root!=NULL){
            return ( isBST(root->left,min,root->data) && 
                     isBST(root->right,root->data,max) &&
                     root->data>min && root->data<max);
        }
        //when root==null return true;
        else
            return true;
    }
};
int main(){
    Node obj;
    Node *root=new Node(12);
    root->left=new Node(4);
    root->right=new Node(25);
    root->left->left=new Node(2);
    root->left->right=new Node(9);
    root->right->left=new Node(16);
    root->right->right=new Node(32);

    cout<<obj.isBST(root,INT8_MIN,INT8_MAX);
}