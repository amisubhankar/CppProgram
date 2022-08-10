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
    int findDist(Node *root,Node *node){
        if(root==NULL)  return 0;
        if(root==node) return 1;

        int L=findDist(root->left,node);
        int R=findDist(root->right,node);
        
        if(L==0 && R==0)    return 0;
        return L+R+1;
    }
};
int main(){
    Node obj;
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);  
    root->left->left->right = new Node(8);  
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    
    
    Node *node1=root->right;
    Node *node2=root->right->right;

    Node *LCA=obj.findLCA(root,node1,node2);
    cout<<"LCA = "<<LCA->data<<endl;
    int leftDist=obj.findDist(LCA,node1);
    int rightDist=obj.findDist(LCA,node2);
    //-2 because total no. of nodes= leftDist+rightDist-1
    //so no. of edges = nodes-1
    cout<<"Distance = "<<leftDist+rightDist-2;

}