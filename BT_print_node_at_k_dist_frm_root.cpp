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
    //this modified PreOrder traversal
    void findNodeAtKDistance(Node *root,int k){
        if(root==NULL) return;

        if(k==0){
            cout<<root->data<<" ";
            return;
        }
        findNodeAtKDistance(root->left,k-1);
        findNodeAtKDistance(root->right,k-1);
    }
};
int main(){
    Node obj;
    Node *root = new Node(10);  
    root->left = new Node(12);  
    root->right = new Node(3);  
    root->left->right = new Node(4);  
    root->right->left = new Node(5);  
    root->right->left->right = new Node(6);  
      
    obj.findNodeAtKDistance(root, 2);  
    return 0;  
}