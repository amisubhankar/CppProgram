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
    Node* findNextRight(Node *root,int data,int &desiredLevel,int level){
        if(root==NULL)  return NULL;

        if(root->data==data){
            desiredLevel=level;
            return NULL;
        }
        if(desiredLevel==level)
            return root;
        
        Node *L=findNextRight(root->left,data,desiredLevel,level+1);
        if(L!=NULL)
            return L;
        return findNextRight(root->right,data,desiredLevel,level+1);
    }
};
int main(){
    Node obj;
    Node *root=new Node(6);
    root->left=new Node(4);
    root->right=new Node(10);
    root->left->left=new Node(12);
    root->left->left->left=new Node(9);
    root->right->left=new Node(8);
    root->right->right=new Node(12);
    root->right->right->right=new Node(14);

    int desiredLevel=-1;
    cout<<"Next node = "<<obj.findNextRight(root,root->data,desiredLevel,0);
    //cout<<desiredLevel;
}