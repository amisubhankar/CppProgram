#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *left,*right;

    public:
    Node(){}
    Node(int item){
        data=item;
        next=right=left=NULL;
    }
    void inorder(Node *root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

    Node* findMirror(Node *root){
        if(root==NULL)  return root;
        Node *node=new Node(root->data);
        node->right=findMirror(root->left);
        node->left=findMirror(root->right);
        return node;
    }
};
int main(){
    Node obj;
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7);  

    obj.inorder(root);
    cout<<endl;
    root=obj.findMirror(root);
    obj.inorder(root);
}