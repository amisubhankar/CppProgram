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
    Node* findNext(Node *root){
        if(root==NULL)  return root;
        if(root->left!=NULL)
            return root->left;
        if(root->right!=NULL)
            return root->right;
        findNext(root->next);
    }
    void connectNode(Node *root){
        if(root==NULL || (root->left==NULL && root->right==NULL) )  
            return ;
        
        if(root->left!=NULL && root->right!=NULL){
            root->left->next=root->right;
            if(root->next!=NULL){
                root->right->next=findNext(root->next);
            }
        }
        else if(root->left!=NULL){
            root->left->next=findNext(root->next);
        }
        else{
            root->right->next=findNext(root->next);
        }

        connectNode(root->right);
        connectNode(root->left);
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

    obj.connectNode(root);
    cout<<root->left->left->left->next->data<<endl;
    cout<<root->right->left->next->data<<endl;
}