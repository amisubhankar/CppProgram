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

    void printKDist(Node *root,int k){
        if(root==NULL)  return;

        if(k==0){
            cout<<root->data<<" ";
            return;
        }
        printKDist(root->left,k-1);
        printKDist(root->right,k-1);
    }

    int findNodeAtKDist(Node *root,Node *node,int k){
        if(root==NULL)  return 0;

        if(root==node){
            //print from root to K dist
            printKDist(root,k);
            return 1;
        }

        int L=findNodeAtKDist(root->left,node,k);
        //if L give some value then node present in root->L
        //so call the root->right as calling root->right we subtract 1 
        if(L!=0){
            //if L is giving a value equals to k then print the root 
            if(L==k)
                cout<<root->data<<" ";
            else
                printKDist(root->right,k-L-1);
            
            return L+1;
        }
        //if L give some value then node present in root->R
        //so call the root->left as calling root->left we subtract 1 
        int R=findNodeAtKDist(root->right,node,k);
        if(R!=0){
            if(R==k)
                cout<<root->data<<" ";
            else
                printKDist(root->left,k-R-1);

            return R+1;
        }
        
        //means L==0 and R==0 so  ret 0
        return 0;
    }
};

int main(){
    Node obj;
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(23);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->left->left=new Node(9);
    root->left->right->right=new Node(7);
    root->left->right->left=new Node(6);
    root->left->right->left->left=new Node(12);
    root->left->right->left->left->right=new Node(19);
    root->left->right->right->right=new Node(10);
    root->left->right->right->right->right=new Node(11);
    root->right->right=new Node(32);

    obj.findNodeAtKDist(root,root->left->right->left,1);
}