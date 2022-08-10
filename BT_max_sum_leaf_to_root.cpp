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

    int findMaxLeafToNode(Node *root){
        if(root==NULL)  return 0;

        int L=findMaxLeafToNode(root->left);
        int R=findMaxLeafToNode(root->right);
        if(L>R){
            return L+root->data;
        }
        else{
            return R+root->data;
        }
    }
};

int main(){
    Node obj;
    // Node *root=new Node(1);
    // root->left=new Node(2);
    // root->right=new Node(3);
    // root->left->left=new Node(4);
    // root->left->right=new Node(5);
    // root->left->right->left=new Node(6);
    // root->right->right=new Node(7);
    // root->right->right->left=new Node(8);

    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(1);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(7);

    cout<<"MAX SUM = "<<obj.findMaxLeafToNode(root);
}