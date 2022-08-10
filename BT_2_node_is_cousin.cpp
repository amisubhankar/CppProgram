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

    int findLevel(Node *root,Node *node,int level){
        if(root==NULL)  return -1;
        if(root->data==node->data){
            return level;
        }
        int l=findLevel(root->left,node,level+1);
        if(l!=-1)   return l;
        return findLevel(root->right,node,level+1);

        // l=findLevel(root->right,node,level+1);
        // if(l!=-1)   return l;
        // return -1;
    }

    Node* findParent(Node *root,Node *item,Node *prev){
        if(root==NULL)  return NULL;
        if(root==item)  return prev;
        prev=root;
        Node *curr=findParent(root->left,item,prev);
        if(curr!=NULL)  return curr;
        return findParent(root->right,item,prev);
    }

    bool sameParent(Node *root,Node *node1,Node *node2){
        if(root==NULL)  return false;

        return ( ( root->left==node1 && root->right==node2 ) || ( root->left==node2 && root->right==node2 ) ||
                  sameParent(root->left,node1,node2) || sameParent(root->right,node1,node2) );
    }

    bool isCousin(Node *root,Node *node1,Node *node2){
        return ( ( findLevel(root,node1,0) == findLevel(root,node2,0) ) && !sameParent(root,node1,node2) );
    }
};

int main(){
    Node obj;
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->right = new Node(15); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->right->left->right = new Node(8); 
  
    Node *Node1, *Node2; 
    Node1 = root->left->left; 
    Node2 = root->left->right; 

    cout<<obj.isCousin(root,Node1,Node2);
}