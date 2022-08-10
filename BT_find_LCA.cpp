//find out the lowest root whose left and right contain 2 nodes
//that root is lowest common ancestor
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
    Node* findLCA(Node *root,Node *node1,Node *node2){
        if(root==NULL || root==node1 || root==node2)
            return root;
        
        Node *left=findLCA(root->left,node1,node2);
        Node *right=findLCA(root->right,node1,node2);

        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        else{
            //this current root is our LCA
            return root;
        }
    }
};
int main(){
    Node obj;
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);  
    root->left->right->left = new Node(8);  
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    
    //node 2 && node 8 LCA=2
    Node *node1=root->left->right->left;
    Node *node2=root->left;

    cout<<"LCA = "<<obj.findLCA(root,node1,node2)->data;
}