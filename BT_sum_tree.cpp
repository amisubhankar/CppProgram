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
    int convertSumTree(Node *root){
        if(root==NULL)  return 0;
        if(root->left==NULL && root->right==NULL){
            int temp=root->data;
            root->data=0;
            return temp;
        }
        int L=convertSumTree(root->left);
        int R=convertSumTree(root->right);
        int temp=root->data;
        root->data=L+R;
        return root->data+temp;
    }

    void inorder(Node *root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }
};

int main(){
    Node obj;
    Node *root=new Node(10);
    root->left=new Node(-2);
    root->right=new Node(6);
    root->left->left=new Node(8);
    root->left->right=new Node(-4);
    root->right->left=new Node(7);
    root->right->right=new Node(5);

    obj.convertSumTree(root);
    obj.inorder(root);
}